#include <stdio.h>

#define RIGHE 3
#define COLONNE 3

void inserisci_valori(int arr[][COLONNE], size_t num_righe, size_t num_colonne);
void stampa_matrice(const int arr[][COLONNE], size_t num_righe, size_t num_colonne);
void somma(const int arr1[][COLONNE], const int arr2[][COLONNE], int arr3[][COLONNE], size_t num_righe, size_t num_colonne);

int main() {
    int A[RIGHE][COLONNE] = {0};
    int B[RIGHE][COLONNE] = {0};
    int C[RIGHE][COLONNE] = {0};

    puts("Inserisci valori matrice A");
    inserisci_valori(A, RIGHE, COLONNE);
    puts("Inserisci valori matrice B");
    inserisci_valori(B, RIGHE, COLONNE);

    puts("Matrice A");
    stampa_matrice(A, RIGHE, COLONNE);
    
    puts("Matrice B");
    stampa_matrice(B, RIGHE, COLONNE);

    puts("Somma di A e B");
    somma(A, B, C, RIGHE, COLONNE);
    stampa_matrice(C, RIGHE, COLONNE);

    return 0;
}

void inserisci_valori(int arr[][COLONNE], size_t num_righe, size_t num_colonne)
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
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
}

void somma(const int arr1[][COLONNE], const int arr2[][COLONNE], int arr3[][COLONNE], size_t num_righe, size_t num_colonne)
{
    for (size_t i = 0; i < num_righe; i++) {
        for (size_t j = 0; j < num_colonne; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}
