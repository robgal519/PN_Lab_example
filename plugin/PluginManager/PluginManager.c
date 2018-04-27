//
// Created by robert on 26.04.18.
//

#include "PluginManager.h"
#include <stdlib.h>
#include <string.h>

void register_new_hook(PluginManager *manager, pluginHook hook, const char *role) {

    hook_element *element = malloc(sizeof(*element));

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
    PluginManager *pluginManager = malloc(sizeof(*pluginManager));
    pluginManager->head = NULL;
}

void PluginManager_free(PluginManager *manager) {
    hook_element *element = manager->head;
    hook_element *next_element;

    while (element) {
        next_element=element->next;
        free(element);
        element = next_element;
    }
    manager->head = NULL;
    free(manager);
}

