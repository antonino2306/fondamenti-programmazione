#define MAT 7
#define MAXLENGHT 100

struct studente {
    char matricola[MAT + 1];
    char *nome;
    char *cognome;
    struct studente *succ;
    struct studente *prec;
};

typedef struct studente Studente;
void stampa_menu();
Studente leggi_dati();
Studente *inserisci_elemento(Studente *lista, char matricola[], char *nome, char *cognome);
void elimina_lista(Studente *lista);
void stampa_lista(Studente *lista);
Studente leggi_dati_da_file(FILE *fp);