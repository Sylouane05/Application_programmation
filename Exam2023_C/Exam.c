#include <stdio.h>
#include "Exam.h"
#include <stdlib.h>
#include <string.h>
/*----------------------------------------*/
VolPtr saisirVol() {
    Vol *vol = malloc(sizeof(*vol));
    if (vol == NULL) {
        fprintf(stderr, "Erreur d'allocation de memoire\n");
        exit(EXIT_FAILURE);
    }
    printf("Saisir le numero du vol: ");
    scanf("%s", vol->numero);
    printf("Saisir le depart du vol: ");
    scanf("%s", vol->depart);
    printf("Saisir la destination du vol: ");
    scanf("%s", vol->destination);
    printf("Saisir le nombre de km: ");
    scanf("%f", &vol->nbreKm);
    printf("Saisir le nombre de passager: ");
    scanf("%d", &vol->nbrePassager);
    return vol;
}
/*----------------------------------------*/
TabVolPtr ajouterVol(TabVolPtr tabVol, int *nbreVol, int *capacite) {
    if (*nbreVol == 0) {
        tabVol = malloc(*capacite * sizeof(*tabVol));
        if (tabVol == NULL) {
            fprintf(stderr, "Erreur d'allocation de memoire\n");
            exit(EXIT_FAILURE);
        }
    } else if (*nbreVol >= *capacite) {
        *capacite *= 2;
        TabVol *temp = realloc(tabVol, *capacite * sizeof(*tabVol));
        if (temp == NULL) {
            fprintf(stderr, "Erreur de réallocation mémoire\n");
            free(tabVol);
            exit(EXIT_FAILURE);
        }
        tabVol = temp;
    }

    tabVol[*nbreVol].vols = saisirVol();
    (*nbreVol)++;
    printf("Le vol a ete ajoute\n");
    return tabVol;
}
/*----------------------------------------*/
void afficherVol(TabVolPtr tabVol, int nbreVol) {
    if (tabVol == NULL) {
        printf("Aucun vol n'est enregistre\n");
        return;
    }
    for (int i = 0; i < nbreVol; i++) {
        printf("%s %s-%s %.2fKm %d passagers\n",
               tabVol[i].vols->numero, tabVol[i].vols->depart,
               tabVol[i].vols->destination, tabVol[i].vols->nbreKm,
               tabVol[i].vols->nbrePassager);
    }
}
/*----------------------------------------*/
void rechercherVol(TabVolPtr tabVol,int nbreVol, char* numero){
             int i;
            for( i = 0; i < nbreVol; i++){
                if(strcmp(tabVol[i].vols->numero, numero) == 0){
                    printf("vol trouve\n");
                    printf("%s %s-%s %.2fKm %d passagers\n",
                           tabVol[i].vols->numero, tabVol[i].vols->depart,
                           tabVol[i].vols->destination, tabVol[i].vols->nbreKm,
                           tabVol[i].vols->nbrePassager);
                    return;
                }
                
            }
            if(i == nbreVol){
                printf("Le vol %s n'existe pas\n", numero);
            }
}
/*----------------------------------------*/
TabVolPtr modifierVol(TabVolPtr tabVol,int nbreVol, char* numero){
     int i;
    for( i = 0; i < nbreVol; i++){
        if(strcmp(tabVol[i].vols->numero, numero) == 0){
            tabVol[i].vols->nbrePassager = 0;
            printf("le vol %s a ete annulee\n", numero);
            break;
        }
    }
    if(i == nbreVol){
        printf("Le vol %s n'existe pas\n", numero);
    }
    return tabVol;
}
/*----------------------------------------*/
void enregistrerVol(){
    Vol *vol = NULL;
    vol = saisirVol();

    // Vérifier si le numéro de vol existe déjà dans le fichier
    char ligne[256];
    char num[20];
    char depart[50];
    char destination[50];
    float nbreKm;
    int nbrePassager;
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier != NULL) {
        while (fgets(ligne, 256, fichier) != NULL) {
            sscanf(ligne, "%s %s %s %f %d\n", num, depart, destination, &nbreKm, &nbrePassager);
            if (strcmp(num, vol->numero) == 0) {
                printf("Le vol avec le numero %s existe deja.\n", vol->numero);
                fclose(fichier);
                free(vol);
                return;
            }
        }
        fclose(fichier);
    }

    fichier = fopen(FILENAME, "a+");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fichier, "%s %s %s %f %d\n", vol->numero, vol->depart, vol->destination, vol->nbreKm, vol->nbrePassager);
    printf("Le vol a ete enregistre\n");
    free(vol);
    fclose(fichier);
}
/*----------------------------------------*/
void enregistrerTabVol(TabVolPtr tabVol, int nbreVol){
    if (tabVol == NULL) {
        printf("Aucun vol n'est enregistre\n");
        return;
    }

    FILE *fichier = fopen(FILENAME, "a+");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nbreVol; i++) {
        // Vérifier si le numéro de vol existe déjà dans le fichier
        char ligne[256];
        char num[20];
        char depart[50];
        char destination[50];
        float nbreKm;
        int nbrePassager;
        int existe = 0;
        FILE *fichierLecture = fopen(FILENAME, "r");
        if (fichierLecture != NULL) {
            while (fgets(ligne, 256, fichierLecture) != NULL) {
                sscanf(ligne, "%s %s %s %f %d\n", num, depart, destination, &nbreKm, &nbrePassager);
                if (strcmp(num, tabVol[i].vols->numero) == 0) {
                    printf("Le vol avec le numero %s existe deja. Ignoré.\n", tabVol[i].vols->numero);
                    existe = 1;
                    break;
                }
            }
            fclose(fichierLecture);
        }

        if (!existe) {
            fprintf(fichier, "%s %s %s %f %d\n", tabVol[i].vols->numero, tabVol[i].vols->depart, tabVol[i].vols->destination, tabVol[i].vols->nbreKm, tabVol[i].vols->nbrePassager);
        }
    }
    fclose(fichier);
    printf("Les vols ont ete enregistres\n");
}
/*----------------------------------------*/
void rechercherVolFichier(char* numero){
    char ligne[256];
    char num[20];
    char depart[50];
    char destination[50];
    float nbreKm;
    int nbrePassager;
    int trouve = 0;
    FILE *fichier = fopen(FILENAME, "r");
    if(fichier == NULL){
        fprintf(stderr, "Erreur d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(ligne, 256, fichier) != NULL){
        sscanf(ligne, "%s %s %s %f %d\n", num, depart, destination, &nbreKm, &nbrePassager); 
        if(strcmp(num, numero) == 0){
            printf("vol trouve\n");
            printf("%s %s-%s %.2fKm %d passagers\n", num, depart, destination, nbreKm, nbrePassager);
            trouve = 1;
            fclose(fichier);
            break;
        }
    } 
    if(trouve == 0){
        printf("Le vol %s n'existe pas\n", numero);
    }
    fclose(fichier);
}
/*----------------------------------------*/
void nombrePassagerFichier(){
    char ligne[256];
    char num[20];
    char depart[50];
    char destination[50];
    float nbreKm;
    int nbrePassager;
    int total = 0;
    FILE *fichier = fopen(FILENAME, "r");
    if(fichier == NULL){
        fprintf(stderr, "Erreur d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(ligne, 256, fichier) != NULL){
        sscanf(ligne, "%s %s %s %f %d\n", num, depart, destination, &nbreKm, &nbrePassager); 
        total += nbrePassager;
    } 
    printf("Le nombre total d'utilisateurs de BVOLS est: %d\n", total);
    fclose(fichier);
}
/*----------------------------------------*/
void viderTabvol(TabVolPtr *tabVol, int *nbreVol) {
    for (int i = 0; i < *nbreVol; i++) {
        free((*tabVol)[i].vols);
    }
    free(*tabVol);
    *tabVol = NULL;
    *nbreVol = 0;
}
/*----------------------------------------*/
void menu(){
    printf("0. Quitter\n");
    printf("1. Saisir un vol\n");
    printf("2. Ajouter un vol dans le tableau des vols\n");
    printf("3. Afficher les vols\n");
    printf("4. Rechercher un vol\n");
    printf("5. Annuler un vol\n");
    printf("6. Enregistrer un vol dans la base de donnees BVOLS\n");
    printf("7. Enregistrer les vols dans la base de donnees BVOLS\n");
    printf("8. Rechercher un vol dans la base de donnees BVOLS\n");
    printf("9. Afficher le nombre d utilisateur dans la base de donnees BVOLS\n");
}
/*----------------------------------------*/