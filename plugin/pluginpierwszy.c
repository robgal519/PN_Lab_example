#include <string.h>

void firstDecoder(char *message){
    for(int i=0; i<strlen(message); i++)
        message[i] -= 10;
}
