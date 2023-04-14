#include <stdio.h>
#include "functions.h"


int main() {
    unsigned int borsellino = 0, flag = 1;

    printf("Quanti soldi vuoi inserire nel borsellino: ");
    scanf("%u", &borsellino);

    do {
        unsigned int scelta_utente;
        
        stampa_istruzioni();
        scanf("%u", &scelta_utente);

        switch (scelta_utente) {
            
            case 1:
                borsellino = prelievo(borsellino);
                break;
            
            case 2:
                borsellino = deposito(borsellino);
                break;

            case 3:
                visualizza_saldo(borsellino);
                break;
            
            case 4: 
                flag = 0;
                break;
            
            default: 
                break;

        }
    } while (flag);

    return 0;
}