#include <stdio.h>
#include <math.h>

int main() {
    int numero;
    unsigned int ripetitivo = 0;

    printf("Inserisci numero: ");
    scanf("%u", &numero);

    // trova il numero delle cifre
    int cifre = 0;
    int num;
    do {
        num = numero / pow(10, cifre);
        cifre++;
    } while (num != 0);

    for (int i = 0; i < cifre-1 && !ripetitivo; i++) {

        int divisore = pow(10, i);
        int cifra_estratta = (numero / divisore) % 10;

        for (int j = i+1; j < cifre; j++) {
            int divisore2 = pow(10, j);
            if (cifra_estratta == ((numero / divisore2) % 10)) {
                ripetitivo = 1;

            }
        }
    }

    if (ripetitivo) {
        puts("Ripetitivo");
    }
    else {
        puts("Non ripetitivo");
    }

    return 0;
}