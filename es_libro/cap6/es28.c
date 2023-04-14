#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define SIZE 20

unsigned int cerca_numero(const unsigned int arr[], size_t size, unsigned int n);
void stampa_array(const unsigned int arr[], size_t size);

int main() {
    unsigned int numeri[SIZE] = {0};
    unsigned int memo = 0;

    srand(time(NULL));

    for (size_t i = 0; i < SIZE; i++) {
        unsigned int n = 1 + (rand() % 20);
        unsigned short int trovato;

        trovato = cerca_numero(numeri, memo, n);

        if (trovato == 0) {
        
            numeri[memo] = n;
            memo++;
    
        }
    }

    stampa_array(numeri, memo);
    
}

void stampa_array(const unsigned int arr[], size_t size) {

    for (size_t i = 0; i < size; i++) {

        printf("Numeri[%lu]: %u\n", i, arr[i]);

    }
}

unsigned int cerca_numero(const unsigned int arr[], size_t size, unsigned int n)
{
    unsigned int trovato = 0;
        
    for(size_t j = 0; j <= size && !trovato; j++) {

        if (n == arr[j]) {
            trovato = 1;
        }

    }

    return trovato;
}
