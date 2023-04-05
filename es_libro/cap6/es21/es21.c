#include <stdio.h>
#include "functions.h"
#include "variables.h"




int main() {
    unsigned int mappa_posti[NUMERO_POSTI] = {0};
    int pieno = 0;
    unsigned int input_utente;

    do {
        stampa_menu();
        scanf("%u", &input_utente);
        assegna_posto(mappa_posti, NUMERO_POSTI, input_utente);

        pieno = controlla_posti(mappa_posti, 0, NUMERO_POSTI);

    } while (pieno != -1);

    printf("Aereo pieno, aspettare il prossimo\n");
    return 0;


}