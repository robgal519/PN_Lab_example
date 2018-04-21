//
// Created by Robert on 21.04.18.
//

#include "argParseSetup.h"


const char* argp_program_version = "0.0.1";
const char* argp_program_bug_address = "https://github.com/robgal519/PN_Lab_example/issues";
static char doc[] = "This is example program and if you managed to compile it than you're very talented!\n"
                    "Now let's try to write some plugins for it :D";

static struct argp_option options[] ={
        {"verbose", 'v', 0,0,"Produce verbose output"},
        {"quiet", 'q',0,0, "Do not produce any output"},
        {"silent",   's', 0,      OPTION_ALIAS },
        {0}
};


static error_t parse_opt(int key, char * arg, struct argp_state * state){
    struct argumentConfig  *arguments = state->input;
    switch (key) {
        case 'q':
        case 's':
            arguments->quiet = 0b1;
            arguments->verbose = 0b0;
            break;
        case 'v':
            arguments->verbose = 0b1;
            arguments->quiet = 0b0;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = {options, parse_opt, 0, doc};

struct argumentConfig parseArguments(int argc, char** argv){
    struct argumentConfig arguments;
    arguments.quiet=0b0;
    arguments.verbose = 0b0;
    argp_parse(&argp, argc,argv,0,0,&arguments);
    return arguments;
}
