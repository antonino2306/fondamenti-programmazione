#include <stdio.h>

int somma_pari(int n);
int somma_pari2(int n);

int main() {
    int n;

    printf("Inserisci un numero: ");
    scanf("%d", &n);

    int somma;
    int somma2;

    if (n % 2 == 1) {
        somma = somma_pari(n-1);
    }
    else {
        somma = somma_pari(n);
    }

    somma2 = somma_pari2(n);


    printf("La somma dei numeri pari da 0 a %d è: %d\n", n, somma);
    printf("La somma dei primi %d numeri pari è: %d\n", n, somma2);
    return 0;
}

int somma_pari(int n)
{
    if (n == 0) {
        return n;
    }
    else {
        return n + somma_pari(n - 2);
    }
}

int somma_pari2(int n)
{
    if (n == 0) {
        return n;
    }
    else {
        return 2*n + somma_pari2(n-1);
    }
    return 0;
}
