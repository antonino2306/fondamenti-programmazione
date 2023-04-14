#include <stdio.h>
#include "functions.h"

const float PI = 3.14;

int main() {

    char input_utente;
    int esegui = 1;

    do {

        stampa_schermata_iniziale();
        scanf("%c", &input_utente);
        
        switch (input_utente) {
        
            case 'a':
                calcola_area_cerchio();
                break;

            case 's':
                somma_n_numeri();
                break;

            case 'b':
                calcola_bmi();
                break;

            case 'q':
                esegui = 0;
                break;

            default:
                printf("Hai inserito una lettera sbagliata riprova");
                break;
        }

        scanf("%c", &input_utente);

    }while (esegui);




    return 0;
}