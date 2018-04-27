//
// Created by robert on 26.04.18.
//

#include "PluginManager.h"
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>


void register_new_hook(PluginManager *manager, pluginHook hook, const char *role) {

    hook_element *element = (hook_element *) malloc(sizeof(*element));

    element->next = manager->head;
    strcpy(element->role_name, role);
    element->hook = hook;
    manager->head = element;
}

bool_t apply_hook(PluginManager *manager, const char role[RoleNameLength], INOUT_data *Data) {
    hook_element *element = manager->head;
    while (element) {
        if (strcmp(role, element->role_name) == 0) {
            //desired element found, apply function from plugin
            element->hook(Data);

            return TRUE;
        } else {
            //check next element, last will be always NULL, so while loop is not infinite
            element = element->next;
        }
    }
    return FALSE;
}

PluginManager *PluginManager_new(void) {
    PluginManager *pluginManager = (PluginManager *) malloc(sizeof(*pluginManager));
    pluginManager->head = NULL;
    pluginManager->handleHead = NULL;
}

void PluginManager_free(PluginManager *manager) {
    hook_element *element = manager->head;
    hook_element *next_element;

    while (element) {
        next_element = element->next;
        free(element);
        element = next_element;
    }
    manager->head = NULL;

    plugin_handler *curHandle = manager->handleHead;
    plugin_handler *nextHandle;
    while (curHandle) {
        nextHandle = curHandle->next;
        if (curHandle->pluginHandler)
            dlclose(curHandle->pluginHandler);
        free(curHandle);
        curHandle = nextHandle;
    }
    manager->handleHead = NULL;

    free(manager);
}

void add_handler_to_PM(PluginManager *PM, void *handler) {
    plugin_handler *element = (plugin_handler *) malloc(sizeof(plugin_handler));
    element->next = handler;
    element->next = PM->handleHead;
    PM->handleHead = element;
}

