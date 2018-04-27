#!/bin/sh -x

gcc -w -c add2num.c

gcc -w -c dostuff.c

gcc -w -c notusedfunction.c

gcc -w -c anotherfunction.c

gcc -w -c staticlibraryusage.c

ar rcs liba.a add2num.o dostuff.o notusedfunction.o

ar rcs libb.a anotherfunction.o

gcc -L . staticlibraryusage.o -o staticlibraryusage.out -la -lb

gcc -L . staticlibraryusage.o -o staticlibraryusage.out -lb -la
