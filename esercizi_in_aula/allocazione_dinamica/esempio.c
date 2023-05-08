#include <stdio.h>
#include <stdlib.h>

void riempi_matrice(int** matrice, size_t righe, size_t colonne);
void stampa_matrice(int** matrice, size_t righe, size_t colonne);
void ridimensiona_colonne(int** matrice, size_t righe, size_t *colonne);
void ridimensiona_righe(int** matrice, size_t *righe, size_t colonne);

// todo modificare le funzioni in modo che liberino memoria se riduco la matrice

int main(void){
    size_t righe, colonne;
    int **matrice;
    
    printf("Inserire numero di righe\n");
    scanf("%lu", &righe);

    printf("Inserire il numero di colonne\n");
    scanf("%lu", &colonne);

    // Alloco lo spazio per le righe
    matrice = (int**)calloc(righe, sizeof(int));

    // Alloco spazio per le colonne
    for (size_t i = 0; i < righe; i++) {
        matrice[i] = (int*)calloc(colonne, sizeof(int));
    }

    riempi_matrice(matrice, righe, colonne);

    stampa_matrice(matrice, righe, colonne);

    ridimensiona_righe(matrice, &righe, colonne);

    ridimensiona_colonne(matrice, righe, &colonne);
    
    // for (size_t i = 0; i < colonne; i++) {
    //     matrice[righe - 1][i] = 12; 
    // }
     
    stampa_matrice(matrice, righe, colonne);

    for (size_t i = 0; i < righe; i++) {
        free(matrice[i]);
    }

    free(matrice);

}

void riempi_matrice(int **matrice, size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            printf("[%ld][%ld] = ", i, j);
            scanf("%d", (*(matrice + i) + j));
        }
    }
}

void stampa_matrice(int **matrice, size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            printf("%d\t", *(*(matrice + i) + j));
        }
        puts("");
    }
}

void ridimensiona_colonne(int **matrice, size_t righe, size_t *colonne)
{
    size_t nuove_colonne;
    
    printf("Inserisci il nuovo numero di colonne ");
    scanf("%lu", &nuove_colonne);
    
    //* Faccio il realloc solo se aumento le colonne
    //* Se le diminuisco mi limito a diminuire solo la variabile
    //* Comunque alla fine del programma la free sulle righe andrà a liberare anche quello spazio
    
    if (nuove_colonne > *colonne) {

        for (size_t i = 0; i < righe; i++) {
            matrice[i] = (int*)realloc(matrice[i], nuove_colonne*sizeof(int));
        }
    
    }

    *colonne = nuove_colonne;
    
}

void ridimensiona_righe(int **matrice, size_t *righe, size_t colonne)
{
    size_t nuove_righe;
    printf("Inserisci il nuovo numero di righe: ");
    scanf("%lu", &nuove_righe);
    
    matrice = (int**)realloc(matrice, nuove_righe * sizeof(int));

    if (nuove_righe < *righe) {
        for (size_t i = nuove_righe; i < *righe; i++) {
            free(matrice[i]);
        }
    }
    else {

        for (size_t i = *righe; i < nuove_righe; i++) {
            matrice[i] = (int*)calloc(colonne, sizeof(int));
        }

    }

    *righe = nuove_righe;

}
