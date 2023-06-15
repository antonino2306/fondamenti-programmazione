#include <stdio.h>
#include <math.h>

long unsigned int pot(unsigned int a, unsigned int b);
long unsigned int pila(unsigned int n);
long unsigned int torre(unsigned int n, unsigned int indice);

int main() {
    unsigned int numero;

    printf("%s","Inserisci un numero: ");
    scanf("%u", &numero);
    printf("La funzione pila di  %u è: %lu\n", numero, pila(numero));
    printf("La funzione torre di %u è: %lu\n", numero, torre(numero, 0));
}

long unsigned int pot(unsigned int a, unsigned int b)
{
    if (b == 0) {
        return 1;
    }
    else {
        return a * pot(a, b-1);
    }
    return 0;
}

long unsigned int pila(unsigned int n)
{
    long unsigned int m;
    if (n == 1) {
        return 1;
    }
    else {
        return pot(n, pila(n-1));
    }
    return 0;
}

long unsigned int torre(unsigned int n, unsigned int indice)
{
    if (indice == n) {
        return 1;
    }
    else {
        return pot(n, torre(n, indice+1));
    }

}
