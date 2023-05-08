#include <stdio.h>
#include <stdlib.h>

void riempi_pila(int *stack, size_t *lunghezza_pila);
void stampa_pila(int *stack, size_t lunghezza_pila);
int* min_adr(int *stack, size_t lunghezza_pila);
size_t min_index(int* stack, int* min_adr);


int main() {
    int *num_stack = (int *)calloc(1, sizeof(int));
    size_t lunghezza_pila = 0;

    riempi_pila(num_stack, &lunghezza_pila);
    stampa_pila(num_stack, lunghezza_pila);

    int *elemento_minimo_adr = min_adr(num_stack, lunghezza_pila);

    printf("L'elemento minimo è: %d e si trova all'indirizzo: %p\n", *(num_stack + min_index(num_stack, elemento_minimo_adr)), elemento_minimo_adr);

    free(num_stack);
}

void riempi_pila(int *num_stack, size_t *lunghezza_pila)
{
    
    char scelta_utente;
    do {
        int numero;
        num_stack = (int *)realloc(num_stack, (*lunghezza_pila + 1) * sizeof(int));

        printf("Inserisci un numero: ");
        scanf(" %d", (num_stack + *lunghezza_pila));

        (*lunghezza_pila)++;

        printf("Devi inserire ancora numeri y/n: ");
        scanf(" %c", &scelta_utente);

    } while (scelta_utente == 'y' || scelta_utente == 'Y');

}

void stampa_pila(int *stack, size_t lunghezza_pila)
{
    for (size_t i = 0; i < lunghezza_pila; i++) {
        printf("%d\t", *(stack + i));
    }

    puts("");
}

int *min_adr(int *stack, size_t lunghezza_pila)
{
    int *min_adr = stack;

    for (size_t i = 1; i < lunghezza_pila; i++) {
        if (*(stack + i) < *min_adr) {
            min_adr = stack + i;
        }
    }

    return min_adr;
}

size_t min_index(int *stack, int *min_adr)
{
    size_t min_index = (size_t)(min_adr - stack);
    return min_index;
}
