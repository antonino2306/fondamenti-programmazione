#include <stdio.h>

int main() {
    unsigned int num_valori, num_positivi = 0, num_negativi = 0, num_nulli = 0;
    int numero;

    printf("Quanti valori inserirai: ");
    scanf("%u", &num_valori);

    for (unsigned int i = 0; i < num_valori; i++) {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);

        if (numero > 0) {
            num_positivi++;
        }
        else if (numero < 0) {
            num_negativi++;
        }
        else {
            num_nulli++;
        }
    }

    printf("Riepilogo: \nPositivi: %u \nNegativi: %u \nNulli: %u\n", num_positivi, num_negativi, num_nulli);
    return 0;
}