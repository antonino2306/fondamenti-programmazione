#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// Funzioni dell'interfaccia utente
void stampa_menu_principale() {
    puts("Premi 1 per aggiungere una nuova promozione");
    puts("Premi 2 per sfogliare le promozioni");
    puts("Premi 3 per eliminare una promozione");
    puts("Premi 4 per cercare il prodotto con lo sconto più alto");
    puts("Premi 0 per uscire");
    printf("> ");
}
void stampa_sottomenu() {
    puts("Premi A per andare indietro");
    puts("Premi D per andare avanti");
    puts("Premi B per tornare al menu precedente");
    printf("> ");
}


Prodotto *aggiungi_promozione(Prodotto *volantino, char nome[], float prezzo, unsigned int sconto) {

    if (volantino == NULL) {
        volantino = (Prodotto*)malloc(sizeof(Prodotto));

        if (volantino != NULL) {

            strcpy(volantino->nome, nome);
            volantino->prezzo = prezzo;
            volantino->percentuale_sconto = sconto;
            volantino->succ = NULL;
            volantino->prec = NULL;

        }
    }
    else {

        Prodotto *nuovo = NULL;
        nuovo = (Prodotto*)malloc(sizeof(Prodotto));

        if (nuovo != NULL) {

            strcpy(nuovo->nome, nome);
            nuovo->prezzo = prezzo;
            nuovo->percentuale_sconto = sconto;

            nuovo->succ = volantino;
            volantino->prec = nuovo;
            nuovo->prec = NULL;
            volantino = nuovo;
        }

    }

    return volantino;

}

void elimina_volantino(Prodotto *volantino) {

    if (volantino != NULL) {
        Prodotto *tmp = volantino;
        volantino = volantino->succ;
        free(tmp);
    }

}

void stampa_volantino(Prodotto *volantino) {

    while (volantino != NULL) {
        printf("%s %.2f %u%%\n", volantino->nome, volantino->prezzo, volantino->percentuale_sconto);
        volantino = volantino->succ;
    }

}

void sfoglia_volantino(Prodotto *volantino) {

    if (volantino != NULL) {

        stampa_sottomenu();
        char input;
        short int torna_indietro = 0;

        do {
            printf("%s %.2f %u%%\n", 
                volantino->nome, volantino->prezzo, volantino->percentuale_sconto);
            scanf(" %c", &input);

            switch (input) {
                case 'a': case 'A':
                    if (volantino->prec != NULL) {
                        volantino = volantino->prec;
                        // printf("%s %.2f %u%%\n",
                        //     volantino->nome, volantino->prezzo, volantino->percentuale_sconto);
                    }
                    else {
                        puts("Sei all'inizio del volantino vai avanti");
                    }
                    break;
                
                case 'd': case 'D':
                    if (volantino->succ != NULL) {
                        volantino = volantino->succ;
                        // printf("%s %.2f %u%%\n",
                        //     volantino->nome, volantino->prezzo, volantino->percentuale_sconto);
                    } 
                    else {
                        puts("Volantino terminato torna indietro");
                    }
                    break;

                case 'b': case 'B':
                    torna_indietro = 1; 
                
                default: break;
            }
        }
        while(!torna_indietro); 
    }
    else {
        puts("Volantino vuoto");
    }

}

Prodotto *elimina_promozione(Prodotto *volantino, char nome[]) {
    
    if (volantino != NULL) {

        if (strcmp(volantino->nome, nome) == 0) {

            Prodotto *tmp = volantino;
            volantino = volantino->succ;
            if (volantino != NULL) {
                volantino->prec = NULL;
            }

        }
        else {
            Prodotto *scorri_volantino = volantino;

            if (scorri_volantino != NULL && strcmp(volantino->nome, nome) != 0) {
                scorri_volantino = scorri_volantino->succ;
            }

            if (scorri_volantino != NULL) {
                Prodotto *tmp = scorri_volantino;
                if (scorri_volantino->prec != NULL) {
                    scorri_volantino->prec->succ = scorri_volantino->succ;
                }
                if (scorri_volantino->succ != NULL) {
                    scorri_volantino->succ->prec = scorri_volantino->prec;
                }
                free(tmp);
            }
        }
    }
    else {
        puts("Volantino vuoto");
    }

    return volantino;
}

void trova_sconto_massimo(Prodotto *volantino) {

    if (volantino != NULL) {

        Prodotto *massimo = volantino;

        while (volantino != NULL) {

            if (volantino->percentuale_sconto > massimo->percentuale_sconto) {
                massimo = volantino;
            }
            volantino = volantino->succ;

        }

        printf("Il prodotto con lo sconto massimo è %s con il %u%% di sconto\n", massimo->nome, massimo->percentuale_sconto);
        
    }
    else {
        puts("Volantino vuoto");
    }

}