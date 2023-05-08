#include <stdio.h>
#include <stdlib.h>

void riempi_pila(int *stack, size_t *lunghezza_pila);
void stampa_pila(int *stack, size_t lunghezza_pila);
void modifica_pila(int *stack, size_t *lunghezza_pila);
void push(int *stack, size_t *lunghezza_pila);
void pop(int *stack, size_t *lunghezza_pila);

int main() {
    
    int *num_stack = (int *)calloc(1, sizeof(int));
    size_t lunghezza_pila = 0;

    riempi_pila(num_stack, &lunghezza_pila);
    stampa_pila(num_stack, lunghezza_pila);

    char scelta_utente;
    do {
        modifica_pila(num_stack, &lunghezza_pila);

        puts("Vuoi continuare a modificare y / n:");
        scanf(" %c", &scelta_utente);

    } while (scelta_utente == 'y' || scelta_utente == 'Y');

    stampa_pila(num_stack, lunghezza_pila);

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

void modifica_pila(int *stack, size_t *lunghezza_pila)
{
    int operazione;
    puts("Scegli cosa vuoi fare:");
    puts("1 per aggiungere un elemento");
    puts("2 per rimuovere un elemento");
    scanf("%d", &operazione);

    switch (operazione)
    {
    case 1:
        push(stack, lunghezza_pila);
        break;
    
    case 2:
        pop(stack, lunghezza_pila);
        break;
    default:
        break;
    }
}

void push(int *stack, size_t *lunghezza_pila)
{
    (*lunghezza_pila)++;
    stack = (int *)realloc(stack, *lunghezza_pila * sizeof(int));
    printf("Inserisci elemento: ");
    scanf(" %d", (stack + *lunghezza_pila - 1));
}

void pop(int *stack, size_t *lunghezza_pila)
{
    (*lunghezza_pila)--;
    stack = (int*)realloc(stack, *lunghezza_pila * sizeof(int));
}
