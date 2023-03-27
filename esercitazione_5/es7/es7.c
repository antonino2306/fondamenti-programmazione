#include <stdio.h>

int main() {
    unsigned int numero;    
    int cifre[5];

    printf("Inserisci un numero di 5 cifre: ");
    scanf("%u", &numero);

    for (unsigned int i = 0; i < 5; i++) {
        cifre[i] = numero % 10;
        numero /= 10;
    }

    if ((cifre[0] == cifre[4]) && (cifre[1] == cifre[3])) {
        printf("Palindromo\n");
    }
    else {
        printf("Non palindromo\n");
    }

    return 0;
}