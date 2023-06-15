#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo {
    int num;
    struct nodo *next;
};

typedef struct nodo Nodo;

Nodo *crea_lista(size_t dim);
void elimina_lista(Nodo *lista);
void stampa_lista(Nodo *lista);
void stampa_lista_al_contrario_ricorsiva(Nodo *lista);
Nodo *cerca_valore(Nodo *lista, int numero);

int main() {

    Nodo *lista = NULL;
    size_t lunghezza;

    puts("Quanto deve essere lunga la lista? ");
    scanf("%lu", &lunghezza);

    lista = crea_lista(lunghezza);

    stampa_lista(lista);

    int num;
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &num);

    Nodo *elemento_cercato = cerca_valore(lista, num);

    if (elemento_cercato != NULL) {
        printf("%d si trova all'indirizzo %p\n", elemento_cercato->num, elemento_cercato->next);
    }
    else {
        puts("L'elemento non si trova nella lista");
    }

    // puts("Lista stampata ricorsivamente:");
    // stampa_lista_al_contrario_ricorsiva(lista);
    // puts("");

    elimina_lista(lista);
    return 0;

}

Nodo *crea_lista(size_t dim)
{

    srand(time(NULL));

    Nodo *lista = NULL;

    lista = (Nodo*)malloc(sizeof(Nodo));

    if (lista != NULL) {
        lista->num = (rand() % 20) + 1;
        lista->next = NULL;

        Nodo *current = lista;
        for (int i = 0; i < dim - 1; i++) {

            Nodo *new = NULL;
            new = (Nodo*)malloc(sizeof(Nodo));

            if (new != NULL) {
                new->num = (rand() % 20) + 1;
                new->next = NULL;
            }
            current->next = new;
            current = current->next;

        }
    }

    return lista;

}

void elimina_lista(Nodo *lista)
{
    while (lista != NULL) {
        Nodo *tmp = lista;
        lista = lista->next;
        free(tmp);
    }
}

void stampa_lista_al_contrario_ricorsiva(Nodo *lista)
{
    if (lista->next == NULL) {
        printf("%d", lista->num);
    }
    else {
        stampa_lista_al_contrario_ricorsiva(lista->next);
        printf(" %d", lista->num);
    }
}

Nodo *cerca_valore(Nodo *lista, int numero)
{

    while (lista != NULL && lista->num != numero) {

        lista = lista->next;

    }

    return lista;
}

void stampa_lista(Nodo *lista) {
    puts("Stampa lista normale");
    while (lista != NULL) {
        printf("%d ", lista->num);
        lista = lista->next;
    }
    puts("");
}