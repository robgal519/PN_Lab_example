#!/bin/sh -x
rm -f *.o *.so
gcc -fPIC -c second.c -o second.o
gcc -shared second.o -o libsecond.so

export LD_LIBRARY_PATH=../02_shared_libs
LD_PRELOAD="./libsecond.so" ./main.out

#rm -f *.o *.a *.so
