#include <stdio.h>
#include <stdlib.h>

void riempi_matrice(int **arr, size_t dimensione);
short int simmetrica(int **arr, size_t dimensione);

int main() {
    size_t dimensione;

    puts("Inserisci la dimensione della matrice");
    scanf("%lu", &dimensione);

    int **matrice = (int**)calloc(dimensione, sizeof(int));

    for (size_t i = 0; i < dimensione; i++) {
        matrice[i] = calloc(dimensione, sizeof(int));
    }

    riempi_matrice(matrice, dimensione);

    if (simmetrica(matrice, dimensione)) {
        puts("La matrice è simmetrica");
    }
    else {
        puts("La matrice non è simmetrica");
    }

    for (size_t i = 0; i < dimensione; i++) {
        free(matrice[i]);
    }

    free(matrice);

    return 0;
}

void riempi_matrice(int **arr, size_t dimensione)
{
    for (size_t i = 0; i < dimensione; i++) {
        for (size_t j = 0; j < dimensione; j++) {
            printf("[%lu][%lu] = ", i, j);
            scanf("%d", (*(arr + i) + j));
        }
    }
}

short int simmetrica(int **arr, size_t dimensione)
{
    for (size_t i = 0; i < dimensione; i++) {
        for (size_t j = 0; j < dimensione; j++) {
            if (i != j) {
                if (*(*(arr + i)+j) != *(*(arr + j)+i)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
