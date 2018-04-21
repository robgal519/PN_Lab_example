#include "stdio.h"
#include "argParseSetup/argParseSetup.h"


int main(int argc, char** argv) {
    struct argumentConfig argumentCfg = parseArguments(argc,argv);

    if(argumentCfg.verbose){
        printf("ala ma kota");
    }

    return 0;
}