#!/bin/sh -x

gcc -w -c add2num.c

gcc -w -c dostuff.c

gcc -w -c notusedfunction.c

gcc -w -c anotherfunction.c

# Stwórz bibliotekę o nazwie 'a' z plików add2num.o dostuff.o notusedfunction.o

# Stwórz bibliotekę o nazwie 'b' z plików anotherfunction.o

gcc -w -c staticlibraryusage.c

# Zlinkuj biblioteki a i b wobec staticlibraryusage.o
