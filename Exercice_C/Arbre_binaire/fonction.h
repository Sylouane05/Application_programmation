#ifndef __FONCTION__H__
#define __FONCTION__H__
#include <stdio.h>

typedef struct tnoeud { 
    char nomCommune[32]; 
    char nomMaire[32]; 
    char codePostal[6]; 
    char signature[4];/* "non" ne donne pas, "???" pas consulté, "oui" ok*/ 
    struct tnoeud* pFg; 
    struct tnoeud* pFd; 
    } TNOEUD;


    void menu();
    FILE * fOuvrirFichier(char  *nomfic);
    int fCreerEnregistrement(FILE * f);

#endif