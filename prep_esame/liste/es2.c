#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo {
    unsigned int num;
    struct nodo *next;
};

typedef struct nodo Nodo;

Nodo *crea_lista(size_t dim);
void stampa_lista(Nodo *lista);
void elimina_lista(Nodo *lista);
unsigned int max(Nodo *lista);
Nodo *first_even(Nodo *lista);
Nodo *min_even(Nodo *lista);
Nodo *min_even_ric(Nodo *lista, Nodo* min);

int main(int argc, char *argv[]) {

    Nodo *lista = NULL;

    size_t lunghezza;
    puts("Inserisci la lunghezza della lista");
    scanf("%lu", &lunghezza);

    lista = crea_lista(lunghezza);
    stampa_lista(lista);

    unsigned int massimo = max(lista);
    
    printf("Il massimo è %u\n", massimo);

    Nodo *primo_elemento_pari = first_even(lista);

    if (primo_elemento_pari != NULL) {
        printf("Il primo numero pari è %u e si trova all'indirizzo %p\n", primo_elemento_pari->num, primo_elemento_pari);
    }
    else {
        puts("Nessun elemento pari");
    }

    Nodo *min_pari = min_even_ric(lista, lista);

    if (min_pari != NULL) {
        printf("Il numero pari più piccolo è %u e si trova all'indirizzo %p\n", min_pari->num, min_pari);
    }
    else {
        puts("Nessun elemento pari");
    }

    elimina_lista(lista);
    return 0;

}

Nodo *crea_lista(size_t dim) {

    srand(time(NULL));

    Nodo *lista = NULL;

    lista = (Nodo*)malloc(sizeof(Nodo));

    if (lista != NULL) {

        lista->num = (rand() % 100) + 1;
        lista->next = NULL;

        Nodo *corrente = lista;

        for(size_t i = 0; i < dim - 1; i++) {
            Nodo *new = NULL;
            new = (Nodo*)malloc(sizeof(Nodo));

            if (new != NULL) {
                new->num = (rand() % 100) + 1;
                new->next = NULL;
            }

            corrente->next = new;
            corrente = corrente->next;

        }

    }

    return lista;

}

void stampa_lista(Nodo *lista) {
    while (lista != NULL) {
        printf("%u ", lista->num);
        lista = lista->next;
    }
    puts("");
}

void elimina_lista(Nodo *lista) {
    while (lista != NULL) {
        Nodo *tmp = lista;
        lista = lista->next;
        free(tmp);
    }
}

unsigned int max(Nodo *lista)
{
    unsigned int massimo;

    if (lista == NULL) {
        puts("Lista vuota");
        return 0;
    }
    if (lista->next == NULL) {
        return lista->num;
    }
    else {
        massimo = max(lista->next);
        if (massimo < lista->num) {
            return lista->num;
        }
        else {
            return massimo;
        }
    }
}

Nodo *first_even(Nodo *lista)
{
    if (lista == NULL) {
        return NULL;
    }
    else {
        if (lista->num % 2 == 0) {
            return lista;
        }
        else {
            return first_even(lista->next);
        }
    }
}

Nodo *min_even(Nodo *lista)
{
    Nodo *min = NULL;
    while (lista != NULL && lista->num % 2 != 0) {
        lista = lista->next;
    }
    
    if (lista != NULL) {
        min = lista;

        while (lista != NULL) {
            if (lista->num % 2 == 0 && lista->num < min->num) {
                min = lista;
            }
            lista = lista->next;
        }
    }
    
    return min;
}

Nodo *min_even_ric(Nodo *lista, Nodo *min)
{

    if (lista == NULL) {
        if (min->num % 2 != 0) {
            return NULL;
        }
        return min;
    }
    else {
        if (lista->num % 2 == 0 && lista->num < min->num) {
            min = lista;
        }
        return min_even_ric(lista->next, min);
    }
    
}
