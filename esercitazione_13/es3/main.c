#include "../es2/header.h"
#include "file_functions.h"

//? per compilare oltre a main dobbiamo includere:
//? file_functions.c ../es2/functions.c

int main(int argc, char *argv[]) {
    
    Pietanza *ricettario;
    size_t num_pietanze;

    FILE *fp;

    if (argc < 2) {
        puts("Inserisci percorso file");
        return -1;
    }

    if ((fp = fopen(argv[1], "a+")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    num_pietanze = lunghezza_attuale_ricettario(fp);

    printf("numero ricette nel file: %lu\n", num_pietanze);

    if (num_pietanze > 0) {
        
        ricettario = (Pietanza*)calloc(num_pietanze, sizeof(Pietanza));

    }


    carica_ricette_da_file(fp, ricettario, num_pietanze, 0);
    stampa_ricette(ricettario, num_pietanze);

    char input;

    do {

        stampa_menu();
        scanf(" %c", &input);

        switch(input) {
            
            case 'a':
                aggiungi_ricetta(&ricettario, &num_pietanze);
                scrivi_ricetta_su_file(fp, ricettario[num_pietanze - 1]);
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
    fclose(fp);
    return 0;
}