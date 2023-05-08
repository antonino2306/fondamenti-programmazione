#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int main() {
    
    char str1[MAXLINE + 1], str2[MAXLINE + 1];
    
    puts("Inserisci la prima stringa");
    scanf(" %100[^\n]", str1);

    puts("Inserisci la seconda stringa");
    scanf(" %100[^\n]", str2);

    if (strcmp(str1, str2) == 0) {
        puts("Uguali");
    }
    else {
        puts("Diverse");
    }

    return 0;
}