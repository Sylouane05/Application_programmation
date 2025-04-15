#include <stdio.h>
#include "Exam.h"
#include "Exam.c"

int main(void) {
    TabVolPtr tabVol = NULL;
    VolPtr vol = NULL;
    int nbreVol = 0;
    int capacite = 2;
    int choix;
    char numero[20];

    
    while(1){
    menu();
    printf("Veuillez choisir une option: ");
    scanf("%d", &choix);
    system("cls");
        switch(choix){
            case 0:
                viderTabvol(&tabVol, &nbreVol);
                printf("Au revoir\n");
                return 0;
            case 1:
                vol = saisirVol();
                if(vol != NULL){
                   printf("Vol saisi avec succes\n");
                }else{
                    printf("Erreur de saisie\n");
                }
                free(vol);
                break;
            case 2:
                tabVol = ajouterVol(tabVol, &nbreVol, &capacite);
                break;
            case 3:
                afficherVol(tabVol, nbreVol);
                break;
            case 4:
                printf("Saisir le numero du vol: ");
                scanf("%s", numero);
                rechercherVol(tabVol, nbreVol, numero);
                break;
            case 5:
                printf("Saisir le numero du vol: ");
                scanf("%s", numero);
                tabVol = modifierVol(tabVol, nbreVol, numero);
                break;
            case 6:
                enregistrerVol();
                break;
            case 7:
                enregistrerTabVol(tabVol, nbreVol);
                break;
            case 8:
                printf("Saisir le numero du vol: ");
                scanf("%s", numero);
                rechercherVolFichier(numero);
                break;
            case 9:
                nombrePassagerFichier();
                break;
            default:
                printf("Option invalide\n");
                break;
        }
                
    }

   

    return 0;
}
