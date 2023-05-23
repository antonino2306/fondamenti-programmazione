#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void crea_array(unsigned int *arr, size_t dim) {
    arr = (unsigned int*)calloc(dim, sizeof(unsigned int));
}

void riempi_array(Pietanza *arr, size_t dim, size_t *num_ingredienti) {

    for (size_t i = 0; i < dim; i++) {
        
        printf("Inserisci il nome della pietanza: ");
        scanf(" %30[^\n]", (arr + i) -> nome);

        printf("Inserisci il numero di ingredienti: ");
        scanf("%lu", num_ingredienti);

        crea_array((arr + i)->dosi, *num_ingredienti);
        
        inserisci_ingredienti((arr + i)->ingredienti, *num_ingredienti, (arr + i)->dosi);

        printf("Inserisci il tempo di cottura in minuti: ");
        scanf("%u", &((arr + i)->tempo_cottura));

        printf("Inserisci il tipo di piatto: ");
        scanf(" %10[^\n]", (arr + i)->tipo_piatto);

    }
}

void inserisci_ingredienti(char **arr_ingredienti, size_t dim, unsigned int *arr_dosi) {

    arr_ingredienti = (char**)calloc(dim, sizeof(char));
    
    for (size_t i = 0; i < dim; i++) {
        arr_ingredienti[i] = (char*)calloc(MAXLENGHT, sizeof(char));
        printf("Inserisci l'ingrediente: ");
        scanf(" %30[^\n]", *(arr_ingredienti + i));
        // printf("Inserisci la dose in grammi: ");
        // scanf("%u", (arr_dosi + i));
    }
    
}

void stampa_lista_pietanze(Pietanza *arr, size_t dim, size_t dim_ingredienti) {
    for (size_t i = 0; i < dim; i++) {

        printf("Nome: %s\n", (arr + i)->nome);
        stampa_ingredienti((arr + i)->ingredienti, dim_ingredienti);
        printf("Tempo di cottura: %u minuti\n", (arr+i)->tempo_cottura);
        printf("Tipo di piatto: %s\n", (arr+i)->tipo_piatto);
        puts("------------------------------------------");

    }
}

void libera_memoria(Pietanza *arr, size_t dim, size_t dim_ingredienti) {
    
    for (size_t i = 0; i < dim_ingredienti; i++) {
        free((arr + i)->ingredienti[i]);
        free((arr + i)->dosi);
    }

    free(arr);

}

void stampa_ingredienti(char **arr_ingredienti, size_t dim_ingredienti) {
    printf("Ingredienti: ");
    for (size_t i = 0; i < dim_ingredienti; i++) {
        printf("%s 0 g\t", *(arr_ingredienti + i));
    }
    puts("");
}