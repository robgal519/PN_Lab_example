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

NAZWA_PLIKU='relocatableFile'
NAZWA_PLIKU2='relocatableFile2'
OUTPUT='executableFile'

echo -n $GREEN
echo -e "Plik $NAZWA_PLIKU.c:"
echo -n $DEFAULT
pygmentize -g $NAZWA_PLIKU.c
echo

echo -n $GREEN
echo -e "Plik $NAZWA_PLIKU2.c:"
echo -n $DEFAULT
pygmentize -g $NAZWA_PLIKU2.c
echo

exe gcc -c $NAZWA_PLIKU.c;
exe gcc -c $NAZWA_PLIKU2.c;

exe file $NAZWA_PLIKU.o

exe file $NAZWA_PLIKU2.o

exe nm $NAZWA_PLIKU.o

exe nm $NAZWA_PLIKU2.o

exe gcc -no-pie $NAZWA_PLIKU.o $NAZWA_PLIKU2.o -o $OUTPUT.out;

exe file $OUTPUT.out

exe nm $OUTPUT.out
