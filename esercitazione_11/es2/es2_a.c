#include <stdio.h>
#define MAXLINE 100

void copia_stringa(const char str[], char str1[]);

int main() {
    char str[MAXLINE + 1], str1[MAXLINE + 1];

    puts("Inserisci la stringa");
    scanf(" %100[^\n]", str);

    copia_stringa(str, str1);
    puts("Stringa copiata:");
    printf("%s\n", str1);
}

void copia_stringa(const char str[], char str1[]) {

    size_t i = 0;

    while (*(str + i) != '\0') {
        *(str1 + i) = *(str + i);
        i++;
    }
    *(str1 + i) = '\0';
}