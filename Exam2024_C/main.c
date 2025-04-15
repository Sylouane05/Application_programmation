#include "fonction.h"

int main() {
    int nb = 0;
    int capacite = 10;
    UsagerPtr *U = malloc(capacite * sizeof(*U));  
    if (U == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire pour U\n");
        return EXIT_FAILURE;
    }

   printf("Bienvenue dans le programme de calcul de l'empreinte carbone\n");
    while (1) {
        int choix;
        printf("0. Quitter et enregistrer\n");
        printf("1. Creer le fichier\n");
        printf("2. Saisir un usager\n");
        printf("3. Modifier un usager\n");
        printf("4. Supprimer un usager\n");
        printf("5. Afficher les usagers\n");
        printf("6. Calculer l'empreinte carbone de tous les usagers\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        system("cls");
        switch (choix) {
            case 0:
                enregistrer_file(U, &nb);
                vider(&U, &nb);
                free(U);
                return 0;
            case 1:
                creer_file();
                break;
            case 2:
                saisie_usager(&U, &capacite, &nb);
                break;
            case 3:
                modifier_usager(&U,  &nb);
                break;
            case 4:
                supprimer_usager(&U, &nb);
                break;
            case 5:
                afficher_usager(U, &nb);
                break;
            case 6:
                cal_carb(U, &nb);
                break;
            default:
                printf("Choix invalide\n");
                break;
        }
    }

    return 0;
}
