#include <stdio.h>

void concatena_stringhe(const char str1[], const char str2[], char str3[]);

int main() {
    
    char s1[100], s2[100], s3[200];

    puts("Inserisci prima stringa");
    scanf(" %99[^\n]", s1);

    puts("Inserisci seconda stringa");
    scanf(" %99[^\n]", s2);

    concatena_stringhe(s1, s2, s3);
    printf("Stringa concatenata: %s\n", s3);

}

void concatena_stringhe(const char str1[], const char str2[], char str3[])
{
    size_t i = 0;

    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }
    // inserisci uno spazio bianco per separare str1 e str2
    str3[i] = ' ';
    
    size_t j = 0;
    
    while (str2[j] != '\0') {
        // Inizia ad inserire dall'elemento successivo allo spazio bianco
        i++;
        str3[i] = str2[j];
        j++;
    }
}
