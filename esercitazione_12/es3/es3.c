#include <stdio.h>
#include <stdlib.h>

size_t lunghezza_stringa(const char *str, size_t *l);

int main() {

    size_t dim;
    const char *str;

    printf("Inserisci la dimensione della stringa: ");
    scanf("%lu", &dim);

    str = (char*)calloc(dim+1, sizeof(char));

    char formato[11];
    sprintf(formato, " %%%lu[^\n]", dim);

    puts("Inserisci stringa:");
    scanf(formato, str);

    size_t lunghezza = 0;
    
    lunghezza_stringa(str, &lunghezza);

    printf("La lunghezza della stringa è: %lu\n", lunghezza);

    free(str);

    return 0;

}

size_t lunghezza_stringa(const char *str, size_t *l)
{
    if (*str == '\0') {
        return *l;
    }
    else {
        (*l)++;
        return lunghezza_stringa(str + 1, l);
    }

}
