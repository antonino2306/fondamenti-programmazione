#include <stdio.h>
#include "functions.h"



int main() {
    unsigned int quantità_sale = 0, flag = 1;
    unsigned const int capienza_barattolo = 1500;
    unsigned int scelta_utente;
    do {
        stampa_schermata_iniziale();
        scanf("%u", &scelta_utente);

        switch (scelta_utente) {
            
            case 1: 
                info_barattolo(quantità_sale, capienza_barattolo);
                break;
            
            case 2:
                quantità_sale = usa_sale(quantità_sale);
                break;
            
            case 3:
                quantità_sale = riempi_barattolo(quantità_sale, capienza_barattolo);
                break;
            
            case 4:
                flag = 0;
                break;

            default:
                break;

        }
    } while (flag);
}

