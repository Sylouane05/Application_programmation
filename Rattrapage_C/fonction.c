#include "fonction.h"

/*---------------------------------SaisirAction---------------------------------*/
ActionPtr SaisirAction(int *nb){
   Action *A;
   A = malloc(sizeof(*A));
   if(A == NULL){
       fprintf(stderr, "Probleme d'allocation de memoire\n");
       exit(EXIT_FAILURE);
   }
   A->id = *nb;
   printf("Entrez le nom de l etudiant: ");
   scanf("%s", A->nom); // 
   fgets(A->nom, 128, stdin);
   A->nom[strlen(A->nom) - 1] = '\0';
   while(1){
         printf("Entrez le numero de l'objectif(de 1 a 17):");
         scanf("%d", &A->object);
            if(A->object >= 1 && A->object <= 17){
                break;
            }
            printf("Objectif invalide ! Veuillez entrer un numero entre 1 et 17.\n");
   }
   printf("Entrez le libelle de l action: ");
   scanf("%s", A->libelle);
   fgets(A->libelle, 256, stdin);
   A->libelle[strlen(A->libelle) - 1] = '\0';
   while(1){
         printf("Entrez le score de l action(de 1 a 5):");
         scanf("%d", &A->score);
            if(A->score >= 1 && A->score <= 5){
                break;
            }
            printf("Score invalide ! Veuillez entrer un score entre 1 et 5.\n");
   }
    return A;
}
/*---------------------------------SaisirAction---------------------------------*/

/*---------------------------------EnregistrerAction---------------------------------*/
void EnregistrerAction(ActionPtr **A, int *capacite, int *nb){
    if(*nb == *capacite){
        *capacite *= 2;
        *A = realloc(*A, *capacite * sizeof(*A));
        if(A == NULL){
            fprintf(stderr, "Probleme d'allocation de memoire\n");
            exit(EXIT_FAILURE);
        }
    }
    (*A)[*nb] = SaisirAction(nb);
    *nb += 1;
    printf("Action enregistree avec succes\n");
}
/*---------------------------------EnregistrerAction---------------------------------*/

/*---------------------------------Afficher_score_eleve---------------------------------*/
void Afficher_score_eleve(ActionPtr *A, int *nb){
   char nom[256];
   printf("Entrez le nom de l etudiant: ");
   scanf("%s", nom);
   fgets(nom, 256, stdin);
   nom[strlen(nom) - 1] = '\0';
   int score = 0;
    for(int i = 0; i < *nb; i++){
         if(strcmp(A[i]->nom, nom) == 0){
              score += A[i]->score;
         }
    }
    if(score == 0){
        printf("Aucune action pour cet etudiant\n");
    }
    else{
        printf("Le score total de l etudiant %s est de: %d\n", nom, score);
    }
}
/*---------------------------------Afficher_score_eleve---------------------------------*/  

/*---------------------------------Afficher_score_objectif---------------------------------*/
void Afficher_score_objectif(ActionPtr *A, int *nb){
   int object;
   while(1){
         printf("Entrez le numero de l objectif(de 1 a 17):");
         scanf("%d", &object);
            if(object >= 1 && object <= 17){
                break;
            }
            printf("Objectif invalide ! Veuillez entrer un numero entre 1 et 17.\n");
   }
   int score = 0;
    for(int i = 0; i < *nb; i++){
         if(A[i]->object == object){
              score += A[i]->score;
         }
    }
    if(score == 0){
        printf("Aucune action pour cet objectif\n");
    }
    else{
        printf("Le score total pour l objectif %d est de: %d\n", object, score);
    }
}
/*---------------------------------Afficher_score_objectif---------------------------------*/

/*---------------------------------ModifierAction---------------------------------*/
void ModifierAction(ActionPtr **A, int *nb){
    int id;
    int score;
    printf("Entrez l id de l action a modifier: ");
    scanf("%d", &id);
    if(id >= *nb || id < 0){
        printf("Id invalide\n");
        exit(EXIT_FAILURE);
    }
    printf("Entrez un nouveau score pour l action: ");
    scanf("%d", &score);
    (*A)[id]->score = score;
    printf("Action modifiee avec succes\n");
}
/*---------------------------------ModifierAction---------------------------------*/

/*---------------------------------Enregistrer_Fichier---------------------------------*/
void Enregistrer_Fichier(char *nom_fichier, ActionPtr *A, int *nb){
    FILE *f;
    f = fopen(nom_fichier, "a");
    if(f == NULL){
        fprintf(stderr, "Probleme d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "---Actions---\n");
    for(int i = 0; i < *nb; i++){
        fprintf(f, "ID: %d\nNom: %s\nObjectif: %d\nLibelle: %s\nScore: %d\n", A[i]->id, A[i]->nom, A[i]->object, A[i]->libelle, A[i]->score);
    }
    fclose(f);
}
/*---------------------------------Enregistrer_Fichier---------------------------------*/

/*---------------------------------vider---------------------------------*/
void vider(ActionPtr **A, int *nb){
    for(int i = 0; i < *nb; i++){
        free((*A)[i]);
    }
    free(*A);
    *nb = 0;
}
/*---------------------------------vider---------------------------------*/

/*---------------------------------Afficher_score_ToutObjectif---------------------------------*/
void Afficher_score_ToutObjectif(ActionPtr *A, int *nb){
    int score[17] = {0};
    for(int i = 0; i < 17; i++){
        for(int j = 0; j < *nb; j++){
            if(A[j]->object == i + 1){
                score[i] += A[j]->score;
            }
        }
    }
    for(int i = 0; i < 17; i++){
        printf("Le score total pour l objectif %d est de: %d\n", i + 1, score[i]);
    }
}