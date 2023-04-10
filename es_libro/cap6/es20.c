#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

unsigned int lancia_dadi();
void craps(unsigned int freq_vittorie[], unsigned int freq_sconfitte[], size_t size);
void stampa_array(const unsigned int arr[], size_t size);

int main() {

    srand(time(NULL));

    unsigned int freq_vittorie[SIZE] = {0}, freq_sconfitte[SIZE] = {0};
    

    for (unsigned int i = 0; i < 10000; i++) {
        craps(freq_vittorie, freq_sconfitte, SIZE);
    }
    
    printf("Risultati del gioco: ");
    printf("\nNumero Vittorie:\n");
    stampa_array(freq_vittorie, SIZE);
    printf("\nNumero sconfitte:\n");
    stampa_array(freq_sconfitte, SIZE);

    return 0;
}



unsigned int lancia_dadi()
{

    unsigned int dado1 = 1 + (rand() % 6);
    unsigned int dado2 = 1 + (rand() % 6);

    return dado1 + dado2;

}

void craps(unsigned int freq_vittorie[], unsigned int freq_sconfitte[], size_t size)
{
    unsigned int mio_punteggio, somma_dadi = 0, num_lanci = 0;
    somma_dadi = lancia_dadi();

    switch (somma_dadi)
    {
    case 7: case 11:
        freq_vittorie[0]++;
        break;

    case 2: case 3: case 12:
        freq_sconfitte[0]++;
        break;
    default:
        num_lanci++;
        mio_punteggio = somma_dadi;
        break;
    }

    unsigned short int lancia = 1;

    while (lancia) {
        somma_dadi = lancia_dadi();
        num_lanci++;

        if (somma_dadi == mio_punteggio) {
            if (num_lanci >= size) {
                freq_vittorie[size-1]++;
            }
            else {
                freq_vittorie[num_lanci - 1]++;
            }
            lancia = 0;
        }
        else if (somma_dadi == 7) {
            if (num_lanci >= size) {
                freq_sconfitte[size-1]++;
            }
            else {
                freq_sconfitte[num_lanci-1]++;
            }
            lancia = 0;
        }
    }

}

void stampa_array(const unsigned int arr[], size_t size)
{

    for (size_t i = 0; i < size; i++) {
        if (i != size - 1) {
            printf("[%lu] lanci: %u", i+1, arr[i]);
        }
        else {
            printf("[%li+] lanci: %u", i+1, arr[i]);
        }
        printf("\n");
        
    }

}
