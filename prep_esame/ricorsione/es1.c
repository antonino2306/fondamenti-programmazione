//? Somma dei primi N numeri pari positivi usando la ricorsione
#include <stdio.h>

unsigned int somma_pari(unsigned int n);

int main() {

    unsigned int n;

    puts("Quanti numeri pari vuoi sommare:");
    scanf("%u", &n);

    printf("La somma dei primi %u numeri pari è: %u\n", n, somma_pari(n));

}

unsigned int somma_pari(unsigned int n)
{
    
    if (n == 1) {
        return 2;
    }
    else {
        return 2*n + somma_pari(n-1);
    }
    
}
