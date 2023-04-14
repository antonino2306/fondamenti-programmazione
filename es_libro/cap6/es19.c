#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 11

unsigned int lancia_dado();
void stampa_risultati(unsigned int arr[], size_t size);

int main() {
    unsigned int somma_dadi = 0;
    unsigned int frequenza_somme[SIZE] = {0};
    const int numero_lanci = 36000;
    unsigned int dado1, dado2;
    
    // Fornisco il seme time(NULL) al generatore di numeri casuali
    srand(time(NULL));
    for (unsigned int i = 0; i < numero_lanci; i++) {

        dado1 = lancia_dado();
        dado2 = lancia_dado();

        somma_dadi = dado1 + dado2;

        // Le somme vanno da 2 a 12, sottraendo 2 faccio in modo che vengano ordinate
        // dall'indice 0 a 10 dell'array
        frequenza_somme[somma_dadi - 2]++; 
    }

    stampa_risultati(frequenza_somme, SIZE);
}

unsigned int lancia_dado() {
    unsigned int lancio = 1 + (rand() % 6);
    return lancio;
}

void stampa_risultati(unsigned int arr[], size_t size){
    printf("Somma\t\t Frequenza\n");
    for (size_t i = 0; i < size; i++) {
        printf("%lu\t\t %9u\n", i + 2, arr[i]);
    }
}