#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGHT 50
#define COD_FISCALE 16

struct data
{
    unsigned int giorno;
    unsigned int mese;
    unsigned int anno;
};

struct indirizzo
{
    char via[MAXLENGHT+1];
    unsigned int civico;
};


struct persona {

    char *nome;
    char *cognome;
    struct data nascita;
    char *luogo_nascita;
    struct indirizzo domicilio;
    char codice_fiscale[COD_FISCALE+1];
    struct persona *succ;
    struct persona *prec;

};

typedef struct persona Persona;
typedef struct data Data;
typedef struct indirizzo indirizzo;

void inserisci_dati(char nome[], char cognome[], char l_nascita[], char cf[], Data *nascita);
void scrivi_su_file(FILE *fp, char nome[], char cognome[], char l_nascita[], char cf[], Data *nascita);
void inserisci_in_lista(Persona **lista, char nome[], char cognome[], char l_nascita[], char cf[], Data *nascita);
Persona *inserisci_nel_nodo(Persona *nodo, char nome[], char cognome[], char l_nascita[], char cf[], Data *nascita);
void scorri_lista(Persona *lista);
void carica_dati_da_file(FILE *fp, Persona **lista);

int main(int argc, char *argv[]) {

    FILE *anagrafe_ptr = NULL;

    if (argc < 2) {
        puts("Inserisci il percorso del file");
        return -1;
    }

    if ((anagrafe_ptr = fopen(argv[1], "a+")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }


    char input_utente;
    char nome[MAXLENGHT+1], cognome[MAXLENGHT+1], l_nascita[MAXLENGHT+1], c_fisc[COD_FISCALE+1];
    Data data_tmp;

    Persona *lista = NULL;

    carica_dati_da_file(anagrafe_ptr, &lista);
    
    do {

        inserisci_dati(nome, cognome, l_nascita, c_fisc, &data_tmp);
        inserisci_in_lista(&lista, nome, cognome, l_nascita, c_fisc, &data_tmp);
        scrivi_su_file(anagrafe_ptr, nome, cognome, l_nascita, c_fisc, &data_tmp);
        fflush(anagrafe_ptr);

        puts("continuare ad inserire y/n:");
        scanf(" %c", &input_utente);


    } while (input_utente != 'n' && input_utente != 'N');

    fclose(anagrafe_ptr);

    scorri_lista(lista);
    return 0;
}

void inserisci_dati(char nome[], char cognome[], char l_nascita[], char cf[], Data *nascita)
{
    puts("Inserisci nome");
    scanf(" %50[^\n]", nome);

    puts("Inserisci cognome");
    scanf(" %50[^\n]", cognome);

    puts("Inserisci il luogo di nascita");
    scanf(" %50[^\n]", l_nascita);

    puts("Inserisci la data di nascita gg/mm/anno");
    scanf(" %u %u %u", &(nascita->giorno), &(nascita->mese), &(nascita->anno));

    puts("Inserisci il codice fiscale");
    scanf(" %16s", cf);
}

void scrivi_su_file(FILE *fp, char nome[], char cognome[], char l_nascita[], char cf[], Data *nascita)
{
    fprintf(fp, "%s,%s,%s,%s,%u %u %u\n",
            cf, nome, cognome, l_nascita, nascita->giorno, nascita->mese, nascita->anno);
}

void inserisci_in_lista(Persona **lista, char nome[], char cognome[], char l_nascita[], char cf[], Data *nascita)
{
    if (*lista == NULL) {
        // Creo il primo elemento della lista
        *lista = (Persona*)malloc(sizeof(Persona));

        if (*lista != NULL) {

            *lista = inserisci_nel_nodo(*lista, nome, cognome, l_nascita, cf, nascita);
            (*lista)->prec = NULL;
            (*lista)->succ = NULL;
        }

    }
    else {
        Persona *nuovo = NULL;
        nuovo = (Persona*)malloc(sizeof(Persona));

        if (nuovo != NULL) {
            nuovo = inserisci_nel_nodo(nuovo, nome, cognome, l_nascita, cf, nascita);

            nuovo->succ = *lista;
            (*lista)->prec = nuovo;
            nuovo->prec = NULL;
            *lista = nuovo;
        }

    }
}

Persona *inserisci_nel_nodo(Persona *nodo, char nome[], char cognome[], char l_nascita[], char cf[], Data *nascita)
{
    nodo->nome = (char*)malloc(sizeof(strlen(nome)+1));

        if (nodo->nome != NULL) {
            strcpy(nodo->nome, nome);
        }

        nodo->cognome = (char*)malloc(sizeof(strlen(cognome)+1));

        if (nodo->cognome != NULL) {
            strcpy((nodo)->cognome, cognome);
        }

        nodo->luogo_nascita = (char*)malloc(sizeof(strlen(l_nascita)+1));

        if (nodo->luogo_nascita != NULL) {
            strcpy(nodo->luogo_nascita, l_nascita);
        }

        strcpy(nodo->codice_fiscale, cf);
        
        nodo->nascita.giorno = nascita->giorno;
        nodo->nascita.mese = nascita->mese;
        nodo->nascita.anno = nascita->anno;

    return nodo;
}

void scorri_lista(Persona *lista)
{
    puts("Premi A per andare indietro, D per andare avanti");

    char comando;


    do {

        printf("%s %s %s\n", lista->codice_fiscale, lista->nome, lista->cognome);
        printf("> ");
        scanf(" %c", &comando);

        switch (comando)
        {
        case 'a': case 'A':
            if (lista->prec != NULL) {
                lista = lista->prec;
            }
            else {
                puts("Vai avanti");
            }
            break;
        
        case 'd': case 'D':
            if (lista->succ != NULL) {
                lista = lista->succ;
            }
            else {
                puts("Vai indietro");
            }
            break;
        
        default:
            break;
        }

    } while (comando != 'q');

}

void carica_dati_da_file(FILE *fp, Persona **lista)
{
    if (feof(fp) != 0) {
        puts("file vuoto");
    }
    else {
        char cf[COD_FISCALE+1], nome[MAXLENGHT+1], cognome[MAXLENGHT+1], l_nascita[MAXLENGHT+1];
        Data tmp;

        while (fscanf(fp, " %16[^,]", cf) != EOF) {
            fgetc(fp);

            fscanf(fp, " %50[^,]", nome);
            fgetc(fp);

            fscanf(fp, " %50[^,]", cognome);
            fgetc(fp);

            fscanf(fp, " %50[^,]", l_nascita);

            fgetc(fp);

            fscanf(fp, " %u %u %u", &(tmp.giorno), &(tmp.mese), &(tmp.anno));
            fgetc(fp);
        }

        inserisci_in_lista(lista, nome, cognome, l_nascita, cf, &tmp);

    }
}
