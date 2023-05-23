#include <stdio.h>
#include <stdlib.h>
#define MAXLENGHT 30

// todo sistemare la stampa degli ingredienti e organizzare meglio il codice

struct pietanza {

    char nome[MAXLENGHT];
    char **ingredienti;
    unsigned int *dosi;
    unsigned int tempo_cottura;
    char tipo_piatto[10];

};

typedef struct pietanza Pietanza;

void riempi_pietanza(Pietanza *p, size_t *num_ingredienti);
void inserisci_ingredienti(char **ingredienti, unsigned int *dosi, size_t num_ingredienti);
void stampa_pietanza(const Pietanza *p, size_t num_ingredienti);
void libera_memoria(Pietanza *p, size_t num_ingredienti);

int main() {

    Pietanza piatto;
    size_t num_ingredienti;

    riempi_pietanza(&piatto, &num_ingredienti);

    stampa_pietanza(&piatto, num_ingredienti);
    
    libera_memoria(&piatto, num_ingredienti);

    return 0;
}

void riempi_pietanza(Pietanza *p, size_t *num_ingredienti)
{
    printf("Inserisci nome: ");
    scanf("%30[^\n]", p->nome);

    printf("Inserisci il numero di ingredienti: ");
    scanf("%lu", num_ingredienti);

    p->ingredienti = (char**)calloc(*num_ingredienti, sizeof(char));
    p->dosi = (unsigned int*)calloc(*num_ingredienti, sizeof(unsigned int));

    inserisci_ingredienti(p->ingredienti, p->dosi, *num_ingredienti);

    printf("Inserisci il tempo di cottura in minuti: ");
    scanf("%u", &(p->tempo_cottura));

    printf("Inserisci il tipo di piatto: ");
    scanf(" %10[^\n]", p->tipo_piatto);
}

void inserisci_ingredienti(char **ingredienti, unsigned int *dosi, size_t num_ingredienti)
{
    for(size_t i = 0; i < num_ingredienti; i++) {
        ingredienti[i] = (char*)calloc(MAXLENGHT + 1, sizeof(char));
        printf("Inserisci l'ingrediente: ");
        scanf(" %30[^\n]", ingredienti[i]);
        printf("Inserisci la quantità: ");
        scanf("%u", &dosi[i]);
    }
}

void stampa_pietanza(const Pietanza *p, size_t num_ingredienti)
{
    puts("----------------------------------------------------------");
    printf("Nome piatto: %s\n", p->nome);
    
    puts("Ingredienti: ");
    for (size_t i = 0; i < num_ingredienti; i++) {
        printf("\t%s %u g\n", p->ingredienti[i], p->dosi[i]);
    }

    printf("Tempo di cottura: %u minuti\n", p->tempo_cottura);
    printf("Tipo di piatto: %s\n", p->tipo_piatto);

}

void libera_memoria(Pietanza *p, size_t num_ingredienti)
{
    for (size_t i = 0; i < num_ingredienti; i++) {
        free(p->ingredienti[i]);
    }

    free(p->ingredienti);
    free(p->dosi);
}
