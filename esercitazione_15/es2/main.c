#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main() {

    Prodotto *volantino = NULL;
    int input;

    do {

        stampa_menu_principale();
        scanf(" %d", &input);

        char nome[MAXLENGHT];
        float prezzo;
        unsigned int sconto;

        switch (input)
        {
        case 1:
            puts("Inserisci il nome del prodotto il prezzo e la percentuale di sconto");
            scanf(" %29s %f %u", nome, &prezzo, &sconto);
            volantino = aggiungi_promozione(volantino, nome, prezzo, sconto);
            break;

        case 2:
            sfoglia_volantino(volantino);
            break;

        case 3:
            puts("Inserisci il nome del prodotto da eliminare");
            scanf(" %29s", nome);
            volantino = elimina_promozione(volantino, nome);
            break;
        
        case 4:
            trova_sconto_massimo(volantino);
            break;
        
        default:
            break;
        }

    } while (input != 0);
    
    elimina_volantino(volantino);
    return 0;
}