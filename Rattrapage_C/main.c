#include "fonction.h"


int main(){
    int nb = 0;
    int capacite = 10;
    ActionPtr *A = malloc(capacite * sizeof(*A));
    if(A == NULL){
        fprintf(stderr, "Erreur d allocation memoire pour A\n");
        return EXIT_FAILURE;
    }
    char nom_fichier[256] = "actions.txt";
    FILE *f;
    f = fopen(nom_fichier, "w");
    if(f == NULL){
        fprintf(stderr, "Probleme d ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    fclose(f);
    while(1){
        int choix;
        printf("0. Quitter et enregistrer\n");
        printf("1. Enregistrer une action\n");
        printf("2. Afficher le score total d un eleve\n");
        printf("3. Afficher le score total d un objectif\n");
        printf("4. Afficher le score total de tous les objectifs\n");
        printf("5. Modifier une action\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch(choix){
            case 0:
                Enregistrer_Fichier(nom_fichier, A, &nb);
                vider(&A, &nb);
                free(A);
                return 0;
            case 1:
                EnregistrerAction(&A, &capacite, &nb);
                break;
            case 2:
                Afficher_score_eleve(A, &nb);
                break;
            case 3:
                Afficher_score_objectif(A, &nb);
                break;
            case 4:
                Afficher_score_ToutObjectif(A, &nb);
                break;
            case 5:
                ModifierAction(&A, &nb);
                break;
            default:
                printf("Choix invalide\n");
                break;
        }
    }
}