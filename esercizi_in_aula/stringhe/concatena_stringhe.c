#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void concatena_stringhe(char str1[], const char str2[]);

int main() {
    
    char s1[2*MAXLINE], s2[MAXLINE];

    puts("Inserisci prima stringa");
    scanf(" %99[^\n]", s1);

    puts("Inserisci seconda stringa");
    scanf(" %99[^\n]", s2);

    concatena_stringhe(s1, s2);
    printf("Stringa concatenata: %s\n", s1);

}

void concatena_stringhe(char str1[], const char str2[])
{
    size_t i = 0;

    int l_str1 = strlen(str1), l_str2 = strlen(str2);

    if (l_str1 + l_str2 >= MAXLINE) {
        printf("Concatenazione impossibile");
        return;
    }
    

    while (str1[i] != '\0') {
        i++;
    }
    // inserisci uno spazio bianco per separare str1 e str2
    str1[i] = ' ';
    
    size_t j = 0;
    
    while (str2[j] != '\0') {
        // Inizia ad inserire dall'elemento successivo allo spazio bianco
        i++;
        str1[i] = str2[j];
        j++;
    }
    str1[i+1] = '\0';
}
