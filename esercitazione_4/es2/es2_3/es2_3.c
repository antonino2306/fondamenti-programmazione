// Risolvere equazioni del tipo ax + b = 0
#include <stdio.h>

float risolvi_eq(float a, float b);

int main() {
    float a, b, soluzione;

    printf("Risolvi equazioni del tipo ax + b = 0.\nInserisi il coefficiente del termine di primo grado e il termine noto: ");
    
    do {
        scanf("%f %f", &a, &b);
        if (a == 0){
            printf("a deve essere diverso da 0. Inserisci nuovamente i valori: ");
        }
    } while (a == 0);

    // if (a == 0) {
    //     printf("Errore!!! a deve essere diverso da zero\n");
    //     return 1;
    // }

    soluzione = risolvi_eq(a, b);
    printf("La soluzione dell'equazione %.1fx + %.1f = 0 è: x = %.1f\n", a, b, soluzione);
    
    return 0;
}

float risolvi_eq(float a, float b)
{
    float sol = -1 * b / a;
    return sol;
}
