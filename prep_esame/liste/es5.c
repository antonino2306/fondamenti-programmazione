#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo
{
    int num;
    struct nodo *succ;
    struct nodo *prec;
};
typedef struct nodo Nodo;

void inserisci(Nodo **lista, int num);
void stampa_lista(Nodo *lista);
void elimina_n_elementi(Nodo **lista, unsigned int n);
void elimina_lista(Nodo *lista);


int main() {
    
    Nodo *lista = NULL;
    size_t lungh;

    puts("Inserisci la lunghezza della lista");
    scanf("%lu", &lungh);

    srand(time(NULL));

    for (size_t i = 0; i < lungh; i++) {
        int num = rand() % 100 + 1;

        inserisci(&lista, num);

    }

    stampa_lista(lista);

    unsigned int n;

    puts("Inserisci quanti elementi vuoi rimuovere");
    scanf("%u", &n);

    elimina_n_elementi(&lista, n);

    if (lista != NULL) {
        stampa_lista(lista);
    }
    else {
        puts("Lista vuota");
    }

    elimina_lista(lista);

}

void inserisci(Nodo **lista, int num)
{
    if (*lista == NULL) {

        *lista = (Nodo*)malloc(sizeof(Nodo));

        if (*lista != NULL) {
            (*lista)->num = num;
            (*lista)->succ = NULL;
            (*lista)->prec = NULL;
        }

    }
    else {
        Nodo *scorri_lista = *lista, *nuovo = NULL;

        while (scorri_lista->succ != NULL) {
            scorri_lista = scorri_lista->succ;
        }

        nuovo = (Nodo*)malloc(sizeof(Nodo));

        if (nuovo != NULL) {

            nuovo->num = num;
            nuovo->succ = NULL;
            nuovo->prec = scorri_lista;

            scorri_lista->succ = nuovo;
            scorri_lista = scorri_lista->succ;

        }
    }
}

void stampa_lista(Nodo *lista) {

    while (lista != NULL) {

        printf("%d ", lista->num);
        lista = lista->succ;

    } 
    puts("");
}

void elimina_lista(Nodo *lista) {

    if (lista != NULL) {
        
        if (lista->succ != NULL) {
            elimina_lista(lista->succ);
        }

        free(lista);

    }

}

void elimina_n_elementi(Nodo **lista, unsigned int n)
{

    size_t i = 0;

    while (i < n && *lista != NULL) {

        // rimuovi dalla testa

        if ((*lista)->succ != NULL) {
            *lista = (*lista)->succ;
            free((*lista)->prec);
        }
        else {
            // elimina l'ultimo elemento della lista
            free(*lista);
            *lista = NULL;
        }

        i++;
    }

}
