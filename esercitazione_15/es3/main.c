#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[]) {

    FILE *fp;

    if (argc < 2) {
        puts("Inserisci il percorso del file");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    Studente *head = NULL;
    head = init_lista(fp);
    stampa_lista(head);

    int input;

    do {

        stampa_menu();
        scanf("%d", &input);

        switch (input) {
            case 1:
                char mat[L_MATRICOLA + 1];
                puts("Inserisci la matricola");
                scanf(" %7s", mat);
                cerca_per_matricola(head, mat);
                break;

            case 2:
                unsigned int cfu;
                puts("Inserisci il numero di cfu");
                scanf("%u", &cfu);
                cerca_per_cfu(head, cfu);
                break;
            
            case 3:
                char l_iniziale, l_finale;
                puts("Inserisci l'intervallo");
                scanf(" %c %c", &l_iniziale, &l_finale);
                filtra_per_cognome(head, l_iniziale, l_finale);
                break;
            
            default:
                break;
        }

    } while (input != 4);
 
    fclose(fp);
    return 0;
}