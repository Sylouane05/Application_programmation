#ifndef __EXAM__H__
#define __EXAM__H__

#define FILENAME "bvols.dat"
#define TAILLE 20

/*Définition d'un vol*/
typedef struct Vol{
    char numero[TAILLE];
    char depart[TAILLE];
    char destination[TAILLE];
    float nbreKm;
    int nbrePassager;
}Vol, *VolPtr;

/*Définition d'un tableau de vol*/
typedef struct TabVol{
    VolPtr vols;
}TabVol, *TabVolPtr;


/*Prototypes des fonctions*/
VolPtr saisirVol();
TabVolPtr ajouterVol(TabVolPtr tabVol, int *nbreVol, int *capacite);
void afficherVol(TabVolPtr tabVol, int nbreVol);
void rechercherVol(TabVolPtr tabVol,int nbreVol, char* numero);
TabVolPtr modifierVol(TabVolPtr tabVol,int nbreVol, char* numero);
void enregistrerVol();
void enregistrerTabVol(TabVolPtr tabVol, int nbreVol);
void rechercherVolFichier(char* numero);
void nombrePassagerFichier();
void menu();
void viderTabvol(TabVolPtr *tabVol, int *nbreVol);






#endif