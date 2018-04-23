//
// Created by Robert on 21.04.18.
//

#ifndef PN_LAB_EXAMPLE_ARGPARSESETUP_H
#define PN_LAB_EXAMPLE_ARGPARSESETUP_H
#include <argp.h>

struct argumentConfig{
    char quiet :1;
    char verbose :1;
};

struct argumentConfig parseArguments(int argc, char** argv);

#endif //PN_LAB_EXAMPLE_ARGPARSESETUP_H
