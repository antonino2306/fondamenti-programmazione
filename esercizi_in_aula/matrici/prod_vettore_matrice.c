#include <stdio.h>
#define RIGHE 4
#define COLONNE 3

void rimepi_vettore(int arr[], size_t dim);
void riempi_matrice(int arr[][COLONNE], size_t num_righe, size_t num_colonne);
void prodotto(const int vettore[], const int matrice[][COLONNE], int prodotto[], size_t num_righe, size_t num_colonne);
void stampa_vettore(const int arr[], size_t dim);
void stampa_matrice(const int arr[][COLONNE], size_t num_righe, size_t num_colonne);


int main() {

    // Per calcolare il prodotto il numero di elementi del vettore deve essere = al num righe della matrice
    int vettore[RIGHE] = {0};
    int matrice[RIGHE][COLONNE] = {0};

    // Il prodotto tra vettore e matrice è un vettore con componenti = colonne della matrice.
    int prod[COLONNE] = {0};

    puts("Inizializza vettore");
    rimepi_vettore(vettore, RIGHE);

    puts("Inizializza matrice");
    riempi_matrice(matrice, RIGHE, COLONNE);
    
    puts("Vettore:");
    stampa_vettore(vettore, RIGHE);

    puts("Matrice:");
    stampa_matrice(matrice, RIGHE, COLONNE);

    puts("Prodotto");
    prodotto(vettore, matrice, prod, RIGHE, COLONNE);
    stampa_vettore(prod, COLONNE);

    return 0;

}

void rimepi_vettore(int arr[], size_t dim)
{
    for (size_t i = 0; i < dim; i++) {
        printf("[%lu]: ", i);
        scanf("%d", &arr[i]);
    }
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

void prodotto(const int vettore[], const int matrice[][COLONNE], int prodotto[], size_t num_righe, size_t num_colonne)
{
    for(size_t j = 0; j < num_colonne; j++) {
        int somma = 0;
        for (size_t i = 0; i < num_righe; i++) {
            somma += vettore[i] * matrice[i][j]; 
        }
        prodotto[j] = somma;
    }
}

void stampa_vettore(const int arr[], size_t dim) {
    for (size_t i = 0; i < dim; i++) {
        printf("%d\t", arr[i]);
    }
    puts("");
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