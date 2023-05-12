#include <stdio.h>

void stampa_tartaglia(unsigned int n);
unsigned int coeff_bin(unsigned int n, unsigned int k);
unsigned int fact(unsigned int n);

int main() {
    unsigned int n;

    printf("Quante righe vuoi stampare? ");
    scanf("%u", &n);

    stampa_tartaglia(n);
}

void stampa_tartaglia(unsigned int n)
{


    if (n == 0) {
        printf("%u\n", coeff_bin(0, 0));
    }
    else {
        stampa_tartaglia(n - 1);
    }

    if (n != 0) {
        for (unsigned int i = 0; i < n + 1; i++) {
            printf("%u ", coeff_bin(n, i));
        }
        puts("");
    }
}

unsigned int coeff_bin(unsigned int n, unsigned int k)
{
    unsigned int n_fact = fact(n);
    unsigned int k_fact = fact(k);
    unsigned int nk_fact = fact(n-k);

    unsigned int c_bin = n_fact / (k_fact * nk_fact);
    return c_bin;
}

unsigned int fact(unsigned int n)
{
    unsigned int f = 1;
    for (unsigned int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}
