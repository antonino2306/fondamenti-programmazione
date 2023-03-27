#include <stdio.h>
#include "functions.h"

unsigned int num_positivi = 0, num_negativi = 0, num_nulli = 0;

int main() {
    unsigned int num_valori;
    int numero;

    num_valori = leggi_num_valori();

    for (unsigned int i = 0; i < num_valori; i++) {
        printf("Inserisci un numero: ");
        scanf("%d", &numero);

        determina_segno(numero);
    }

    printf("Riepilogo: \nPositivi: %u \nNegativi: %u \nNulli: %u\n", num_positivi, num_negativi, num_nulli);
    return 0;

}