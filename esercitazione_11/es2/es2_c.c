#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void concatena_stringhe(char str1[], const char str2[]);

int main() {

    char str1[MAXLINE + 1], str2[MAXLINE + 1];

    puts("Inserisci la prima stringa:");
    scanf(" %100[^\n]", str1);

    puts("Inserisci la seconda stringa:");
    scanf(" %100[^\n]", str2);

    concatena_stringhe(str1, str2);

    printf("Stringa concatenata: %s\n", str1);
}

void concatena_stringhe(char str1[], const char str2[]) {

    unsigned int l_str1 = strlen(str1), l_str2 = strlen(str2);

    if (l_str1 + l_str2 > MAXLINE) {
        puts("Concatenazione impossibile. Stringhe troppo lunghe");
        return;
    }

    size_t i = 0;

    while (*(str1 + i) != '\0') {
        i++;
    }

    size_t j = 0;
    while (*(str2 + j) != '\0') {

        *(str1 + i) = *(str2 + j);
        i++;
        j++;
    }

    *(str1 + i) = '\0';
}