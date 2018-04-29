#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE

int main()
{
	  void * lib = dlopen("./libfoo.so", RTLD_NOW);
	  //resolve all undefined symbols before dlopen() returns and fail if this cannot be done
	  void (*a)(void) = 0;
	  a = dlsym(lib,"foo");
	  if(dlerror()){
      puts("Symbol nie został znaleziony");
      exit(-1);
    	}
	  a();

	return 0;
}