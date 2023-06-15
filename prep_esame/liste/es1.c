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
int somma_multipli(Nodo *lista, unsigned int m);
void scrivi_lista_su_file(FILE *fp, Nodo *lista);

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        puts("Inserisci percorso file");
        return -1;
    }

    FILE *fp = NULL;

    if ((fp = fopen(argv[1], "a")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    Nodo *lista = NULL;

    size_t lunghezza;
    puts("Inserisci la lunghezza della lista");
    scanf("%lu", &lunghezza);

    lista = crea_lista(lunghezza);
    stampa_lista(lista);

    scrivi_lista_su_file(fp, lista);

    unsigned int molt;
    int somma;
    puts("Inserisci il numero di cui vuoi sommare i multipli: ");
    scanf("%u", &molt);


    somma = somma_multipli(lista, molt);
    printf("La somma dei multipli di %u è %d\n", molt, somma);

    elimina_lista(lista);
    fclose(fp);
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

int somma_multipli(Nodo *lista, unsigned int m)
{
    if (lista == NULL) {
        return -1;
    }

    unsigned int somma = 0;
    while (lista != NULL) {
        if (lista->num % m == 0) {
            somma += lista->num;
        }
        lista = lista->next;
    }
    return somma;
}

void scrivi_lista_su_file(FILE *fp, Nodo *lista)
{
    while (lista != NULL) {
        fprintf(fp, "%u ", lista->num);
        lista = lista->next;
    }
    fputc('\n', fp);
}
