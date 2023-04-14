// Scrivere un programma in linguaggio c, con le opportune funzioni, che dati due numeri, calcola la differenza
// tra il numero maggiore e il numero minore.
#include <stdio.h>

float max(float a, float b);
float min(float a, float b);
// Differenza tra valore maggiore e minore inseriti dall'utente
int main() {
    float x, y, differenza;
    float maggiore, minore;
    
    printf("Inserisci due numeri: ");
    scanf("%f %f", &x, &y);

    maggiore = max(x, y);
    minore = min(x, y);

    differenza = maggiore - minore;

    printf("|x-y| = %.2f\n", differenza);

    return 0;
}

float max(float a, float b)
{
    if (a >= b)
        return a;
    else 
        return b;
}

float min(float a, float b)
{
    if (a <= b)
        return a;
    else 
        return b;
}
