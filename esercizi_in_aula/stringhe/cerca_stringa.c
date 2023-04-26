#include <stdio.h>

size_t cerca_stringa(const char str1[], const char str2[]);
unsigned int lunghezza_stringa(const char str[]);

int main() {
    
    char stringa[100], stringa_da_cercare[100];

    puts("Inserisci prima stringa");
    scanf(" %99[^\n]", stringa);

    puts("Inserisci stringa da cercare");
    scanf(" %99[^\n]", stringa_da_cercare);

    size_t indice_di_inizio = cerca_stringa(stringa, stringa_da_cercare);

    if (indice_di_inizio != 101) {
        printf("La stringa inizia all'indice %lu\n", indice_di_inizio);
    }
    else {
        puts("Il pattern che cerchi non è nella stringa");
    }

    return 0;
}

size_t cerca_stringa(const char str1[], const char str2[])
{
    size_t indice_pattern = 0;
    unsigned int lunghezza_pattern = lunghezza_stringa(str2);
    for (size_t i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == str2[indice_pattern]) {
            indice_pattern++;
        }
        if (indice_pattern == lunghezza_pattern) {
            return i - (lunghezza_pattern - 1);
        }
    }
    return 101;
}

unsigned int lunghezza_stringa(const char str[])
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
