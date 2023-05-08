#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void cerca_carattere(const char str[], const char carattere, size_t *indice);

int main() {
    char str[MAXLINE + 1], carattere;
    size_t indice_carattere;

    puts("Inserisci stringa: ");
    scanf(" %100[^\n]", str);

    puts("Inserisci il carattere da cercare: ");
    scanf(" %c", &carattere);

    cerca_carattere(str, carattere, &indice_carattere);

    if (indice_carattere == strlen(str)) {
        puts("Carattere non trovato");
    }
    else {
        printf("Il carattere cercato si trova all'indice %lu\n", indice_carattere);
    }
    return 0;
}

void cerca_carattere(const char str[], const char carattere, size_t *indice)
{
    size_t i = 0;

    while (*(str + i) != '\0') {

        if (*(str + i) == carattere) {
            *indice = i;
            return;
        }
        i++;
    }

    *indice = i;
}
