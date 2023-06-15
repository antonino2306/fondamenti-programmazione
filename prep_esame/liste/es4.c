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
unsigned int conta_picchi(Nodo *lista);
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

    unsigned int num_picchi = conta_picchi(lista);

    printf("Il numero di picchi della lista è: %u\n", num_picchi);

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

unsigned int conta_picchi(Nodo *lista)
{
    unsigned int conta = 0;
    if (lista != NULL && lista->succ != NULL) {


        // punto al secondo elemento della lista
        lista = lista->succ;

        while (lista->succ != NULL) {

            if ((lista->num / 2) >= lista->prec->num && (lista->num / 2) >= lista->succ->num) {
                conta++;
            }

            lista = lista->succ;

        }

    }

    return conta;
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