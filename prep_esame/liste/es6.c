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

void inserisci_in_ordine(Nodo **lista, int num);
void stampa_al_contrario(Nodo *lista);
void stampa_lista(Nodo *lista);
void elimina_lista(Nodo *lista);

int main() {

    Nodo *lista = NULL;
    size_t lungh;

    puts("Inserisci la lunghezza della lista");
    scanf("%lu", &lungh);

    srand(time(NULL));

    for (size_t i = 0; i < lungh; i++) {
        int num = rand() % 100 + 1;

        inserisci_in_ordine(&lista, num);

    }

    // puts("Numeri inseriti");

    stampa_lista(lista);
    stampa_al_contrario(lista);

    elimina_lista(lista);
}

void inserisci_in_ordine(Nodo **lista, int num)
{
    if (*lista == NULL) {
        // Inserisci il primo elemento

        *lista = (Nodo*)malloc(sizeof(Nodo));

        if (*lista != NULL) {

            (*lista)->num = num;
            (*lista)->succ = NULL;
            (*lista)->prec = NULL;

        }

    }
    else {

        Nodo *nuovo = NULL;
        nuovo = (Nodo*)malloc(sizeof(Nodo));

        if (nuovo != NULL) {

            nuovo->num = num;
            nuovo->succ = NULL;
            nuovo->prec = NULL;

            if (nuovo->num <= (*lista)->num) {
                // Inserisci in testa
                nuovo->succ = *lista;
                (*lista)->prec = nuovo;
                *lista = nuovo;
            }
            else {
                Nodo *scorri_lista = *lista;

                while (scorri_lista->succ != NULL && nuovo->num > scorri_lista->num) {
                    scorri_lista = scorri_lista->succ;
                }

                if (nuovo->num < scorri_lista->num) {

                    // aggiungi prima di scorri_lista

                    nuovo->prec = scorri_lista->prec;
                    nuovo->succ = scorri_lista;

                    scorri_lista->prec->succ = nuovo;
                    scorri_lista->prec = nuovo;

                }
                else {
                    // aggiungi alla fine
                    scorri_lista->succ = nuovo;
                    nuovo->prec = scorri_lista;
                }
            }

        }

    }
}

void stampa_al_contrario(Nodo *lista)
{
    if (lista != NULL) {

        // vai alla fine della lista
        while (lista->succ != NULL) {

            lista = lista->succ;

        }

        //torna all'inizio stampando
        while (lista != NULL) {
            printf("%d ", lista->num);
            lista = lista->prec;
        }
        puts("");
    }

}

void elimina_lista(Nodo *lista) {

    while (lista != NULL) {
        Nodo *tmp = lista;

        lista = lista->succ;
        free(tmp);

    }

}

void stampa_lista(Nodo *lista) {
    while (lista != NULL) {
        printf("%d ", lista->num);
        lista = lista->succ;
    }
    puts("-----------------------------");
}