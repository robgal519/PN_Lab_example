#include <ctype.h>
#include <string.h>
#include "../PluginManager/PluginManager.h"

void upperCase(INOUT_data *data){
  for(int i=0;i<strlen(data);i++){
    data[i]=toupper(data[i]);
  }
}

void init_upper(PluginManager *PM) {
  register_new_hook(PM,(pluginHook)upperCase,"upperCaseMessage");
}
