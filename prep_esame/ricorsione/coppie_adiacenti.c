#include <stdio.h>

unsigned int conta_coppie_adiacienti(int numero, short int rappresentante_coppia);

int main() {

    int numero;

    puts("Inserisci un numero");
    scanf("%d", &numero);

    unsigned int num_coppie = conta_coppie_adiacienti(numero, numero % 10);
    printf("Numero coppie adiacienti: %u\n", num_coppie);

}

unsigned int conta_coppie_adiacienti(int numero, short int rappresentante_coppia)
{   
    numero /= 10;

    if (numero == 0) {
        return 0;
    }

    if (rappresentante_coppia == numero % 10) {
        return 1 + conta_coppie_adiacienti(numero, numero % 10);
    }
    else {
        return 0 + conta_coppie_adiacienti(numero, numero % 10);
    }
}
