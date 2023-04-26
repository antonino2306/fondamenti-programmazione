#include <stdio.h>

size_t cerca_carattere(const char str1[], char carattere);

int main() {
    
    char s1[100], carattere;

    puts("Inserisci stringa");
    scanf(" %99[^\n]", s1);

    puts("Inserisci carattere da cercare: ");
    scanf(" %c", &carattere);

    size_t posizione = cerca_carattere(s1, carattere);

    if (posizione != 101) {
        printf("Il carattere compare alla posizione %lu\n", posizione);
    }
    else {
        puts("Il carattere non compare");
    }
}

size_t cerca_carattere(const char str1[], char carattere)
{

    for (size_t i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == carattere) {
            return i;
        }
    }

    return 101;
}
