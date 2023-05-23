#include <stdio.h>
#include <stdlib.h>
#define MAXLENGHT 30

//? Avrei potuto creare una struct solo per gli ingredienti
struct pietanza {

    char nome[MAXLENGHT];
    unsigned int num_ingredienti;
    char **ingredienti;
    unsigned int *dosi;
    unsigned int tempo_cottura;
    char tipo_piatto[10];

};

typedef struct pietanza Pietanza;

//* Prototipi delle funzioni

//? Funzioni di stampa
void stampa_menu();
void stampa_ricette(const Pietanza* const array, size_t num_p);

//? Funzioni di inizializzazione dei dati
void inserisci_ricette(Pietanza *array, size_t num_p, size_t indice_iniziale);
void inserisci_ingredienti(char **ingredienti, unsigned int* dosi, size_t num_i);


void libera_memoria(Pietanza *array, size_t num_p);


void aggiungi_ricetta(Pietanza **array, size_t *num_p);

//? Funzioni di ricerca dati
void ricerca_ingredienti(const Pietanza *array, size_t num_pietanze);
void ricerca_per_tipologia(const Pietanza *array, size_t num_pietanze);
void ricerca_per_ingredienti(const Pietanza *array, size_t num_pietanze);
void ricerca_per_tempo_cottura(const Pietanza *array, size_t num_pietanze);