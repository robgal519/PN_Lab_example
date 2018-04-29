#!/usr/bin/env bash

source clean.sh

RED=$'\e[31m'
GREEN=$'\e[32m'
YELLOW=$'\e[33m'
DEFAULT=$'\e[39m'

exe() {
    echo -e -n $GREEN
    echo "${@/eval/}"
    echo -e -n $YELLOW
    "$@";
    echo;
}

LIB1F1='add2num';
LIB1F2='dostuff';
LIB1F3='notusedfunction'
LIB1='liba'
LIB2F1='anotherfunction';
LIB2F1Alt='wrapperanotherfunction'
LIB2='libb'
LIB2Alt='libbalt'
MAIN='sharedlibraryusage';

echo -n $GREEN
echo -e "Plik $LIB1F1.c:"
echo -n $DEFAULT
pygmentize -g $LIB1F1.c
echo

echo -n $GREEN
echo -e "Plik $LIB1F2.c:"
echo -n $DEFAULT
pygmentize -g $LIB1F2.c
echo

echo -n $GREEN
echo -e "Plik $LIB1F3.c:"
echo -n $DEFAULT
pygmentize -g $LIB1F3.c
echo

echo -n $GREEN
echo -e "Plik $LIB2F1.c:"
echo -n $DEFAULT
pygmentize -g $LIB2F1.c
echo

echo -n $GREEN
echo -e "Plik $LIB2F1Alt.c:"
echo -n $DEFAULT
pygmentize -g $LIB2F1Alt.c
echo

echo -n $GREEN
echo -e "Plik $MAIN.c:"
echo -n $DEFAULT
pygmentize -g $MAIN.c
echo

exe gcc -w -c -fPIC $LIB1F1.c;
exe gcc -w -c -fPIC $LIB1F2.c;
exe gcc -w -c -fPIC $LIB1F3.c;
exe gcc -w -c -fPIC $LIB2F1.c;
exe gcc -w -c $MAIN.c;

exe gcc -shared $LIB1F1.o $LIB1F2.o $LIB1F3.o -o $LIB1.so;
exe gcc -shared $LIB2F1.o -o $LIB2.so;

exe gcc -L . $1 $MAIN.o -o $MAIN.out -la -lb;

exe export LD_LIBRARY_PATH='.'
exe ldd $MAIN.out
exe ./$MAIN.out

exe gcc -w -c -fPIC $LIB2F1Alt.c;
exe gcc -shared $LIB2F1Alt.o -o $LIB2Alt.so -ldl;

exe eval "LD_PRELOAD=./$LIB2Alt.so ldd $MAIN.out"
exe eval "LD_PRELOAD=./$LIB2Alt.so ./$MAIN.out"
