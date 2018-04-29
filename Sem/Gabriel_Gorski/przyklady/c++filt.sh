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

MAIN='plikcpp';

echo -n $GREEN
echo -e "Plik $MAIN.cpp:"
echo -n $YELLOW
pygmentize -g $MAIN.cpp
echo

exe gcc $MAIN.cpp -o $MAIN.out;

exe nm $MAIN.out

exe eval "nm $MAIN.out | c++filt"
