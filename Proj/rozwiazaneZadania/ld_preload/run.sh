#!/bin/sh -x
rm -f *.o *.so
export LD_LIBRARY_PATH=../shared_libs

gcc -fPIC -c second.c -o second.o
gcc -shared second.o -o libsecond.so

LD_PRELOAD="./libsecond.so" ./main.out
