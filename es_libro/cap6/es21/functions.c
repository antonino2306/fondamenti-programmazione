#include <stdio.h>
#include "variables.h"

void stampa_menu() {
    printf("Prenota un biglietto aereo:\n\n");
    printf("Premi 1 per la prima classe\n");
    printf("Premi 2 per l'economy\n");
    printf("> ");
}

void stampa_carta_imbarco(unsigned int posto) {
    printf("Carta di imbarco del volo: ");
    printf("Sei seduto al posto numero %u\n", posto);
}

int controlla_posti(unsigned int mappa[], unsigned int start, unsigned int end) {
    for (size_t i = start; i < end; i++) {
        if (mappa[i] == 0) {
            return i;
        }
    }
    return -1;
}

void assegna_posto(unsigned int mappa[], unsigned int size, unsigned int scelta_utente) {
    int posto;

    switch (scelta_utente) {
        case 1: 
            posto = controlla_posti(mappa, 0, 5);
            if (posto == -1) {
                int risposta;
                printf("Vuoi un posto in seconda classe (premi 2): ");
                scanf("%d", &risposta);

                if (risposta == 2) {
                    assegna_posto(mappa, NUMERO_POSTI, risposta);
                }
                else {
                    printf("Aspetta il prossimo volo\n");
                }

            }
            else {
                mappa[posto] = 1;
                stampa_carta_imbarco(posto);
            }
            break;
        
        case 2: 
            posto = controlla_posti(mappa, 5, 10);
            if (posto == -1) {
                printf("Seconda classe piena\n");
            }
            else {
                mappa[posto] = 1;
                stampa_carta_imbarco(posto);
            }
            break;
        
        default: break;
    }
}