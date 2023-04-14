#include <stdio.h>

int main() {
    unsigned int numero, cifra, cifra2;
    int i = 0, corrispondenza = 0;
    int denominatore = 10000;
    // unsigned int flag = 1;
    printf("Inserisci un numero di 5 cifre: ");
    scanf("%u", &numero);

    // 1232     1
    while (i < 2) {
        cifra = numero % 10;

        if (cifra == ((numero / denominatore) % 10)) {
            corrispondenza++;
        }

        numero /= 10;
        denominatore /= 100;
        i++;
    }

    if (corrispondenza == 2) {
        printf("Palindromo\n");
    }
    else {
        printf("Non palindromo\n");
    }

    return 0;
}
