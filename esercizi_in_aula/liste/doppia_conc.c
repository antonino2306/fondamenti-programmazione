#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int value;
    struct nodo *prec;
    struct nodo *succ;
};

typedef struct nodo Nodo;

void insertAfterHead(Nodo *head, int v);
Nodo *deleteByValue(Nodo *head, int v);

int main() {
    return 0;
}

void insertAfterHead(Nodo *head, int v)
{
    Nodo *new = NULL;
    new = (Nodo*)malloc(sizeof(Nodo));

    if (new != NULL) {

        new->value = v;
        if (head != NULL) {
            new->prec = head;
            new->succ = head->succ;
            head->succ = new;
            // Controllo che serve per evitare segmentation fault
            if (new->succ != NULL) {
                new->succ->prec = new;
            }
        }

    }
}

Nodo *deleteByValue(Nodo *head, int v)
{
    //* Se il nodo è in testa
    if (head != NULL) {

        if (head->value == v) {
            Nodo *tmp = head;
            head = head->succ;
            free(tmp);

            if (head != NULL) {
                head->prec = NULL;
            }
        }
        else {
            Nodo *current = head;

            while (current != NULL && current->value != v) {
                current = current->succ;
            }

            // Il while termina perché viene trovato il valore
            if (current != NULL) {
                (current->prec)->succ = current->succ;

                if (current->succ != NULL) {
                    (current->succ)->prec = current->prec;
                }
                free(current);
            }
        }
    }

    return head;
}
