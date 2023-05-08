#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int main() {
    char str[MAXLINE + 1], str2[MAXLINE + 1];

    puts("Inserisci stringa");
    scanf(" %100[^\n]", str);

    puts("Inserisci stringa da cercare: ");
    scanf(" %100[^\n]", str2);

    char* posizione_stringa = strstr(str, str2);
    char* posizione_primo_elemento = strchr(str, str[0]);
    char* posizione_terminatore = strchr(str, '\0');

    unsigned int indice_terminatore = (long unsigned int)(posizione_terminatore - posizione_primo_elemento);

    unsigned int indice_cercato = (long unsigned int)(posizione_stringa - posizione_primo_elemento);

    if (indice_cercato > indice_terminatore) {
        puts("Il pattern cercato non è nella stringa");
    }
    else {
        printf("La stringa cercata inizia all'indice: %u\n", indice_cercato);
    }

    return 0;
}