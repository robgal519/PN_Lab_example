#!/usr/bin/env bash

source clean.sh

DEFAULT=$'\e[39m'
RED=$'\e[31m'
GREEN=$'\e[32m'
YELLOW=$'\e[33m'
GREY=$'\e[33m'
MAGENTA=$'\e[35m'

DEFAULTB=$'\e[49m'
REDB=$'\e[41m'
BLUEB=$'\e[44m'
MAGENTAB=$'\e[45m'

exe() {
    echo -e -n $GREEN
    echo "${@/eval/}"
    echo -e -n $DEFAULT
    "$@";
    echo;
}

F1='gccoutput';

echo -n $GREEN
echo -e "Plik $F1.c:"
echo -n $DEFAULT
pygmentize -g $F1.c
echo

exe gcc -v $F1.c;

read

CONTENT=$((gcc -v $F1.c) 2>&1)

echo -n $REDB
echo -e "Kompilacja do asemblera"
grep -e "/cc1" <<< "$CONTENT"
echo -n $DEFAULTB
echo
echo -n $BLUEB
echo -e "Asemblacja do pliku obiektowego"
grep -e "\<as -v\>" <<< "$CONTENT"
echo -n $DEFAULTB
echo -n $MAGENTAB
echo -e "Linkowanie"
LINKING=`grep -e "collect2\>" <<< "$CONTENT"`
echo "$LINKING"
echo -n $DEFAULTB

read
echo Opcje linkera rozdzielona na nowe linie:

IFS=' ' read -ra A <<< "$LINKING"
for i in "${A[@]}"
do
    echo "$i"
done
