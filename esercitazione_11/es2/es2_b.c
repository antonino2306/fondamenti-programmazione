#include <stdio.h>
#define MAXLINE 100

int confronta_stringhe(const char str1[], const char str2[]);

int main() {
    char str1[MAXLINE + 1], str2[MAXLINE + 1];

    puts("Inserisci la prima stringa:");
    scanf(" %100[^\n]", str1);

    puts("Inserisci la seconda stringa:");
    scanf(" %100[^\n]", str2);

    if(confronta_stringhe(str1, str2)) {
        puts("Uguali");
    }
    else {
        puts("Diverse");
    }
}

int confronta_stringhe(const char str1[], const char str2[]) {

    size_t i;

    for (i = 0; *(str1 + i) != '\0' && *(str2 + i) != '\0'; i++) {
        if (*(str1 + i) != *(str2 + i)) {
            return 0;
        }
    }

    return *(str1 + i) == *(str2 + i);
}