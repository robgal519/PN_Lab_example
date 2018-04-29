#include <string.h>
#include "../PluginManager/PluginManager.h"

void decode(INOUT_data *data) {
  for (int i = 0; i < strlen(data); ++i) {
    data[i]-=10;
  }
}

void init_decode(PluginManager *PM) {
  register_new_hook(PM,(pluginHook)decode,"decodeMessage");
}

