#include "PluginManager/PluginLoader.h"
#include "PluginManager/PluginManager.h"
#include <stdio.h>

char message[] = "Vkly|k~y|sk*ZX*}k*mkvusow*pktxo";
char PluginDirectory[] = "plugin/";
const char *PluginAPI[] = {"decodeMessage", "upperCaseMessage"};
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(*(x)))

int main(int argc, char **argv) {
    PluginManager *manager = PluginManager_new();
    puts("Wiadomosc poczatkowa");
    puts(message);
    fillPlugins(manager, PluginDirectory);
    for (int i = 0; i < ARRAY_SIZE(PluginAPI); i++) {
        bool_t result = apply_hook(manager, PluginAPI[i], (INOUT_data *) message);
        if (result) {
            puts(PluginAPI[i]);
            puts(message);
        }
    }

    PluginManager_free(manager);

}
