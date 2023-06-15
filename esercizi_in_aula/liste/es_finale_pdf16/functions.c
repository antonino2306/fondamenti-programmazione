#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
void stampa_menu()
{
    puts("Premi 1 per inserire un nuovo elemento");
    puts("Premi 2 per cancellare uno studente");
    puts("Premi 3 per cercare uno studente per matricola");
    puts("Premi 4 per uscire");
    printf("%s", "> ");
}

Studente leggi_dati_da_file(FILE *fp) {
    Studente std;
    char nome[MAXLENGHT], cognome[MAXLENGHT];
    fgetc(fp);
    fscanf(fp, "%[^,]", nome);
    fgetc(fp);
    fscanf(fp, "%[^,\n]", cognome);
    fgetc(fp);

    std.nome = (char*)malloc(sizeof(strlen(nome)));
    std.cognome = (char*)malloc(sizeof(strlen(cognome)));

    if (std.nome != NULL) {
        strcpy(std.nome, nome);
    }
    if (std.cognome != NULL) {
        strcpy(std.cognome, cognome);
    }

    
    return std;
}

Studente leggi_dati() {
    Studente std;

    char nome[MAXLENGHT], cognome[MAXLENGHT];
    puts("Inserisci matricola:");
    scanf(" %7s", std.matricola);

    puts("Inserisci nome:");
    scanf(" %99[^\n]", nome);

    puts("Inserisci cognome:");
    scanf(" %99[^\n]", cognome);

    std.nome = (char*)malloc(strlen(nome)+1);
    if (std.nome != NULL) {
        strcpy(std.nome, nome);
    }
    std.cognome = (char*)malloc(strlen(cognome)+1);
    if (std.nome != NULL) {
        strcpy(std.cognome, cognome);
    }

    return std;
}

Studente *inserisci_elemento(Studente *lista, char matricola[], char *nome, char *cognome) {

    if (lista == NULL) {
        lista = (Studente*)malloc(sizeof(Studente));

        if (lista != NULL) {
            strcpy(lista->matricola, matricola);
            lista->nome = nome;
            lista->cognome = cognome;
            lista->succ = NULL;
            lista->prec = NULL;
        }

    }
    else {
        Studente *nuovo = NULL;
        nuovo = (Studente*)malloc(sizeof(Studente));

        if (nuovo != NULL) {
            strcpy(nuovo->matricola, matricola);
            nuovo->nome = nome;
            nuovo->cognome = cognome;
            nuovo->prec = NULL;
            nuovo->succ = lista;
            lista = nuovo;
        }
    }

    return lista;

}

void elimina_lista(Studente *lista) {
    while (lista != NULL) {
        Studente *tmp = lista;
        lista = lista->succ;
        free(tmp->nome);
        free(tmp->cognome);
        free(tmp);
    }    
}

void stampa_lista(Studente *lista) {
    while (lista != NULL) {
        printf("%s %s %s\n", lista->matricola, lista->nome, lista->cognome);
        lista = lista->succ;
    }
}