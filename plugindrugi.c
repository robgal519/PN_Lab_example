#include <string.h>

void secondDecoder(char *message){
    for(int i=0; i<strlen(message); i++)
        message[i] -= 2;
}
