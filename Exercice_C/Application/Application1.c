#include <stdio.h>

int main(){
    int nbreTerme, i, valeur;
    int somme = 0;
    int produit = 1;
    float moyenne = 0;

    printf("Entrez le nombre de termes: ");
    scanf("%d", &nbreTerme);

    for(i=0; i<nbreTerme; i++){
        printf("Entrez la valeur du terme %d: ", i+1);
        scanf("%d", &valeur);
        if(valeur < 1 || valeur > 50){
            printf("La valeur doit être comprise entre 1 et 50\n");
            i--;
        }else{
            somme += valeur;
            produit *= valeur;
        }
        
    }
    moyenne = somme / (float)nbreTerme;
    printf("La somme des termes est: %d\n", somme);
    printf("Le produit des termes est: %d\n", produit);
    printf("La moyenne des termes est: %.2f\n", moyenne);

    return 0;
}