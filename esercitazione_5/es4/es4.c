#include <stdio.h>

int main() {
    int n;
    int somma = 0;

    printf("Leggi il valore di n: ");
    scanf("%d", &n);

    if (n > 0) {

        for (unsigned int i = n; i <= 2*n; i++) {
            somma += i;
        }

        printf("La somma dei numeri tra %d e %d (estremi inclusi) è: %d\n", n, 2*n, somma);
    }
    else if (n < 0) {

        for (unsigned int i = 2*n; i <= n; i++) {
            somma += i;
        }
        printf("La somma dei numeri tra %d e %d (estremi inclusi) è: %d\n", 2*n, n, somma);

    }

    return 0; 
}