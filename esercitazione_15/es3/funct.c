#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

Studente *init_lista(FILE *fp) {

    Studente *lista = NULL;
    lista = (Studente *)malloc(sizeof(Studente));

    if (lista != NULL) {
        fscanf(fp, " %s %s %s %u", 
        lista->matricola, lista->cognome, lista->nome, &(lista->cfu));
        lista->next = NULL;
    }

    
    Studente *scorri_lista = lista;
    char str_tmp[7];
    while (fscanf(fp, " %s", str_tmp) != EOF) {

        Studente *nuovo = NULL;
        nuovo = (Studente*)malloc(sizeof(Studente));

        if (nuovo != NULL) {
            strcpy(nuovo->matricola, str_tmp);
            fscanf(fp, " %s %s %u",
            nuovo->cognome, nuovo->nome, &(nuovo->cfu));
            nuovo->next = NULL;
            scorri_lista->next = nuovo;
            
        }

        scorri_lista = scorri_lista->next;

    }
    
    return lista;
}

void libera_lista(Studente *lista) {

    while (lista != NULL) {
        Studente *tmp = lista;
        lista = lista->next;
        free(tmp);
    }

}

void stampa_lista(Studente *lista) {
    
    while (lista != NULL) {
        printf("Matricola: %s\nCognome: %s\nNome: %s\ncfu: %u\n",
            lista->matricola, lista->cognome, lista->nome, lista->cfu);

        lista = lista->next;    
    }
}

void stampa_menu() {
    puts("Premi 1 per cercare uno studente per matricola");
    puts("Premi 2 per cercare tutti gli studenti con un determinato numero di cfu");
    puts("Premi 3 per filtrare per cognome gli studenti in un nuovo file");
    puts("Premi 4 per uscire");
}

void cerca_per_matricola(Studente *lista, const char mat[]) {

    while (lista != NULL) {

        if (strcmp(lista->matricola, mat) == 0) {
            printf("Studente: %s %s\n", lista->cognome, lista->nome);
            return;
        }
        lista = lista->next;

    }

}

void cerca_per_cfu(Studente *lista, unsigned int n_cfu) {
    
    while (lista != NULL) {

        if (lista->cfu == n_cfu) {
            printf("Studente %s %s\n", lista->cognome, lista->nome);
        }
        lista = lista->next;

    }

}
void filtra_per_cognome(Studente *lista, char lettera_iniziale, char lettera_finale) {
    FILE *nuovo_file;

    if ((nuovo_file = fopen("studenti.txt", "w")) == NULL) {
        puts("Errore nella crezione del file");
        return;
    }

    while (lista != NULL) {

        if (lista->cognome[0] >= toupper(lettera_iniziale) && lista->cognome[0] <= toupper(lettera_finale)) {
            fprintf(nuovo_file, "%s %s %s %u\n",
                lista->matricola, lista->cognome, lista->nome, lista->cfu);

        }
        lista = lista->next;

    }

    fclose(nuovo_file);
}