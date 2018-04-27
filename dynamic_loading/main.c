#include <dlfcn.h>
#include <stdio.h>

int main(){

    puts("Program główny");

    void *  lib = dlopen("./libfoo.so",RTLD_NOW);

    if(!lib){
        puts("problem z załadowaniem biblioteki");
    }
    else {
        void (*hook)(void);
        hook=dlsym(lib,"exampleFoo");
        const char *libraryLoadingError = dlerror();
        if (libraryLoadingError){
            puts("Symbol nie znaleziony");
        }else{
            hook();
        }
    }
    dlclose(lib);
}