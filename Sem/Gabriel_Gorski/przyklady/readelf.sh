#!/usr/bin/env bash

source clean.sh

RED=$'\e[31m'
GREEN=$'\e[32m'
CYAN=$'\e[96m'
YELLOW=$'\e[33m'
DEFAULT=$'\e[39m'

gcc -c relocatableFile.c -o a.out

echo -n $GREEN
readelf -h a.out
echo -n $YELLOW
readelf -S a.out
echo -n $RED
readelf -l a.out
echo -n $CYAN
readelf -d a.out
echo -n $GREEN
readelf -r a.out
echo -n $YELLOW
readelf -s a.out
echo -n $DEFAULT
