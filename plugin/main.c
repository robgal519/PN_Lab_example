#include <dlfcn.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

const char *prefix = "plugin";
const char *suffix = ".so";

#define ARRSIZE 17
#define SHARED_OBJECT 0x03
typedef unsigned char byte;

int checkIfContains(const char *stringToTest, const char *prefix, const char *suffix) {
    return
            !strncmp(stringToTest, prefix, strlen(prefix)) &&
            !strncmp(stringToTest + strlen(stringToTest) - strlen(suffix), suffix, strlen(suffix));
}

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

void *getLibHandler(const char *filename) {
//    char pluginPath[128] = {'\0'};
//    sprintf(pluginPath, "./%s", filename);
//    return dlopen(pluginPath, RTLD_NOW);
    return NULL;
}

int main(int argc, const char *argv[]) {
    char message1[] = "Vkly|k~y|sk*ZX*}k*mkvusow*pktxo"; // 10
    char message2[] = "Q\"kng\"ukg\"mqowu\"ejeg\"tq|ykc|{yce\"|cfcpkc"; // 2
    char message3[] = "Niwpm$hsxevpiw$e~$xyxen$xs$kvexypyni$weqs~etevgme$>-$>T"; // 4

    char *messages[] = {message1, message2, message3};

    const char *requiredFunctionNames[] = {"firstDecoder", "secondDecoder", "thirdDecoder"};

    DIR *dir;
    dir = opendir(".");
    if (!dir) return -1;

    const char *currentFilename;
//    void *handler;
//    void (*funPtr)(char *);
    for (struct dirent *entity = readdir(dir); entity; entity = readdir(dir)) {
        currentFilename = entity->d_name;
        if (checkIfPlugin(currentFilename, prefix, suffix)) {
            void *libHandler = getLibHandler(currentFilename);
            const char *error = dlerror();
            if (error)
                puts(error);
            else {
                printf("%s plugin found!\n", currentFilename);
                puts("..function searching..");
                for (int i = 0; i < (sizeof(requiredFunctionNames) / sizeof(const char *)); i++) {
//                    funPtr = (void (*)(char *)) dlsym(libHandler, requiredFunctionNames[i]);
//                    if (funPtr) {
//                        printf("%s function found! Applying it on message%d.\n", requiredFunctionNames[i], i);
//                        funPtr(messages[i]);
//                    }
//                    else
//                        printf("%s not found, continuing.\n", requiredFunctionNames[i]);
                }
                putchar('\n');
                dlclose(libHandler);
            }
        }
    }

    puts("Messages after decoding:");
    for (int i = 0; i<(sizeof(messages) / sizeof(const char *)); i++){
        printf("Message %d: %s\n", i, messages[i]);
    }
}