#include <stdio.h>
#include <stdlib.h>

size_t lunghezza_stringa(const char *str, size_t *l);
size_t lunghezza_stringa2(const char *str);

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
    printf("La lunghezza della stringa è: %lu\n", lunghezza_stringa2(str));

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

size_t lunghezza_stringa2(const char *str)
{

    if (*str == '\0') {
        return 0;
    }
    else {
        return 1 + lunghezza_stringa2(str + 1);
    }
    
}
