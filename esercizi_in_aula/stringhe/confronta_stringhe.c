#include <stdio.h>

short int confronta_stringhe(const char str1[], const char str2[]);

int main() {

    char s1[100], s2[100];

    puts("Inserisci prima stringa");
    scanf(" %99[^\n]", s1);

    puts("Inserisci seconda stringa");
    scanf(" %99[^\n]", s2);

    if (confronta_stringhe(s1, s2)) {
        puts("Uguali");
    }
    else {
        puts("Diverse");
    }

    return 0;
}

short int confronta_stringhe(const char str1[], const char str2[])
{
    size_t i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return str1[i] == str2[i];
}
