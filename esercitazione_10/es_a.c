#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int main() {
    
    char str1[MAXLINE + 1], str2[MAXLINE + 1];
    
    puts("Inserisci la prima stringa");
    scanf(" %100[^\n]", str1);

    strcpy(str2, str1);
    puts("Stringa copiata");
    printf("%s\n", str2);
}