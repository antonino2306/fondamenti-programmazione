#define L_MATRICOLA 7
#define MAXLENGHT 30
#include <stdio.h>


struct _studente {
    char matricola[L_MATRICOLA + 1];
    char cognome[MAXLENGHT];
    char nome[MAXLENGHT];
    unsigned int cfu;
    struct _studente *next;
};

typedef struct _studente Studente;

Studente *init_lista(FILE *fp);
void libera_lista(Studente *lista);
void stampa_lista(Studente *lista);

//? Funzioni che usa l'utente
void stampa_menu();
void cerca_per_matricola(Studente *lista, const char mat[]);
void cerca_per_cfu(Studente *lista, unsigned int n_cfu);
void filtra_per_cognome(Studente *lista, char lettera_iniziale, char lettera_finale);