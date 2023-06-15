#include <stdio.h>
#include <stdlib.h>

void riempi_matrice(int **mat, size_t righe, size_t colonne);
void cerca_rumori(int **mat, int **mat_rumori, size_t righe, size_t colonne);
void stampa_matrice(const int** matrice, size_t righe, size_t colonne);

int main() {
    size_t righe, colonne;

    puts("Inserisci il numero di righe e di colonne della matrice");
    scanf("%lu %lu", &righe, &colonne);

    int **matrice = (int**)calloc(righe, sizeof(int));

    for (size_t i = 0; i < righe; i++) {
        matrice[i] = (int*)calloc(colonne, sizeof(int));
    }

    riempi_matrice(matrice, righe, colonne);

    int **mat_rumori = (int**)calloc(righe, sizeof(int));
     
    for (size_t i = 0; i < righe; i++) {
        mat_rumori[i] = (int*)calloc(colonne, sizeof(int));
    }

    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            mat_rumori[i][j] = 0;
        }
    }

    cerca_rumori(matrice, mat_rumori, righe, colonne);

    stampa_matrice(mat_rumori, righe, colonne);

    for (size_t i = 0; i < righe; i++) {
        free(matrice[i]);
        free(mat_rumori[i]);
    }
    

    free(matrice);
    free(mat_rumori);

}

void riempi_matrice(int **mat, size_t righe, size_t colonne) {
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            printf("[%lu][%lu]: ", i, j);
            scanf("%d", *(mat + i) + j);
        }
    }
}

void cerca_rumori(int **mat, int **mat_rumori, size_t righe, size_t colonne)
{
    int k, m;

    for (int i = 0; i < righe; i++) {

        for (int j = 0; j < colonne; j++) {
            
            int somma = 0;
            unsigned int conta = 0;

            k = i - 1;
            while (k <= i + 1) {
                
                if (k >= 0 && k < righe) {
                    
                    m = j - 1;

                    while (m <= j + 1) {

                        if (m >= 0 && m < colonne) {
                            if (!(m == j && k == i)) {

                                somma += mat[k][m];
                                conta++;
                            }
                        }
                        m++;
                    }

                   
                }
                k++;

            }
            
            int media = somma / conta;
            if (abs(media - *(*(mat + i)+ j)) >= 2) {
                *(*(mat_rumori + i) + j) = 1;
            }
            else {
                *(*(mat_rumori + i) + j) = 0;
            }
        }
    }
}

void stampa_matrice(const int **matrice, size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            printf("%d\t", *(*(matrice + i) + j));
        }
        puts("");
    }
}
