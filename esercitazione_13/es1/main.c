#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main() {

    Pietanza *lista_pietanze;
    size_t numero_pietanze, numero_ingredienti;

    puts("Quante pietanze vuoi inserire: ");
    scanf(" %lu", &numero_pietanze);

    lista_pietanze = (Pietanza*)calloc(numero_pietanze, sizeof(Pietanza));

    riempi_array(lista_pietanze, numero_pietanze, &numero_ingredienti);
    printf("numero ingredienti: %lu\n", numero_ingredienti);
    stampa_lista_pietanze(lista_pietanze, numero_pietanze, numero_ingredienti);

    libera_memoria(lista_pietanze, numero_pietanze, numero_ingredienti);
}