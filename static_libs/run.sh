#!/bin/sh -x
rm -f *.out *.o *.a *.so

gcc -c first.c -o first.o
gcc -c second.c -o second.o
# Stwórz bibliotekę statyczną z powyższych plików obiektowych

# Skompilowanie pliku main.c
# Zlinkowanie pliku wykonywalnego (main.c + biblioteka)
./main.out
