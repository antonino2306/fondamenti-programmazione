// Definizione delle funzioni
#include <stdio.h>
#include "var_declaration.h"

unsigned int leggi_num_valori() {
    unsigned int n;
    printf("Quanti valori inserirai: ");
    scanf("%u", &n);

    return n;
}

extern void determina_segno(int n){
    if (n > 0) {
        num_positivi++;    
    }
    else if (n < 0) {
        num_negativi++;
    }
    else {
        num_nulli++;
    }
}