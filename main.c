#include <dlfcn.h>
#include <dirent.h>
#include <stdio.h>
#include <elf.h>
#include <string.h>

#define ARRSIZE 17
#define SHARED_OBJECT 0x03
typedef unsigned char byte;

int checkIfPlugin(const char *filename, const char *prefix, const char *suffix) {
    FILE *file = fopen(filename, "rb");
    byte header[ARRSIZE];
    size_t bytesRead = fread(header, sizeof(*header), ARRSIZE, file);
    fclose(file);
    if (checkIfContains(filename, prefix, suffix) &&
        bytesRead == ARRSIZE &&
        header[0x00] == 0x7f &&
        header[0x01] == 'E' &&
        header[0x02] == 'L' &&
        header[0x03] == 'F' &&
        header[0x10] == SHARED_OBJECT) {
        return 1;
    }
}

int checkIfContains(const char *stringToTest, const char *prefix, const char *suffix) {
    return
            !strncmp(stringToTest, prefix, strlen(prefix)) &&
            !strncmp(stringToTest + strlen(stringToTest) - strlen(suffix), suffix, strlen(suffix));
}

int main(int argc, const char *argv[]) {
    const char *prefix = "plugin";
    const char *suffix = ".so";

    DIR *dir;
    dir = opendir(".");
    if (!dir) return -1;

    const char *currentFilename;
    void *handler;
    for (struct dirent *entity = readdir(dir); entity; entity = readdir(dir)) {
        currentFilename = entity->d_name;
        if(checkIfPlugin(currentFilename, prefix, suffix)){
            char pluginPath[128] = { '\0' };
            sprintf(pluginPath, "./%s", currentFilename);
            handler = dlopen(pluginPath, RTLD_NOW);
            const char *error = dlerror();
            if(error)
                puts(error);
            else{
                printf("%s plugin action:\n", currentFilename);
                char startingFunction[128] = { 0 };
                strncpy(startingFunction, currentFilename, strlen(currentFilename) - strlen(suffix));
                ((void (*)(void))dlsym(handler, startingFunction))();
                dlclose(handler);
            }


        }
    }

}