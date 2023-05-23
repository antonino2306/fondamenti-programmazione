#include <stdio.h>
#define SIZE 50
#define NUM 3

struct Persona {
    char nome[SIZE];
    float altezza;
    float peso;
    unsigned int eta;
};

typedef struct Persona Persona;

void riempi_persona(Persona *p);
void stampa_persona(const Persona *p);

int main() {

    Persona p[NUM];

    for (size_t i = 0; i < NUM; i++) {
        printf("Inserisci i dati della persona %lu\n", i);
        riempi_persona(p + i);
        puts("");
    }

    for (size_t i = 0; i < NUM; i++) {
        printf("Dati della persona %lu\n", i);
        stampa_persona(p + i);
        puts("");
    }

    
    return 0;

}

void riempi_persona(Persona *p)
{
    printf("Nome: ");
    scanf(" %20[^\n]", p -> nome);

    printf("Eta: ");
    scanf("%u", &(p -> eta));

    printf("Peso: ");
    scanf("%f", &(p -> peso));

    printf("Altezza: ");
    scanf("%f", &(p -> altezza));

}

void stampa_persona(const Persona *p)
{
    printf("Nome: %s\nEtà: %u\nPeso: %f\nAltezza: %f\n", 
            p -> nome, p -> eta, p -> peso, p -> altezza);
}
