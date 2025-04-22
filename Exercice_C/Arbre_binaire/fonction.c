#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"


/*-------------------------------------------------------*/
void menu() {
    
}
/*-------------------------------------------------------*/
FILE * fOuvrirFichier(char  *nomfic) {
    FILE *fichier = fopen(nomfic, "a+");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nomfic);
        exit(EXIT_FAILURE);
    }
    return fichier;
}
/*-------------------------------------------------------*/
