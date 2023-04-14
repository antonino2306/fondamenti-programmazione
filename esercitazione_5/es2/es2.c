#include <stdio.h>

int main() {
    unsigned int fattoriale = 1, n;

    printf("Di quale numero devo calcolare il fattoriale? ");
    scanf("%u", &n);

    if (n != 0) {
        
        for (unsigned int i = 1; i <= n; i++) {
            fattoriale *= i;
        }

    }

    printf("Risultato: %u\n", fattoriale);
    return 0;
}