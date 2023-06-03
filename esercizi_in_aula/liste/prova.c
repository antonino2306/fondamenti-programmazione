#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int num;
    struct nodo *next;
};

typedef struct nodo Nodo;

Nodo *create_list(int value);
void add_in_tail(Nodo *list_ptr, int value);
void print_list(Nodo *list_ptr);
void free_list(Nodo* head);
Nodo *merge_lists(Nodo *list_ptr1, Nodo *list_ptr2);
void free_list_ric(Nodo *head);

int main() {

    Nodo *head = create_list(-1);
    Nodo *head2 = create_list(-1);

    for (int i = 0; i < 10; i++) {
        add_in_tail(head, i);
        add_in_tail(head2, 2*i);
    }

    // print_list(head);
    // print_list(head2);
    
    head = merge_lists(head, head2);
    puts("");
    print_list(head);

    free_list(head);
    free_list(head2);

    // print_list(head);
}

//? Funzione che crea la lista
Nodo *create_list(int value)
{

    Nodo *start_ptr = NULL;

    start_ptr = (Nodo*)malloc(sizeof(Nodo));

    if (start_ptr != NULL) {

        start_ptr->num = value;
        start_ptr->next = NULL;

    }
    else {
        puts("Error in memory allocation");
    }

    return start_ptr;
    
}

void add_in_tail(Nodo *list_ptr, int value)
{

    Nodo *new = NULL;
    new = (Nodo*)malloc(sizeof(Nodo));

    if (new != NULL) {
        new->num = value;
        new->next = NULL;
    
        while (list_ptr->next != NULL) {
            list_ptr = list_ptr->next;
        }

        list_ptr->next = new;
    }
    else {
        puts("Error: no memory avaible");
    }


}

void print_list(Nodo *list_ptr)
{
    while (list_ptr != NULL) {
        printf("%d\n", list_ptr->num);
        list_ptr = list_ptr->next;
    }
}

void free_list(Nodo *head)
{
    while (head != NULL) {
        Nodo *tmp_ptr = head;
        head = head->next;
        free(tmp_ptr);
    }
}

Nodo *merge_lists(Nodo *list_ptr1, Nodo *list_ptr2)
{

    if (list_ptr1 != NULL) {
        Nodo *tmp = list_ptr1;

        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = list_ptr2;

    }
    else {
        list_ptr1 = list_ptr2;
    }
    return list_ptr1;
}

void free_list_ric(Nodo *head)
{
    if (head != NULL) {
        if (head->next == NULL) {
            free(head);
        }
        else {
            free_list_ric(head->next);
            free(head);
        }
    }
}
