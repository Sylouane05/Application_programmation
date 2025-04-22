#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"


int main(){
    
    while(1){
       int choix;
       menu();
       printf("Choisissez une option : ");
       scanf("%d", &choix); 
    }
    return 0;
}