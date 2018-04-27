//
// Created by robert on 26.04.18.
//

#ifndef PN_LAB_EXAMPLE_LINKEDLIST_H
#define PN_LAB_EXAMPLE_LINKEDLIST_H

#define RoleNameLength 50

typedef char INOUT_data;

typedef void (*pluginHook)(INOUT_data *);

typedef enum {
    FALSE, TRUE
} bool_t;


typedef struct plugin_hook_list_element {
    char role_name[RoleNameLength];
    pluginHook hook;
    struct plugin_hook_list_element *next;
} hook_element;

typedef struct PM_t {
    hook_element *head;
} PluginManager;

void register_new_hook(PluginManager *manager, pluginHook hook, const char *role);

bool_t apply_hook(PluginManager *manager, const char role[RoleNameLength], INOUT_data *Data);

PluginManager *PluginManager_new(void);

void PluginManager_free(PluginManager *manager);


#endif //PN_LAB_EXAMPLE_LINKEDLIST_H
