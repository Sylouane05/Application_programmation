#ifndef __FONCTION__H__
#define __FONCTION__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---Structure des actions---*/
typedef struct action{
    int id;
    char nom[256];
    int object;
    char libelle[256];
    int score;
}Action, *ActionPtr;


/*---Prototypes---*/
ActionPtr SaisirAction(int *nb);
void EnregistrerAction(ActionPtr **A, int *capacite, int *nb);
void Afficher_score_eleve(ActionPtr *A, int *nb);
void Afficher_score_objectif(ActionPtr *A, int *nb);
void ModifierAction(ActionPtr **A, int *nb);
void Enregistrer_Fichier(char *nom_fichier, ActionPtr *A, int *nb); // Dans la conception j'ai oublié les champs ActionPtr *A et int *nb pour cette fonction
void vider(ActionPtr **A, int *nb);
void Afficher_score_ToutObjectif(ActionPtr *A, int *nb);
/*---Prototypes---*/

#endif