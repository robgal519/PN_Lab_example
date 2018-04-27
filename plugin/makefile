PluginManager/PluginManager.o: PluginManager/PluginManager.c PluginManager/PluginManager.h


PluginManager/PluginLoader.o: PluginManager/PluginLoader.c PluginManager/PluginLoader.h

main.o: main.c
	gcc -c main.c

a.out: PluginManager/PluginManager.o PluginManager/PluginLoader.o main.o plugin/decode.so plugin/upper.so
	gcc  main.o PluginManager/PluginManager.o PluginManager/PluginLoader.o -ldl

plugin/decode.so: plugin/decode.c PluginManager/PluginManager.o
	gcc -shared -fpic -o plugin/decode.so plugin/decode.c PluginManager/PluginManager.o

plugin/upper.so: plugin/upper.c PluginManager/PluginManager.o
	gcc -shared -fpic -o plugin/upper.so plugin/upper.c PluginManager/PluginManager.o
