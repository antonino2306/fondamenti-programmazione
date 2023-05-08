// L'esercizio senza la funzione di libreria è in /home/antonino/fondamenti-programmazione/esercizi_in_aula/stringhe/concatena_stringhe.c
#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int main() {
    
    char s1[2*MAXLINE+1], s2[MAXLINE+1];

    puts("Inserisci prima stringa");
    scanf(" %100[^\n]", s1);

    puts("Inserisci seconda stringa");
    scanf(" %100[^\n]", s2);

    strcat(s1, s2);
    printf("Stringa concatenata: %s\n", s1);

}