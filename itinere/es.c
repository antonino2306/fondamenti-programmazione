#include <stdio.h>
#define SIZE 100

void riempi_array(int arr[], size_t dim);
int cerca_pattern(const int pattern[], const int arr[], size_t dim_pattern, size_t dim_arr);
void moltiplica_pari(int arr[], size_t dim, int k);
void stampa_menu();
int determina_dimensione();
int inserisci_parametro();

int main() {
    int sequenza[SIZE] = {0};
    int pattern[SIZE] = {0};
    int dim_arr = determina_dimensione();
    int dim_pattern;
    int scelta_utente;

    do {
        stampa_menu();
        scanf("%d", &scelta_utente);

        switch (scelta_utente) {
            case 1:
                riempi_array(sequenza, dim_arr);
                break;

            case 2:
                dim_pattern = determina_dimensione();
                riempi_array(pattern, dim_pattern);
                unsigned int conta_pattern = cerca_pattern(pattern, sequenza, dim_pattern, dim_arr);
                printf("Numero pattern: %u\n", conta_pattern);
                break;
            
            case 3:
                int k = inserisci_parametro();
                moltiplica_pari(sequenza, dim_arr, k);
                break;
            
            case 4: default:
                break;
        }
    } while(scelta_utente != 4);

    printf("Programma terminato\n");
    return 0;
}

void riempi_array(int arr[], size_t dim) {
    for (size_t i = 0; i < dim; i++) {
        printf("[%lu]: ", i);
        scanf("%d", &arr[i]);
    }
}

int cerca_pattern(const int pattern[], const int arr[], size_t dim_pattern, size_t dim_arr) {
    unsigned int conta_pattern = 0;
    size_t indice_pattern = 0;

    for (size_t i = 0; i < dim_arr; i++) {

        if (arr[i] == pattern[indice_pattern]) {
            indice_pattern++;
        }

        if (indice_pattern == dim_pattern) {
            conta_pattern++;
            indice_pattern = 0;
        }
    }

    return conta_pattern;
}

void moltiplica_pari(int arr[], size_t dim, int k)
{
    for (size_t i = 0; i < dim; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] *= 2;
        }
    }
}

int determina_dimensione()
{   
    unsigned int dimensione;
    printf("Inserisci dimensione: ");
    scanf("%u", &dimensione);

    if (dimensione > SIZE) {
        dimensione = SIZE;
    }
    
    return dimensione;
}

int inserisci_parametro()
{
    int k;
    printf("Inserisci parametro: ");
    scanf("%d", &k);
    return k;
}

void stampa_menu() {
    puts("1 per riempire il vettore");
    puts("2 per cercare un pattern");
    puts("3 per moltiplicare per un parametro i valori pari");
    puts("4 per uscire");
    printf("> ");
}
