#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

//TODO: lettura iniziale dei dati degli studenti da file
int main(int argc, char *argv[]) {

    Studente *lista = NULL;
    FILE *fp = NULL;
    int input;
    
    if (argc < 2) {
        puts("Inserisci percorso file");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    char tmp_matricola[MAT + 1];
    while (fscanf(fp, "%7[^,]", tmp_matricola) != EOF) {
        Studente tmp = leggi_dati_da_file(fp);
        strcpy(tmp.matricola, tmp_matricola);
        lista = inserisci_elemento(lista, tmp.matricola, tmp.nome, tmp.cognome);
    }

    do {
        stampa_menu();
        scanf(" %d", &input);

        switch (input) {

            case 1:
                Studente tmp = leggi_dati();
                lista = inserisci_elemento(lista, tmp.matricola, tmp.nome, tmp.cognome);
                break;
            case 2:
                // la funzione per cancellare un elemento in base al numero
                // di matricola rimane la stessa. Solo che prima di liberare
                // l'elemento devo liberare la memoria allocata per nome e cognome
                break;
            case 3:
                // La funzione di ricerca rimane la stessa
                break;
            default:
                break;

        }
    } while (input != 4);

    stampa_lista(lista);
    elimina_lista(lista);
    fclose(fp);
    return 0;
}