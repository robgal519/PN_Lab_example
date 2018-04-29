#define _GNU_SOURCE
#include <dlfcn.h>
void anotherfunction(){
  puts("Uwaga! Funkcja anotherfunction została wywołana!");
  static void (*oldanotherfunction)() = 0;
  if(!oldanotherfunction){
    oldanotherfunction = dlsym(RTLD_NEXT, "anotherfunction");
    if(dlerror()){
      puts("Symbol nie został znaleziony");
      exit(-1);
    }
  }
  oldanotherfunction();
}
