#ifndef __FONCTION__H__
#define __FONCTION__H__

#define ANNEE 2024

typedef struct{
    int numero;
    char nom[20];
    float prix;
    int annee_limite;
} Facture;

typedef struct noeud{
    Facture info;
    struct noeud *suivant;
} T_NOEUD;


Facture saisir_facture();
void afficher_facture(Facture f);
T_NOEUD * creer_noeud(void);
T_NOEUD * inserer_noeud(T_NOEUD *T, T_NOEUD *N);
void afficher_noeud(T_NOEUD *N);
int afficher_liste(T_NOEUD *T);
int numero(T_NOEUD *T);
T_NOEUD * supprimer_noeud(T_NOEUD *T, int numero);
float penal(float prix, int nbre_annee);
void  penalite(T_NOEUD  *T);
void liberer_liste(T_NOEUD *T);
void menu();

#endif