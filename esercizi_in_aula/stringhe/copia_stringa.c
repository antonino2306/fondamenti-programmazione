#include <stdio.h>

void copia_stringa(const char str1[], char str2[]);

int main() {
    char s1[100], s2[100];

    puts("Inserisci la prima stringa");
    scanf(" %99[^\n]", s1);

    copia_stringa(s1, s2);

    puts("Stringa copiata");
    printf("%s\n", s2);

    return 0;

}

void copia_stringa(const char str1[], char str2[])
{
    size_t i = 0;

    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}
