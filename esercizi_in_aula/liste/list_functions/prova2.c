#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define ALPHABETH 26


int main() {

    Node *head = NULL;

    // Crea una lista di 5 elementi e la inizializza
    head = init_list(ALPHABETH);

    print_list_ric(head);

    // head = remove_head(head);
    // head = remove_tail(head);
    char el;
    puts("Inserisci carattere da rimuovere");
    scanf("%c", &el);
    head = remove_by_value(head, el);
    head = insert_head(head, 33);

    print_list(head);

    free_list(head);
}

