#include <string.h>

void thirdDecoder(char *message){
    for(int i=0; i<strlen(message); i++)
        message[i] -= 4;
}
