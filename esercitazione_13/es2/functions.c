//* Definizione delle funzioni
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


extern void stampa_menu() {
    puts("Scegli l'operazione da effettuare: ");
    puts("1. Premi a per inseririre una nuova pietanza");
    puts("2. Premi b per visualizzare gli ingredienti di una pietanza");
    puts("3. Premi c per cercare pietanze in base alla tipologia");
    puts("4. premi d per cercare le pietanze per ingrediente");
    puts("5. premi e per cercare in base al tempo di cottura");
    puts("6. premi q per uscire");
}

extern void stampa_ricette(const Pietanza* const array, size_t num_p) {
    
    for (size_t i = 0; i < num_p; i++) {

        puts("-----------------------------------------------");
        printf("Nome: %s\n", (array+i)->nome);

        puts("Ingredienti:");
        for (size_t j = 0; j < (array+i)->num_ingredienti; j++) {

            printf("\t%s %u g\n", (array+i)->ingredienti[j], (array+i)->dosi[j]);

        } 

        printf("Tempo di cottura: %u minuti\n", (array+i)->tempo_cottura);
        printf("Tipo di piatto: %s\n", (array+i)->tipo_piatto);

        puts("-----------------------------------------------");

    }
}

extern void libera_memoria(Pietanza *array, size_t num_p) {

    for (size_t i = 0; i < num_p; i++) {
        
        for (size_t j = 0; j < (array+i)->num_ingredienti; j++) {
            free((array+i)->ingredienti[j]);
        }

        free((array+i)->ingredienti);
        free((array+i)->dosi);

    }

    free(array);

}

extern void inserisci_ingredienti(char **ingredienti, unsigned int* dosi, size_t num_i) {

    for (size_t i = 0; i < num_i; i++) {

        ingredienti[i] = (char*)calloc(MAXLENGHT, sizeof(char));
        printf("Ingrediente: ");
        scanf(" %30[^\n]", ingredienti[i]);

        printf("Dose: ");
        scanf(" %u", &dosi[i]);

    }

}

extern void inserisci_ricette(Pietanza *array, size_t num_p, size_t indice_iniziale) {
    
    for (size_t i = indice_iniziale; i < num_p; i++) {

        printf("Inserisci il nome del piatto: ");
        scanf(" %30[^\n]", (array+i)->nome);

        printf("Inserisci il numero degli ingredienti: ");
        scanf("%u", &((array+i)->num_ingredienti));

        (array+i)->ingredienti = (char**)calloc((array+i)->num_ingredienti, sizeof(char));
        (array+i)->dosi = (unsigned int*)calloc((array+i)->num_ingredienti, sizeof(unsigned int));

        inserisci_ingredienti((array+i)->ingredienti, (array+i)->dosi, (array+i)->num_ingredienti);

        printf("Inserisci il tempo di cottura in minuti: ");
        scanf("%u", &((array+i)->tempo_cottura));

        printf("Inserisci il tipo di piatto: ");
        scanf(" %10[^\n]", (array+i)->tipo_piatto);

    }

}

//? Prende in input l'indirizzo del ricettario perché realloc cambia l'indirizzo di memoria!!! 
extern void aggiungi_ricetta(Pietanza **array, size_t *num_p) {
    
    (*num_p)++;
    
    // Inserisci la prima pietanza
    if (*num_p == 1) {
        *array = (Pietanza*)calloc(*num_p, sizeof(Pietanza));
    }
    else {
        // Aggiungi una pietanza
        *array = (Pietanza*)realloc(*array, (*num_p)*sizeof(Pietanza));
    }

    // Dato che ho l'indirizzo del ricettario usando *array passo il ricettario
    inserisci_ricette(*array, *num_p, *num_p - 1);


}

extern void ricerca_ingredienti(const Pietanza *array, size_t num_pietanze) {

    char str_da_cercare[MAXLENGHT];

    puts("Inserisci nome pietanza da cercare: ");
    scanf(" %30[^\n]", str_da_cercare);

    for (size_t i = 0; i < num_pietanze; i++) {

        if (strcmp((array + i)->nome, str_da_cercare) == 0) {
            puts("Ingredienti:");
            for (size_t j = 0; j < (array+i)->num_ingredienti; j++) {

                printf("\t%s %u g\n", (array + i)->ingredienti[j], (array+i)->dosi[j]);

            }

        }

    }
}

extern void ricerca_per_tipologia(const Pietanza *array, size_t num_pietanze) {
    
    char str_da_cercare[10];

    puts("Inserisci un tipo di pasto (esempio: primo, secondo...): ");
    scanf(" %10[^\n]", str_da_cercare);

    for (size_t i = 0; i < num_pietanze; i++) {

        if (strcmp((array + i)->tipo_piatto, str_da_cercare) == 0) {

            printf("- %s\n", (array + i)->nome);

        }

    }

}

extern void ricerca_per_ingredienti(const Pietanza *array, size_t num_pietanze) {

    char str_da_cercare[MAXLENGHT];

    puts("Inserisci ingrediente per effettuare la ricerca: ");
    scanf(" %30[^\n]", str_da_cercare);


    for (size_t i = 0; i < num_pietanze; i++) {
        
        int trovato = 0;

        for (size_t j = 0; j < (array+i)->num_ingredienti && !trovato; j++) {

            if (strcmp((array+i)->ingredienti[j], str_da_cercare) == 0) {
                printf("- %s\n", (array + i)->nome);
                trovato = 1;
            }

        }

    }

}

extern void ricerca_per_tempo_cottura(const Pietanza *array, size_t num_pietanze) {
    
    unsigned int tempo_cercato;
    
    puts("Inserisci il tempo di cottura per effettuare la ricerca: ");
    scanf("%u", &tempo_cercato);

    puts("Risultati:");
    for (size_t i = 0; i < num_pietanze; i++) {

        if ((array + i)->tempo_cottura < tempo_cercato) {
            printf("- %s\n", (array+i)->nome);
        }
    }

}