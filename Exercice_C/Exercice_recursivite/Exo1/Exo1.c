#include <stdio.h>
#include <math.h>

/*
U0 = 5
Un = sqrt(2 + Un-1) pour n > 0
*/

float suite(int n){
    float resultat = 0;
    if(n == 1){
        resultat += 5;
    } else if (n > 1){
        resultat += sqrt(2 + suite(n - 1));
    } else {
        printf("Erreur : n doit être supérieur ou égal à 1.\n");
        return -1; // Valeur d'erreur
    }
    return resultat;
}

int main(){
    int n;
    printf("Entrez le nombre de termes de la suite : ");
    scanf("%d", &n);
    while(n < 1){
        printf("Erreur : n doit etre superieur ou egal a 1.\n");
        printf("Entrez le nombre de termes de la suite : ");
        scanf("%d", &n);
    }
    for (int i = 1; i <= n; i++){
        printf("U%d = %.2f\n", i-1, suite(i));
    }
return 0;
}