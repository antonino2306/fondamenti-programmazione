#include <stdio.h>
#include <string.h>
#define SIZE 100

unsigned int grado_minimo(const char str[], size_t lungh);
unsigned int grado_massimo(const char str[], size_t lungh);

int main() {

    char parola[SIZE];
    
    printf("Inserisci una parola: ");
    scanf("%s", parola);

    size_t lunghezza = strlen(parola);

    unsigned int g_min = grado_minimo(parola, lunghezza);
    unsigned int g_max = grado_massimo(parola, lunghezza);

    printf("Grado minimo:  %u\n", g_min);
    printf("Grado massimo: %u\n", g_max);

    return 0;

}

unsigned int grado_minimo(const char str[], size_t lungh)
{
    unsigned int g_min = 101;

    for (size_t i = 0; i < lungh; i++) {
        unsigned int occorrenze = 0;
        for (size_t j = 0; j < lungh; j++) {

            if (str[i] == str[j]) {
                occorrenze++;
            }
        }

        if (occorrenze < g_min) {
            g_min = occorrenze;
        }
    }
    return g_min;
}

unsigned int grado_massimo(const char str[], size_t lungh)
{
    unsigned int g_max = 0;

    for (size_t i = 0; i < lungh - 1; i++) {
        unsigned int occorrenze = 1;
        for (size_t j = i + 1; j < lungh; j++) {

            if (str[i] == str[j]) {
                occorrenze++;
            }
        }

        if (occorrenze > g_max) {
            g_max = occorrenze;
        }
    }

    return g_max;
}
