#!/bin/sh -x
rm -f *.out *.o *.a *.so

gcc -fPIC -c first.c -o first.o
gcc -fPIC -c second.c -o second.o
gcc -shared first.o second.o -o libhello.so

gcc -I. -c main.c -o main.o
gcc -L. main.o -lhello -o main.out

LD_LIBRARY_PATH=. ./main.out


# Na potrzeby nastepnego zadania :)
cp -f main.out ../ld_preload/.
