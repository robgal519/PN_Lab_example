#include "stdio.h"
#include "argParseSetup/argParseSetup.h"
#include "logSetup/logSetup.h"


int main(int argc, char** argv) {
    struct argumentConfig argumentCfg = parseArguments(argc,argv);

    verbousePrint(argumentCfg,"Ala ma %d koty\n", 2);
    fprint(argumentCfg,stdout,"test");
    return 0;
}