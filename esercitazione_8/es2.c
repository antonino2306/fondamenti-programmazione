#include <stdio.h>
#define SIZE 100

unsigned int input_dimensione();
void stampa_menu();
void riempi_matrice(int arr[][SIZE], size_t righe, size_t colonne);
size_t scegli_riga(unsigned int num_righe);
void stampa_riga(const int arr[][SIZE], size_t colonne, size_t indice_riga);
size_t scegli_colonna(unsigned int num_colonne);
void stampa_colonna(const int arr[][SIZE], size_t righe, size_t indice_colonna);
void stampa_diagonale(const int arr[][SIZE], size_t dim);
int somma_riga(const int arr[][SIZE], size_t colonne, size_t indice_riga);
int somma_colonna(const int arr[][SIZE], size_t righe, size_t indice_colonna);
int somma_diagonale(const int arr[][SIZE], size_t dim);
void modifica_elemento(int arr[][SIZE], size_t righe, size_t colonne);
void stampa_matrice(const int arr[][SIZE], size_t righe, size_t colonne);


int main() {
    int matrice[SIZE][SIZE] = {0};
    
    puts("Numero righe");
    unsigned int righe = input_dimensione();
    puts("Numero colonne");
    unsigned int colonne = input_dimensione();

    riempi_matrice(matrice, righe, colonne);

    int scelta_utente;
    do {
        size_t riga, colonna;
        int somma;

        stampa_menu();
        scanf("%d", &scelta_utente);
        puts("");

        switch (scelta_utente)
        {

            case 0:
                stampa_matrice(matrice, righe, colonne);
                break;    
            case 1:
                riga = scegli_riga(righe);
                stampa_riga(matrice, colonne, riga);
                break;
            
            case 2:
                colonna = scegli_colonna(colonne);
                stampa_colonna(matrice, righe, colonna);
                break;

            case 3:
                if (righe == colonne) {
                    stampa_diagonale(matrice, righe);
                }
                else {
                    puts("La matrice non è quadrata\n");
                }
                break;

            case 4:
                riga = scegli_riga(righe);
                somma = somma_riga(matrice, colonne, riga);
                printf("La somma degli elementi della riga %lu è: %d\n", riga, somma);
                break;

            case 5:
                colonna = scegli_colonna(colonne);
                somma = somma_colonna(matrice, righe, colonna);
                printf("La somma degli elementi della colonna %lu è: %d\n", colonna, somma);
                break;

            case 6:
                if (righe == colonne) {
                    somma = somma_diagonale(matrice, righe);
                    printf("La somma degli elementi della diagonale principale è: %d", somma);
                }
                else {
                    puts("La matrice non è quadrata");
                }
                break;

            case 7:
                modifica_elemento(matrice, righe, colonne);
                break;

            default:
                break;
        }

    } while (scelta_utente != -1);
}

unsigned int input_dimensione()
{
    unsigned int dim;
    do {
        scanf("%u", &dim);
    } while (dim > 100);
    
    return dim;
}

void stampa_menu() {
    printf("\n\n");
    puts("------------------------------------------------------------------");
    puts("0 per stampare la matrice");
    puts("1 per stampare una riga");
    puts("2 per stampare una colonna");
    puts("3 stampare la diagonale principale");
    puts("4 per sommare gli elementi di una riga");
    puts("5 per sommare gli elementi di una colonna");
    puts("6 per sommare gli elementi della diagonale principale");
    puts("7 per modificare il valore memorizzato in una signola cella");
    puts("-1 per uscire");
    puts("------------------------------------------------------------------");
    printf("> ");
}

void riempi_matrice(int arr[][SIZE], size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            printf("[%lu][%lu]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

size_t scegli_riga(unsigned int num_righe)
{
    size_t riga;
    do {
        printf("Inserisci l'indice di riga: ");
        scanf("%lu", &riga);
    } while (riga > num_righe);

    return riga;
}

void stampa_riga(const int arr[][SIZE], size_t colonne, size_t indice_riga)
{
    for (size_t i = 0; i < colonne; i++) {
        printf("%d\t", arr[indice_riga][i]);
    }
    puts("");
}

size_t scegli_colonna(unsigned int num_colonne)
{
    size_t colonna;
    
    do {

        printf("Inserisci l'indice di colonna: ");
        scanf("%lu", &colonna);

    } while (colonna > num_colonne);
    return colonna;
}

void stampa_colonna(const int arr[][SIZE], size_t righe, size_t indice_colonna)
{
    for (size_t i = 0; i < righe; i++) {
        printf("%d\n", arr[i][indice_colonna]);
    }
}

void stampa_diagonale(const int arr[][SIZE], size_t dim)
{
    for (size_t i = 0; i < dim; i++) {
        for (size_t j = 0; j < dim; j++) {
            if (i == j) {
                printf("%d\t", arr[i][j]);
            }
            else {
                printf(" \t");
            }
        }
        puts("");
    }
}

int somma_riga(const int arr[][SIZE], size_t colonne, size_t indice_riga)
{
    int tot = 0;
    for (size_t i = 0; i < colonne; i++) {
        tot += arr[indice_riga][i];
    }
    return tot;
}

int somma_colonna(const int arr[][SIZE], size_t righe, size_t indice_colonna)
{
    int tot = 0;

    for (size_t i = 0; i < righe; i++) {
        tot += arr[i][indice_colonna];
    }
    return tot;
}

int somma_diagonale(const int arr[][SIZE], size_t dim)
{
    int tot = 0;

    for (size_t i = 0; i < dim; i++) {
        for (size_t j = 0; j < dim; j++) {
            if (i == j) {
                tot += arr[i][j];
            }
        }
    }
    return tot;
}

void modifica_elemento(int arr[][SIZE], size_t righe, size_t colonne)
{
    size_t indice_riga = scegli_riga(righe);
    size_t indice_colonna = scegli_colonna(colonne);
    printf("Inserisci il nuovo valore: ");

    scanf("%d", &arr[indice_riga][indice_colonna]);
}

void stampa_matrice(const int arr[][SIZE], size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            printf("%d\t", arr[i][j]);
        }
        puts("");
    }
}
