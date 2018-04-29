#include <stdio.h>
void * externFunctionWhichPresumablyDoesntExist(int); /* niejawnie extern */

int imGloballyAvailableFunction(int a){
  return a + 1;
}

static int imLocallyAvailableFunction(int a){
  return a + 2;
}

int main(){
  printf("Adres funkcji main: %p\n", main);
  externFunctionWhichPresumablyDoesntExist(23);
  return 32;
}
