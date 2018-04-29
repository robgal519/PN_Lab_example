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

echo -n $GREEN
echo -e "Plik $NAZWA_PLIKU.c:"
echo -n $DEFAULT
pygmentize -g $NAZWA_PLIKU.c
echo

exe gcc -c -w $NAZWA_PLIKU.c

exe file $NAZWA_PLIKU.o

exe nm $NAZWA_PLIKU.o

exe readelf --symbols $NAZWA_PLIKU.o
