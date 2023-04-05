#include <stdio.h>
#define SIZE 100 


int main() {
    int numeri[SIZE] = {0};
    // int max, min, secondo_max, secondo_min;
    unsigned int size_utente;

    printf("Inserisci la dimensione dell'array (< 100): ");
    scanf("%u", &size_utente);

    for (size_t i = 0; i < size_utente; i++) {
        printf("Inserisci numero: ");
        scanf("%d", &numeri[i]);
    }

    for (size_t i = 0; i < size_utente; i++) {
        int tmp;

        for (size_t j = 0; j < size_utente-1; j++) {
            if (numeri[j] > numeri[j+1]) {
                tmp = numeri[j];
                numeri[j] = numeri[j+1];
                numeri[j+1] = tmp;
            }
        }
    }

    printf("Massimo: %d\n", numeri[size_utente-1]);
    printf("Minimo: %d\n", numeri[0]);
    printf("Secondo massimo: %d\n", numeri[size_utente-2]);
    printf("Secondo minimo: %d\n", numeri[1]);


}