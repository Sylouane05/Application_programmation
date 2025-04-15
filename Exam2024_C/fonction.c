#include "fonction.h"


/*-------------------------------------*/
float cal_dep(Usager *U){
    float dep = 0;
    if(strcmp(U->type, "etudiant") == 0){
        dep = ETUD *  U->distance * (U->T->Velo_Elec * VELO_ELEC + U->T->Bus * BUS + U->T->Voiture * VOITURE);
    }
    else{
        dep = ADMIN *  U->distance * (U->T->Velo_Elec * VELO_ELEC + U->T->Bus * BUS + U->T->Voiture * VOITURE);
    }
    return dep;
}
/*-------------------------------------*/

/*-------------------------------------*/
float cal_alim(Usager *U){
    float alim = 0;
    if(strcmp(U->type, "etudiant") == 0){
        alim = ETUD *  U->distance * (U->A->Veg * VEG + U->A->Poisson * POISSON + U->A->Poulet * POULET + U->A->Boeuf * BOEUF);
    }
    else{
        alim = ADMIN *  U->distance * (U->A->Veg * VEG + U->A->Poisson * POISSON + U->A->Poulet * POULET + U->A->Boeuf * BOEUF);
    }
    return alim;
}
/*-------------------------------------*/

/*-------------------------------------*/
UsagerPtr creer_usager(int *nb){
    Usager *U;
    U = malloc(sizeof(*U));
    if(U == NULL){
        fprintf(stderr, "Probleme d'allocation de memoire\n");
        exit(EXIT_FAILURE);
    }
    U->T = malloc(sizeof(*U->T));
    if(U->T == NULL){
        fprintf(stderr, "Probleme d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    U->A = malloc(sizeof(*U->A));
    if(U->A == NULL){
        fprintf(stderr, "Probleme d'allocation de memoire\n");
        exit(EXIT_FAILURE);
    }
    
    U->id = *nb;
    printf("Entrez le nom de l'usager: ");
    scanf("%s", U->nom);
    printf("Entrez le prenom de l'usager: ");
    scanf("%s", U->prenom);
    while (1) {
        printf("Entrez le type de l'usager (etudiant, administrateur, enseignant): ");
        scanf("%s", U->type);
        if (strcmp(U->type, "etudiant") == 0 || strcmp(U->type, "administrateur") == 0 || strcmp(U->type, "enseignant") == 0) {
            break; //  Type valide → on sort de la boucle
        }
        printf(" Type invalide ! Veuillez entrer 'etudiant', 'administrateur' ou 'enseignant'.\n");
    }
    printf("Entrez la distance parcourue par l'usager: ");
    scanf("%f", &U->distance);
    while (1) {
        printf("Entrez le coefficient de marche a pied: ");
        scanf("%f", &U->T->A_Pied);
        printf("Entrez le coefficient de velo: ");
        scanf("%f", &U->T->Velo);
        printf("Entrez le coefficient de velo electrique: ");
        scanf("%f", &U->T->Velo_Elec);
        printf("Entrez le coefficient de bus: ");
        scanf("%f", &U->T->Bus);

        U->T->Voiture = 1 - U->T->A_Pied - U->T->Velo - U->T->Velo_Elec - U->T->Bus;
        
        if (U->T->Voiture >= 0) {
            break; //  Somme valide → on sort de la boucle
        }
        printf(" Erreur : La somme des coefficients doit etre ≤ 1. Veuillez recommencer.\n");
    }

    
    while (1) {
        printf("Entrez le coefficient de repas vegetarien: ");
        scanf("%f", &U->A->Veg);
        printf("Entrez le coefficient de repas au poisson: ");
        scanf("%f", &U->A->Poisson);
        printf("Entrez le coefficient de repas au poulet: ");
        scanf("%f", &U->A->Poulet);

        U->A->Boeuf = 1 - U->A->Veg - U->A->Poisson - U->A->Poulet;

        if (U->A->Boeuf >= 0) {
            break; // Somme valide → on sort de la boucle
        }
        printf(" Erreur : La somme des coefficients doit être ≤ 1. Veuillez recommencer.\n");
    }
    U->cout_carbone = cal_dep(U) + cal_alim(U);
    return U;
}
/*-------------------------------------*/

/*-------------------------------------*/
void saisie_usager(UsagerPtr **U, int *capacite, int *nb){
    if(*nb >= *capacite){
        *capacite *= 2;
        *U = realloc(*U, *capacite * sizeof(*U));
        if(U == NULL){
            fprintf(stderr, "Probleme d'allocation de memoire\n");
            exit(EXIT_FAILURE);
        }
    }
    (*U)[*nb] = creer_usager(nb);
    *nb += 1;
    printf("Usager ajoute avec succes\n");
}
/*-------------------------------------*/

/*-------------------------------------*/
void modifier_usager(UsagerPtr **U,  int *nb){
    if(*nb == 0){
        printf("Aucun usager\n");
        return;
    }
    int id;
    printf("Entrez l'id de l'usager a modifier: ");
    scanf("%d", &id);
    if(id >= *nb || id < 0){
        printf("Id invalide\n");
        exit(EXIT_FAILURE);
    }
    free((*U)[id]);
    (*U)[id] = creer_usager(&id);
    printf("Usager modifie avec succes\n");
}
/*-------------------------------------*/

/*-------------------------------------*/
void supprimer_usager(UsagerPtr **U, int *nb){
    if(*nb == 0){
        printf("Aucun usager\n");
        return;
    }
    int id;
    printf("Entrez l'id de l'usager a supprimer: ");
    scanf("%d", &id);
    if(id >= *nb || id < 0){
        printf("Id invalide\n");
        exit(EXIT_FAILURE);
    }
    free((*U)[id]);
    for(int i = id; i < *nb - 1; i++){
        (*U)[i + 1]->id -= 1;
        (*U)[i] = (*U)[i + 1];
    }
    *nb -= 1;
    printf("Usager supprime avec succes\n");
}
/*-------------------------------------*/

/*-------------------------------------*/
void afficher_usager(UsagerPtr *U, int *nb){
    if(*nb == 0){
        printf("Aucun usager\n");
        return;
    }
    for(int i = 0; i < *nb; i++){
        printf("Id: %d\n", U[i]->id);
        printf("Nom: %s\n", U[i]->nom);
        printf("Prenom: %s\n", U[i]->prenom);
        printf("Type: %s\n", U[i]->type);
        printf("Distance: %2.f\n", U[i]->distance);
        printf("Cout carbone: %2.f\n", U[i]->cout_carbone);
    }
}
/*-------------------------------------*/

/*-------------------------------------*/
void cal_carb(UsagerPtr *U, int *nb){
    float carb = 0;
    for(int i = 0; i < *nb; i++){
        carb += U[i]->cout_carbone;
    }
    printf("Le cout carbone total est de: %f\n", carb);
}
/*-------------------------------------*/

/*-------------------------------------*/
void creer_file(){
    FILE *f;
    f = fopen("usagers.txt", "w");
    if(f == NULL){
        fprintf(stderr, "Probleme d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    fclose(f);
}
/*-------------------------------------*/

/*-------------------------------------*/
void enregistrer_file(UsagerPtr *U, int *nb){
    FILE *f;
    f = fopen("usagers.txt", "a");
    if(f == NULL){
        fprintf(stderr, "Probleme d'ouverture du fichier\n");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "--------Usagers--------\n");
    for(int i = 0; i < *nb; i++){
        fprintf(f, "ID: %d\n 
            Nom: %s\n Prenom: %s\n 
            Type: %s\n 
            Distance domicile-ecole en Km: %2.f\n 
            Modalite de transport en pourcentage: A pied: %2.f Velo: %2.f Velo electrique: %2.f Bus: %2.f Voiture: %2.f\n 
            Modalite de repas en pourcentage: Vegetarien: %2.f Poisson: %2.f Poulet: %2.f Boeuf: %2.f\n ",
             U[i]->id, U[i]->nom, U[i]->prenom, U[i]->type, U[i]->distance, U[i]->T->A_Pied * 100, U[i]->T->Velo * 100, U[i]->T->Velo_Elec * 100, U[i]->T->Bus * 100, U[i]->T->Voiture * 100, U[i]->A->Veg * 100, U[i]->A->Poisson * 100, U[i]->A->Poulet * 100, U[i]->A->Boeuf * 100); 
    }
    fclose(f);
}
/*-------------------------------------*/

/*-------------------------------------*/
void vider(UsagerPtr **U, int *nb){
    for(int i = 0; i < *nb; i++){
        free((*U)[i]);
    }
    free(*U);
    *nb = 0;
}
/*-------------------------------------*/

