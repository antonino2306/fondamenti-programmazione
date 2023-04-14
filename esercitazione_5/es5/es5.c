#include <stdio.h>

int main() {
    unsigned int n, num = 1, num_prec = 0;

    printf("Quanti numeri della successione di fibonacci devo stampare? ");
    scanf("%u", &n);

    if (n > 0) {
        printf("I primi %u numeri della successione di Fibonacci sono: 1 ", n);
        for (unsigned int i = 0; i < n-1; i++) {
            unsigned int copia_num;
            copia_num = num;
            num += num_prec;
            num_prec = copia_num;
            printf("%u ", num);
        }
    }
    else {
        printf("Devi inserire un numero > 0");
    }

    printf("\n");
    return 0;
}