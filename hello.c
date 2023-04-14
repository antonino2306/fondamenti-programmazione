#include <stdio.h>
#include <math.h>

int main() {
    int numero, cifra;

    scanf("%d", &numero);
    for (int i = 0; i < 5; i++) {
        int divisore = pow(10, i);
        cifra = (numero / divisore) % 10;
        printf("%d", cifra);
    }
    return 0;
}