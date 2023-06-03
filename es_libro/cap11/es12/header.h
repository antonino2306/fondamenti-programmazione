#include <stdio.h>
#define MAXLENGHT 50

struct _attrezzo {
    unsigned int record;
    char nome[MAXLENGHT];
    unsigned int quantita;
    float prezzo;
};

typedef struct _attrezzo Attrezzo;

void stampa_menu();

void esegui_comando(char input, FILE *fp);

//? Funzioni per operare sul file
void crea_nuovo_record(FILE *fp);
void modifica_record(FILE *fp);
void elimina_record(FILE *fp);
void stampa_lista_record(FILE *fp);
unsigned int conta_record(FILE *fp);