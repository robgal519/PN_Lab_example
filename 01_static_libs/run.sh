#!/bin/sh -x
rm -f *.out *.o *.a *.so

gcc -c first.c -o first.o
gcc -c second.c -o second.o
ar rcs libhello.a first.o second.o

gcc -I. -c main.c -o main.o
gcc -L. main.o -lhello -o main.out
./main.out
