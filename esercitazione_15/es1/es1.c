#include <stdio.h>
#include <stdlib.h>

struct _nodo {
    int num;
    struct _nodo *next;
};

typedef struct _nodo Nodo;


void stampa_menu();
void stampa_lista(Nodo *head);
void libera_lista(Nodo *head);
Nodo *inserisci_in_ordine(Nodo *head);
unsigned int conta_occorrenze(Nodo* head, int numero);
Nodo *rimuovi_per_valore(Nodo *head, int numero);
Nodo *eleva_al_quadrato(Nodo *head);

int main() {

    Nodo *head = NULL;

    char input;
    
    do {
        stampa_menu();
        scanf(" %c", &input);

        switch (input)
        {
        case 'a':
            head = inserisci_in_ordine(head);
            stampa_lista(head);
            break;
        
        case 'b':
            int numero;
            puts("Inserisci il numero da cercare");
            scanf("%d", &numero);
            unsigned int occorrenze = conta_occorrenze(head, numero);
            printf("Il numero è presente %u volte\n", occorrenze);
            break;
        
        case 'c':
            int numero_da_eliminare;
            puts("Inserisci il numero da rimuovere");
            scanf("%d", &numero_da_eliminare);
            head = rimuovi_per_valore(head, numero_da_eliminare);
            stampa_lista(head);
            break;
        
        case 'd':
            head = eleva_al_quadrato(head);
            stampa_lista(head);
            break;
        
        default:
            break;
        }
    } while (input != 'q');

    libera_lista(head);
}

void stampa_menu() {
    puts("Premi a per inserire un nuovo numero nella lista ordinata");
    puts("Premi b per contare quante volte è presente un determinato numero");
    puts("Premi c per eliminare tutti gli elementi che hanno un determinato valore");
    puts("Premi d per elevare al quadrato tutti gli elementi della lista ordinata");
    puts("Premi q per terminare il programma");
    printf("%s", "> ");
}

void stampa_lista(Nodo *head)
{
    while (head != NULL) {
        printf("%d ", head->num);
        head = head->next;
    }
    puts("");
}

void libera_lista(Nodo *head)
{
    while (head != NULL) {
        Nodo *tmp = head;
        head = head->next;
        free(tmp);
    }
}

Nodo *inserisci_in_ordine(Nodo *head)
{

    if (head == NULL) {
        head = (Nodo*)malloc(sizeof(Nodo));
        puts("Inserisci il primo elemento della lista");
        scanf("%d", &(head->num));
        head->next = NULL;
    }
    else {
        Nodo *new = NULL;
        new = (Nodo*)malloc(sizeof(Nodo));

        if (new != NULL) {
            puts("Inserisci un numero intero");
            scanf("%d", &(new->num));
            new->next = NULL;
            
            
            if (new->num < head->num) {
                new->next = head;
                head = new;
            }
            else {
                int posizione_trovata = 0;
                
                Nodo *corrente = head, *precedente = NULL;
                
                while (corrente != NULL && !posizione_trovata) {
                    
                    if (new->num < corrente->num) {
                        posizione_trovata = 1;
                    }
                    else {
                        precedente = corrente;
                        corrente = corrente->next;
                    }

                }

                precedente->next = new;
                new->next = corrente;
            }

        }

    }

    return head;
    
}

unsigned int conta_occorrenze(Nodo *head, int numero)
{
    unsigned int conta = 0;

    while (head != NULL) {

        if (numero == head->num) {
            conta++;
        }
        head = head->next;

    }

    return conta;
}

Nodo *rimuovi_per_valore(Nodo *head, int numero)
{

    if (head != NULL) {


        if (head->num == numero) {

            while (head != NULL && head->num == numero) {
                Nodo *tmp = head;
                head = head->next;
                free(tmp);
            }

        }
        else {

            Nodo *corrente = head, *precedente = NULL;

            while (corrente != NULL) {

                if (corrente->num == numero) {
                    corrente = corrente->next;
                    free(precedente->next);
                    precedente->next = corrente;
                }
                else {
                    precedente = corrente;
                    corrente = corrente->next;
                }

            }
        }

    }

    return head;
}

Nodo *eleva_al_quadrato(Nodo *head)
{
    Nodo *tmp = head;

    while (tmp != NULL) {
        tmp->num *= tmp->num;
        tmp = tmp->next;
    }
    return head;
}

