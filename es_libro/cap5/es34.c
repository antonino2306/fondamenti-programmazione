#include <stdio.h>

unsigned int power(unsigned int base, unsigned int exponent);

int main() {

    unsigned int base, exp;

    printf("Inserisci il la base e l'esponente: ");
    scanf("%u %u", &base, &exp);

    printf("%u^%u = %u\n", base, exp, power(base, exp));
    return 0;
    
}

unsigned int power(unsigned int base, unsigned int exponent)
{
    if (exponent == 1) {
        return base;
    }
    else {
        return base * power(base, exponent - 1);
    }
}
