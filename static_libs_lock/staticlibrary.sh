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
LIB2='libb'
MAIN='staticlibraryusage';

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
echo -e "Plik $MAIN.c:"
echo -n $DEFAULT
pygmentize -g $MAIN.c
echo

exe gcc -w -c $LIB1F1.c;
exe gcc -w -c $LIB1F2.c;
exe gcc -w -c $LIB1F3.c;
exe gcc -w -c $LIB2F1.c;
exe gcc -w -c $MAIN.c;

exe ar rcs $LIB1.a $LIB1F1.o $LIB1F2.o $LIB1F3.o;
exe ar rcs $LIB2.a $LIB2F1.o;

exe gcc -L . $MAIN.o -o $MAIN.out -la -lb;

exe gcc -L . $MAIN.o -o $MAIN.out -lb -la;

exe eval "nm $MAIN.out | grep -v \"_\""

