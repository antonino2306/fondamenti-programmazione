#include <stdio.h>
#define SIZE 20

int main() {
    unsigned int numero;
    unsigned int array[SIZE] = {0};

    for (size_t i = 0; i < SIZE; i++) {
        unsigned int trovato = 0;
        
        printf("Inserisci numero compreso tra 10 e 100: ");
        scanf("%u", &numero); 
        
        for (size_t j = 0; j <= i; j++) {
            if (numero == array[j]) {
                trovato = 1;
            }
        }

        if (!trovato) {
            printf("Numero inserito\n");
            array[i] = numero;
        }
        else {
            printf("Numero già presente in memoria\n");
        }
    }

    for (size_t i = 0; i < SIZE; i++) {
        printf("array[%lu] = %u\n", i, array[i]);
    }

    return 0;
}