#include <stdio.h>
#define SIZE 100

void inserisci_dimensioni(unsigned int* seq_size, unsigned int* patt_size);
void inserisci_valori(int arr[], size_t size);
short int cerca_pattern(const int arr[], const int pattern[], size_t arr_size, size_t pattern_size);

int main() {

    int sequenza[SIZE] = {0}, pattern[SIZE] = {0};
    unsigned int seq_dim, patt_dim;

    inserisci_dimensioni(&seq_dim, &patt_dim);

    printf("Sequenza:\n");
    inserisci_valori(sequenza, seq_dim);
    
    printf("Pattern:\n");
    inserisci_valori(pattern, patt_dim);

    int inizio_sequenza = cerca_pattern(sequenza, pattern, seq_dim, patt_dim);

    if (inizio_sequenza == -1) {
        printf("Pattern non trovato\n");
    }
    else {
        printf("Il pattern inizia dalla posizione %d\n", inizio_sequenza);
    }

    return 0;

}

void inserisci_dimensioni(unsigned int *seq_size, unsigned int *patt_size)
{
    printf("Inserisci dimensione della sequenza: ");
    scanf("%u", &*seq_size);

    do {
        printf("Inserisci dimensione pattern: ");
        scanf("%u", &*patt_size);
    } while (*patt_size >= *seq_size);

}

void inserisci_valori(int arr[], size_t size) {
    
    for (size_t i = 0; i < size; i++) {
        printf("[%lu]: ", i);
        scanf("%d", &arr[i]);
    }
}

short int cerca_pattern(const int arr[], const int pattern[], size_t arr_size, size_t pattern_size)
{
    unsigned short int trovato = 0;
    unsigned int indice_pattern = 0;
    int inizio_sequenza;

    for (size_t i = 0; i < arr_size && trovato < pattern_size; i++) {


        if (arr[i] == pattern[indice_pattern]) {
            
            if (trovato == 0) {
                inizio_sequenza = i;
            }
            indice_pattern++;
            trovato++;
        }
        else {
            trovato = 0;
            indice_pattern = 0;
            inizio_sequenza = -1;
        }

    }
    return inizio_sequenza;
}
