#include <stdio.h>

void char_to_dec(char c);

int main() {
    char carattere;

    printf("Inserisci un carattere qualsiasi: ");
    scanf("%c", &carattere);
    char_to_dec(carattere);

    return 0;
}

void char_to_dec(char c)
{
    printf("Il valore decimale di %c è %d\n", c, c);
}
