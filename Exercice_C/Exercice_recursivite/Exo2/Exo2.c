#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"


int main(){
    T_NOEUD *T = NULL;

    while(1){
        int choix;
        menu();
        printf("Choix : ");
        scanf("%d", &choix);
        system("cls"); // clear the console
        switch(choix){
            case 0:{
                liberer_liste(T);
                return 0;
            }
            case 1:{
                T_NOEUD *N = creer_noeud();
                T = inserer_noeud(T, N);
                break;
            }
            case 2:{
                afficher_liste(T);
                break;
            }
            case 3: {
                int num = numero(T);
                if (num == INT_MAX) {
                    printf("Aucune facture en regle trouvee.\n");
                    num = 0;
                } else {
                    printf("Le numero de la facture en regle la plus petite est : %d\n", num);
                }
                break;
            }
            case 4:{
                penalite(T);
                break;
            }
            case 5:{
                int num;
                printf("Entrez le numero de la facture a supprimer : ");
                scanf("%d", &num);
                T = supprimer_noeud(T, num);
                break;
            }
            default:{
                printf("Choix invalide.\n");
            }
        }
    }
    

    return 0;
}