#include <stdio.h>

int ore_sec(int h);
int min_sec(int m);
int somma(int v1, int v2, int v3);

int main() {
    int ore = 3, min = 5, sec = 8;

    int h_s = ore_sec(ore);
    int m_s = min_sec(min);
    int tot_secondi = somma(h_s, m_s, sec);
    printf("Tempo totale in secondi:\n%d\n", tot_secondi);
    return 0;
}

int ore_sec(int h) {
    return h * 60 * 60;
}

int min_sec(int m) {
    return m * 60;
}

int somma(int v1, int v2, int v3) {
    return v1 + v2 + v3;
}