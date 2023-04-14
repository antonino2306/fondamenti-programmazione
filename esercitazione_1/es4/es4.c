#include <stdio.h>

float calcola_stipendio(int paga, int ore);

int main() {
    int paga_oraria = 27, num_ore_mensili = 730;
    float stipendio = calcola_stipendio(paga_oraria, num_ore_mensili);
    printf("Lo stipendio mensile è: %.2f\n", stipendio);
    return 0;
}

float calcola_stipendio(int paga, int ore)
{
    float trattenuta = 0.18;
    int tot = paga * ore;
    float stipendio = tot - tot * trattenuta;
    return stipendio;
}

// Per calcolare lo stipendio di tutti gli impegati
// basta moltiplicare lo stipendio del signolo per il 
// numero di impiegati. Assumendo che tutti abbiano lo stesso stipendio