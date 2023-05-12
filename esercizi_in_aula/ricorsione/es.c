// Funzione ricorsiva che dato un numero calcola la funzione di fibonacci
#include <stdio.h>

int fibonacci(int n);
int fibonacci_iterativo(unsigned int n);

int main() {

    unsigned int x, i;
    printf("Che numero di fibonacci vuoi? ");
    scanf("%d", &i);

    x = fibonacci(i);

    // if (x != -1) {
    //     printf("Il numero di fibonacci di posizione %d è %d\n", i, x);
    // }

    x = fibonacci_iterativo(i);
    printf("numero di fibonacci iterativo di posizione %d è %d\n", i, x);
    return 0;
}

int fibonacci(int n)
{
    if (n <= 0) {
        printf("Errore, ci vuole un numero positivo\n");
        return -1;
    }
    // Caso base 1
    if (n == 1) {
        return 0;
    }
    // Caso base 2
    else if (n == 2) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    return 0;
}

int fibonacci_iterativo(unsigned int n)
{
    int risultato, f_prec, f_prec2;

    if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }

    f_prec = 1;
    f_prec2 = 0;

    for (int i = 3; i <= n; i++) {

        risultato = f_prec + f_prec2;
    
        f_prec2 = f_prec;
        f_prec = risultato;

    }

    return risultato;
}
