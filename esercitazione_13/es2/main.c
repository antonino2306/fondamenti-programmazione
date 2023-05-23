// #include <stdio.h>
#include "header.h"

int main() {
    
    Pietanza *ricettario;

    size_t num_pietanze;

    printf("Inserisci il numero di pietanze: ");
    scanf(" %lu", &num_pietanze);

    if (num_pietanze > 0) {
        
        ricettario = (Pietanza*)calloc(num_pietanze, sizeof(Pietanza));

    }

    inserisci_ricette(ricettario, num_pietanze, 0);

    stampa_ricette(ricettario, num_pietanze);

    char input;

    do {

        stampa_menu();
        scanf(" %c", &input);

        switch(input) {
            
            case 'a':
                aggiungi_ricetta(&ricettario, &num_pietanze);
                stampa_ricette(ricettario, num_pietanze);
                break;
            
            case 'b':
                ricerca_ingredienti(ricettario, num_pietanze);
                break;

            case 'c':
                ricerca_per_tipologia(ricettario, num_pietanze);
                break;

            case 'd':
                ricerca_per_ingredienti(ricettario, num_pietanze);
                break;

            case 'e':
                ricerca_per_tempo_cottura(ricettario, num_pietanze);
                break;
            
            default:
                break;

        }

    } while (input != 'q');

    libera_memoria(ricettario, num_pietanze);
    return 0;
}