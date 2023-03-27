// Calcolare il valore assoluto di un numero in input
#include <stdio.h>

float val_abs(float n);

int main(void) {
    float n, n_abs;

    printf("Inserisci un numero: ");
    scanf("%f", &n);

    n_abs = val_abs(n);

    printf("|%.2f| = %.2f\n", n, n_abs);
    
    return 0;
}

float val_abs(float n) {
    if (n >= 0)
        return n;
    else
        return -1 * n;
}