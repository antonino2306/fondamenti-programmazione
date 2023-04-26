#include <stdio.h>
#define RIGHE 4
#define COLONNE 3
#define COLONNE_2 2

void riempi_matrice(int arr[][COLONNE], size_t num_righe, size_t num_colonne);
void riempi_matrice2(int arr[][COLONNE_2], size_t num_righe, size_t num_colonne);
void stampa_matrice(const int arr[][COLONNE], size_t num_righe, size_t num_colonne);
void stampa_matrice2(const int arr[][COLONNE_2], size_t num_righe, size_t num_colonne);
void prodotto(const int a[][COLONNE], const int b[][COLONNE_2], int prod[][COLONNE_2], size_t num_righe, size_t num_colonne, size_t num_colonne2);

int main() {

    int a[RIGHE][COLONNE] = {0};
    int b[COLONNE][COLONNE_2] = {0};
    int prod[RIGHE][COLONNE_2] = {0};

    puts("Inizializza matrice a");
    riempi_matrice(a, RIGHE, COLONNE);

    puts("Inizializza matrice b");
    riempi_matrice2(b, COLONNE, COLONNE_2);

    puts("Matrice a");
    stampa_matrice(a, RIGHE, COLONNE);

    puts("Matrice b");
    stampa_matrice2(b, RIGHE, COLONNE_2);

    puts("Prodotto");
    prodotto(a, b, prod, RIGHE, COLONNE, COLONNE_2);
    stampa_matrice2(prod, RIGHE, COLONNE_2);
    
    return 0;
}

void riempi_matrice(int arr[][COLONNE], size_t num_righe, size_t num_colonne)
{
    for (size_t i = 0; i < num_righe; i++) {
        for (size_t j = 0; j < num_colonne; j++) {
            printf("[%lu][%lu]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void riempi_matrice2(int arr[][COLONNE_2], size_t num_righe, size_t num_colonne)
{
    for (size_t i = 0; i < num_righe; i++) {
        for (size_t j = 0; j < num_colonne; j++) {
            printf("[%lu][%lu]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void stampa_matrice(const int arr[][COLONNE], size_t num_righe, size_t num_colonne)
{
    for (size_t i = 0; i < num_righe; i++) {
        for (size_t j = 0; j < num_colonne; j++) {
            printf("%d\t", arr[i][j]);
        }
        puts("");
    }
}

void stampa_matrice2(const int arr[][COLONNE_2], size_t num_righe, size_t num_colonne)
{
    for (size_t i = 0; i < num_righe; i++) {
        for (size_t j = 0; j < num_colonne; j++) {
            printf("%d\t", arr[i][j]);
        }
        puts("");
    }
}


void prodotto(const int a[][COLONNE], const int b[][COLONNE_2], int prod[][COLONNE_2], size_t num_righe, size_t num_colonne, size_t num_colonne2)
{
    for (size_t i = 0; i < num_righe; i++) {

        for (size_t j = 0; j < num_colonne2; j++) {
            
            for (size_t k = 0; k < num_colonne; k++) {
                prod[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
