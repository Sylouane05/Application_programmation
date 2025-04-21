#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

/*---------------------------------------------------*/
Facture saisir_facture(){
    Facture f;
    int resultat;
    do{
        printf("Numero de la facture : ");
        resultat = scanf("%d", &f.numero);
        if(resultat != 1){
            printf("Erreur : le numero de la facture doit etre un entier\n");
            while(getchar() != '\n'); // vider le tampon d'entree
        }
        else if(f.numero <= 0){
            printf("Erreur : le numero de la facture doit etre positif\n");
        }
    }while (f.numero <= 0 || resultat != 1);

    do{
        printf("Nom du client : ");
        resultat = scanf("%s", f.nom);
        if(resultat != 1){
            printf("Erreur : le nom de la facture doit etre une chaine de caracteres\n");
            while(getchar() != '\n'); // vider le tampon d'entree
        }
    }while (resultat != 1);

    do{
        printf("Prix de la facture : ");
        resultat = scanf("%f", &f.prix);
        if(resultat != 1){
            printf("Erreur : le prix de la facture doit etre un reel\n");
            while(getchar() != '\n'); // vider le tampon d'entree
        }
        else if(f.prix < 0){
            printf("Erreur : le prix de la facture doit etre positif\n");
        }
    }while (f.prix < 0 || resultat != 1);

    do{
        printf("Annee limite de la facture : ");
        resultat = scanf("%d", &f.annee_limite);
        if(resultat != 1){
            printf("Erreur : l'annee limite de la facture doit etre un entier\n");
            while(getchar() != '\n'); // vider le tampon d'entree
        }
        else if(f.annee_limite < 2000 || f.annee_limite > 2100){
            printf("Erreur : l'annee limite de la facture doit etre comprise entre 2000 et 2100\n");
        }
    }while (f.annee_limite < 2000 || f.annee_limite > 2100 || resultat != 1);

    printf("Facture saisie avec succes !\n");

   return f;  
}
/*---------------------------------------------------*/
void afficher_facture(Facture f){
   printf("[Numero : %d, Nom : %s, Prix : %.2f, Annee limite : %d]\n", f.numero, f.nom, f.prix, f.annee_limite);
}
/*---------------------------------------------------*/
T_NOEUD * creer_noeud(void){
    T_NOEUD * nouveau = malloc(sizeof(*nouveau));
    if(nouveau == NULL){
        printf("Erreur d'allocation memoire\n");
        exit(EXIT_FAILURE);
    }
    nouveau->info = saisir_facture();
    nouveau->suivant = NULL;
    return nouveau;
}
/*---------------------------------------------------*/
T_NOEUD * inserer_noeud(T_NOEUD *T, T_NOEUD *N){
    if(T == NULL){
        return N;
    }
    else if(N ->info.numero < T->info.numero){
        N->suivant = T;
        return N;
    }
    else if(N->info.numero == T->info.numero){
        printf("Erreur : le numero de la facture existe deja\n");
        free(N);
        return T;
    }
    else{
        T->suivant = inserer_noeud(T->suivant, N);
        return T;
    }
}
/*---------------------------------------------------*/
void afficher_noeud(T_NOEUD *N){
    if(N == NULL){
        printf("Erreur : le noeud est vide\n");
    }
    else{
        afficher_facture(N->info);
    }
}
/*---------------------------------------------------*/
int afficher_liste(T_NOEUD *T){
    if(T == NULL){
        return 0;
    }
    else{
        afficher_noeud(T);
        return 1 + afficher_liste(T->suivant);
    }
}
/*---------------------------------------------------*/
int numero(T_NOEUD *T) {
    if (T == NULL) {
        return INT_MAX; 
    }

    int min_suiv = numero(T->suivant); 

    // Si facture en règle, comparer
    if (T->info.annee_limite >= ANNEE) {
        int min_local = T->info.numero;
        return (min_local < min_suiv) ? min_local : min_suiv;
    } else {
        return min_suiv; 
    }
}
/*---------------------------------------------------*/
T_NOEUD * supprimer_noeud(T_NOEUD *T, int numero){
    if (T == NULL) {
        printf("Cette facture n'existe pas !\n");
        return NULL;
    }

    if (T->info.numero == numero) {
        T_NOEUD *temp = T->suivant;
        free(T);
        printf("Facture %d supprime avec succes.\n", numero);
        return temp; // nouvelle tête
    }

    T->suivant = supprimer_noeud(T->suivant, numero);
    return T;
    
}
/*---------------------------------------------------*/
float penal(float prix, int nbre_annee){
    float nouveau_prix = prix;
    for(int i = 0; i < nbre_annee; i++){
        nouveau_prix *= 1.1; // 10% de penalite par annee
    }
    return nouveau_prix;
}
/*---------------------------------------------------*/
void penalite(T_NOEUD *T) {
    printf("Factures avant penalite :\n");
    afficher_liste(T); 

    printf("Factures apres penalite :\n");
    T_NOEUD *tmp = T;

    while (tmp != NULL) {
        Facture copie = tmp->info; 

        if (ANNEE - copie.annee_limite > 0) {
            copie.prix = penal(copie.prix, ANNEE - copie.annee_limite); 
        }

        afficher_facture(copie); 
        tmp = tmp->suivant;
    }
}
/*---------------------------------------------------*/
void liberer_liste(T_NOEUD *T){
    if(T != NULL){
        liberer_liste(T->suivant);
        free(T);
    }
}
/*---------------------------------------------------*/
void menu(){
    printf("0. Quitter\n");
    printf("1. Ajouter une facture\n");
    printf("2. Afficher la liste des factures\n");
    printf("3. Afficher la premiere facture en regle\n");
    printf("4. Afficher la penalite\n");
    printf("5. Supprimer une facture\n");
}