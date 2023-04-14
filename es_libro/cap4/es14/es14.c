#include <stdio.h>

long unsigned int calcola_fattoriale(unsigned int n);

int main() {
    // unsigned int numero;
    long unsigned int fattoriale;
    unsigned int contatore = 0;

    do {
    // printf("%s", "Inserisci un numero: ");
    // scanf("%u", &numero);

    fattoriale = calcola_fattoriale(contatore);
    printf("%u! = %lu\n", contatore, fattoriale);
    contatore++;
    } while (contatore <= 20);

}

long unsigned int calcola_fattoriale(unsigned int n)
{
    if (n <= 1) {
        return 1;
    }
    else {
        return (n * calcola_fattoriale(n-1));
    }
}
