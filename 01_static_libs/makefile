all: main library
	gcc -L. main.o -lhello -o main.out
	./main.out

main:
	gcc -I. -c main.c -o main.o

library: first second
	ar rcs libhello.a first.o second.o

first:
	gcc -c first.c -o first.o

second:
	gcc -c second.c -o second.o

clean:
	@rm -f *.out *.o *.a *.so

.PHONY: all clean
