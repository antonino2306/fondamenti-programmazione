#include <stdio.h>
#define LUNGHEZZA 100

unsigned int conta_maiuscole(const unsigned char str[]);
unsigned int conta_minuscole(const unsigned char str[]);
unsigned int conta_cifre(const unsigned char str[]);
unsigned int conta_altri_caratteri(const unsigned char str[]);

int main() {
    
    unsigned char stringa[LUNGHEZZA + 1];

    puts("Inserisci stringa");
    printf("%s", "> ");
    scanf("%100[^\n]", stringa);

    unsigned int maiuscole = conta_maiuscole(stringa);
    unsigned int minuscole = conta_minuscole(stringa);
    unsigned int cifre = conta_cifre(stringa);
    unsigned int altri_caratteri = conta_altri_caratteri(stringa);

    printf("Numero maiuscole: %u\n", maiuscole);
    printf("Numero minuscole: %u\n", minuscole);
    printf("Numero cifre    : %u\n", cifre);
    printf("Numero altri car: %u\n", altri_caratteri);

    return 0;
}

unsigned int conta_maiuscole(const unsigned char str[])
{
    unsigned int contatore = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            contatore++;
        }
    }
    return contatore;
}

unsigned int conta_minuscole(const unsigned char str[])
{
    unsigned int contatore = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            contatore++;
        }
    }
    return contatore;
}

unsigned int conta_cifre(const unsigned char str[])
{
    unsigned int contatore = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            contatore++;
        }
    }
    return contatore;
}


unsigned int conta_altri_caratteri(const unsigned char str[])
{
    unsigned int contatore = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 48 && str[i] <= 57) && !(str[i] >= 65 && str[i] <= 90)) {
            contatore++;
        }
    }
    return contatore;
}