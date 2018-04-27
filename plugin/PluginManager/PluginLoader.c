//
// Created by robert on 26.04.18.
//

#include "PluginLoader.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

static bool_t checkIfPluginSignature(const char *name) {
    const char suffix[] = ".so";
    return !strncmp(name + strlen(name) - strlen(suffix), suffix, strlen(suffix));

}

static bool_t initPlugin(PluginManager *PM, const char *path, const char *name) {
    char pluginPath[128] = {'\0'};
    void (*_init_hook)(PluginManager *);
    void *handler;
    char functionName[128]={'\0'};
    char functionName1[128];
    sprintf(pluginPath, "%s%s", path, name);
    handler = dlopen(pluginPath, RTLD_NOW);
    const char *error = dlerror();
    if (error) {
        puts(error);
        dlclose(handler);
        return FALSE;
    } else {
        strcpy(functionName,name);
        functionName[strlen(name) - strlen(".so")] = '\0';
        sprintf(functionName1, "init_%s", functionName);
        _init_hook = dlsym(handler, functionName1);
        _init_hook(PM);
        add_handler_to_PM(PM,handler);
    }
    return TRUE;

}

void fillPlugins(PluginManager *PM, char *path) {
    DIR *dir;
    dir = opendir(path);
    if (dir) {
        const char *currentFileName;
        for (struct dirent *entity = readdir(dir); entity; entity = readdir(dir)) {
            currentFileName = entity->d_name;
            if (checkIfPluginSignature(currentFileName)) {
                initPlugin(PM, path, currentFileName);
            }
        }
    }
}