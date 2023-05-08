#include <stdio.h>
#include <string.h>
#define MAXLINE 99

void cerca_stringa(const char str1[], const char str2[], size_t *indice);
unsigned int lunghezza_stringa(const char str[]);

int main() {
    
    char stringa[MAXLINE + 1], stringa_da_cercare[MAXLINE + 1];

    puts("Inserisci prima stringa");
    scanf(" %99[^\n]", stringa);

    puts("Inserisci stringa da cercare");
    scanf(" %99[^\n]", stringa_da_cercare);

    size_t indice_di_inizio;
    cerca_stringa(stringa, stringa_da_cercare, &indice_di_inizio);

    if (indice_di_inizio != 101) {
        printf("La stringa inizia all'indice %lu\n", indice_di_inizio);
    }
    else {
        puts("Il pattern che cerchi non è nella stringa");
    }

    return 0;
}

void cerca_stringa(const char str1[], const char str2[], size_t *indice)
{
    size_t indice_pattern = 0;
    unsigned int lunghezza_pattern = strlen(str2);
    for (size_t i = 0; *(str1 + i) != '\0'; i++) {
        if (*(str1 + i) == *(str2 + indice_pattern)) {
            indice_pattern++;
        }
        if (indice_pattern == lunghezza_pattern) {
            *indice = i - (lunghezza_pattern - 1);
            return;
        }
    }
    *indice = 101;
}
