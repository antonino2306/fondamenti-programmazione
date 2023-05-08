#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int main() {
    char str[MAXLINE + 1], carattere;

    puts("Inserisci stringa");
    scanf(" %100[^\n]", str);

    char* posizione_primo_carattere = strchr(str, str[0]);
    char* posizione_terminatore = strchr(str, '\0');

    unsigned int indice_terminatore = (long unsigned int)(posizione_terminatore - posizione_primo_carattere);
    // printf("Indice terminatore: %u", indice_terminatore);
    
    puts("Inserisci carattere da cercare");
    scanf(" %c", &carattere);

    // Restituisce l'indirizzo di memoria del carattere cercato
    char* posizione_cercata = strchr(str, carattere);


    unsigned int differenza_posizione = (long unsigned int)(posizione_cercata - posizione_primo_carattere);
    if (differenza_posizione > indice_terminatore) {
        puts("Il carattere non è nella stringa");
    }
    else {
        printf("Prima posizione in cui è stato trovato il carattere: %u\n", differenza_posizione);
    }
    return 0;
}