#include <stdio.h>


int main(void){
    int stop = 0;
    float accumulateur = 0.0;
    float operande ;
    char operateur;

    printf("Bonjour, bienvenu dans la calculatrice HP\n");
    printf("saisissez les operations au format : <numeric><operateur>. ex : 123.5+\n");
    printf("Pour quitter, saisissez <numeric>q\n"); 

    while(stop == 0){
        printf("Commande: ");
        scanf("%f%c", &operande, &operateur);
        if(operateur == 'q'){
            stop = 1;
            printf("Accumulateur: %f\n", accumulateur);
            printf("Au revoir\n");
        }else{
            if (operateur == '+'){
                accumulateur += operande;
            }else if (operateur == '-'){
                accumulateur -= operande;
            }else if (operateur == '*'){
                accumulateur *= operande;
            }else if (operateur == '/'){
                if(operande == 0){
                    printf("Division par zero impossible\n");
                }else{
                    accumulateur /= operande;
                }
            }else{
                printf("Operateur inconnu\n");
            }
            printf("Accumulateur: %f\n", accumulateur);
        }
    }


    return 0;
}