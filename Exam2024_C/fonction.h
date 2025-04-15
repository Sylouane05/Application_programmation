#ifndef __FONCTION__H__
#define __FONCTION__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*---Définition des constantes---*/

/*Coût carbone en gCO2/km*/
#define VELO_ELEC 110
#define BUS 80
#define VOITURE 2183
#define VEG 51
#define POISSON 1980
#define POULET 1580
#define BOEUF 7260
/*Coût carbone en gCO2/km*/

/*Nombre de jours passer à l'école*/
#define ETUD 150
#define ADMIN 210
/*Nombre de jours passer à l'école*/

/*---Définition des constantes---*/

/*---Définition des structures---*/

//structure des déplacements
typedef struct transport{
    float A_Pied;
    float Velo;
    float Velo_Elec;
    float Bus;
    float Voiture;
}Transport;

//structure des repas
typedef struct alimentation{
    float Veg;
    float Poisson;
    float Poulet;
    float Boeuf;
}Alimentation;

//structure usager
typedef struct usager{
    int id;
    char nom[20];
    char prenom[20];
    char type[20];
    float distance;
    float cout_carbone;
    struct transport *T;
    struct alimentation *A;
}Usager, *UsagerPtr;

/*---Définition des structures---*/

/*---Définition des prototypes---*/

float cal_dep(UsagerPtr U);
float cal_ali(UsagerPtr U);
UsagerPtr  creer_usager(int *nb);
void saisie_usager(UsagerPtr **U, int *capacite, int *nb);
void modifier_usager(UsagerPtr **U,  int *nb);
void supprimer_usager(UsagerPtr **U, int *nb);
void afficher_usager(UsagerPtr *U, int *nb);
void cal_carb(UsagerPtr *U, int *nb);
void creer_file();
void enregistrer_file(UsagerPtr *U, int *nb);
void vider(UsagerPtr **U, int *nb);

/*---Définition des prototypes---*/



#endif 