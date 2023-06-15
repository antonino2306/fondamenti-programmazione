#include <stdio.h>

void somma_cifre(int numero, int *somma);
int somma_cifre_v2(int n);

int main() {

    int numero;

    puts("Inserisci un numero");
    scanf("%d", &numero);

    int somma = 0;
    somma_cifre(numero, &somma);

    printf("La somma delle cifre di %d ridotta ad un numero < 10 è %d\n", numero, somma);

}

void somma_cifre(int numero, int *somma) {

    
    while (numero != 0) {
        *somma += numero % 10;
        numero /= 10;
    }
    
    if (*somma >= 10) {
        numero = *somma;
        *somma = 0;
        return somma_cifre(numero, somma);
    }

}

int somma_cifre_v2(int n) {

    int somma = 0;
    
    while (n != 0) {

        somma += n % 10;
        n /= 10;

    }

    if (somma < 10) {
        return somma;
    }
    else {
        return somma_cifre_v2(somma);
    }

}