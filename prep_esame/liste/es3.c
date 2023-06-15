#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXLENGTH 100

struct nodo
{
    int num;
    struct nodo *succ;
};
typedef struct nodo Nodo;

void riempi_vettore(int v[], size_t dim);
void stampa_vettore(const int v[], size_t dim);
void copia_vettore_in_lista(const int v[], Nodo **lista, size_t dim_v);
void stampa_lista_al_contrario(Nodo *lista);
void elimina_lista(Nodo *lista);



int main() {

    int v[MAXLENGTH];
    size_t dim;

    puts("Inserisci la dimensione del vettore");
    scanf("%lu", &dim);

    riempi_vettore(v, dim);
    stampa_vettore(v, dim);

    Nodo *lista = NULL;
    copia_vettore_in_lista(v, &lista, dim);

    if (lista != NULL) {
        stampa_lista_al_contrario(lista);
        puts("");
    }
    else {
        puts("Vettore vuoto");
    }

    elimina_lista(lista);

}

void riempi_vettore(int v[], size_t dim)
{
    srand(time(NULL));

    for (size_t i = 0; i < dim; i++) {
        v[i] = rand() % 100 + 1;
    }
}

void copia_vettore_in_lista(const int v[], Nodo **lista, size_t dim_v)
{
    if (dim_v == 0) {
        puts("Il vettore è vuoto");
    }
    else {
        if (*lista == NULL) {

            //Crea il primo nodo
            *lista = (Nodo*)malloc(sizeof(Nodo));

            if (*lista != NULL) {
                (*lista)->num = v[0];
                (*lista)->succ = NULL;
            }

        }
        
        Nodo *scorri_lista = *lista;

        for (size_t i = 1; i < dim_v; i++) {
            
            Nodo *nuovo = NULL;

            nuovo = (Nodo*)malloc(sizeof(Nodo));

            if (nuovo != NULL) {
                nuovo->num = v[i];
                nuovo->succ = NULL;
                scorri_lista->succ = nuovo;
                scorri_lista = scorri_lista->succ;
            }

        }
        
    }
}

void stampa_lista_al_contrario(Nodo *lista)
{
    if (lista->succ != NULL) {
        stampa_lista_al_contrario(lista->succ);
    }
    printf("%d ", lista->num);
}

void stampa_vettore(const int v[], size_t dim)
{
    for (size_t i = 0; i < dim; i++) {
        printf("%d ", v[i]);
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