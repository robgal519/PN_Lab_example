all: main.out

PluginManager/PluginManager.o: PluginManager/PluginManager.c PluginManager/PluginManager.h
	gcc -c PluginManager/PluginManager.c -o PluginManager/PluginManager.o


PluginManager/PluginLoader.o: PluginManager/PluginLoader.c PluginManager/PluginLoader.h
	gcc -c PluginManager/PluginLoader.c -o PluginManager/PluginLoader.o

main.o: main.c
	gcc -c main.c

main.out: PluginManager/PluginManager.o PluginManager/PluginLoader.o main.o plugin/decode.so plugin/upper.so
	gcc  main.o PluginManager/PluginManager.o PluginManager/PluginLoader.o -o main.out -ldl

plugin/decode.so: plugin/decode.c PluginManager/PluginManager.o
	gcc -shared -fpic -o plugin/decode.so plugin/decode.c PluginManager/PluginManager.o

plugin/upper.so: plugin/upper.c PluginManager/PluginManager.o
	gcc -shared -fpic -o plugin/upper.so plugin/upper.c PluginManager/PluginManager.o

clean:
	find . -name '*.so' -delete
	find . -name '*.o' -delete
	find . -name '*.out' -delete

.PHONY: clean all
