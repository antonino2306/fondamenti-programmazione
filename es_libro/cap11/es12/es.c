#include "header.h"


int main() {

    FILE *fp;

    if ((fp = fopen("hardware.txt", "a+")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }


    char input;

    do {

        stampa_menu();
        scanf(" %c", &input);
        esegui_comando(input, fp);
    
    } while (input != 'q');


    fclose(fp);
    return 0;
}
