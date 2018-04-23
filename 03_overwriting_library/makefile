all: main library
	@LD_PRELOAD="libalthello.so" LD_LIBRARY_PATH=.:../02_shared_lib ./main.out

main:
	gcc -I. -c main.c -o main.o

library: first second
	gcc -shared first.o second.o -o libalthello.so

first:
	gcc -fPIC -c first.c -o first.o

second:
	gcc -fPIC -c second.c -o second.o

clean:
	@rm -f *.o *.a *.so

.PHONY: all clean
