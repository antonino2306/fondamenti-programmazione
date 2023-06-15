#include <stdio.h>

unsigned long int calcolo_interesse(unsigned long int imporot, unsigned int anni, unsigned int perc_interesse);

int main() {

    unsigned long int importo;
    
    puts("Inserisci l'importo iniziale");
    scanf("%lu", &importo);

    unsigned int anni;
    puts("Inserisci il numero di anni");
    scanf("%u", &anni);

    unsigned int interesse_annuo;

    puts("Inserisci la percentuale di interesse annua");
    scanf("%u", &interesse_annuo);

    printf("L'imporot di denaro dopo %u anni è di %lu\n", anni, calcolo_interesse(importo, anni, interesse_annuo));
}

unsigned long int calcolo_interesse(unsigned long int importo, unsigned int anni, unsigned int perc_interesse)
{

    if (anni == 0) {
        return importo;
    }
    else {
        return importo * perc_interesse / 100 + calcolo_interesse(importo, anni-1, perc_interesse);
    }

}
