all: main library
	gcc -L. main.o -lhello -o main.out
	LD_LIBRARY_PATH=. ./main.out
	@cp -f main.out ../03_overwriting_library/.


main:
	gcc -I. -c main.c -o main.o

library: first second
	gcc -shared first.o second.o -o libhello.so

first:
	gcc -fPIC -c first.c -o first.o

second:
	gcc -fPIC -c second.c -o second.o

clean:
	@rm -f *.out *.o *.a *.so

.PHONY: all clean
