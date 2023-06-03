#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *init_list(unsigned int list_length)
{

    Node *head = (Node*)malloc(sizeof(Node));

    if (head != NULL) {

        head->letter = 'a';
        head->next = NULL;

        Node *tmp = head;

        for (int i = 1; i < list_length; i++) {

            Node *new = NULL;
            new = (Node*)malloc(sizeof(Node));

            if (new != NULL) {
                new->letter = head->letter + i;
                new->next = NULL;

                tmp->next = new;

                tmp = tmp->next;
            }
            else {
                puts("Error in malloc");
            }

        }

    }


    return head;
}

void print_list(Node *head)
{
    while (head != NULL) {
        printf("%c ", head->letter);
        head = head->next;
    }
    puts("");
}

void free_list(Node *head)
{
    Node *tmp = NULL;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

Node *insert_head(Node *head, int value)
{

    if (head != NULL) {

        Node *new = (Node*)malloc(sizeof(Node));

        if (new != NULL) {
            
            new->letter = value;
            new->next = head;

            head = new;
        }

    }

    return head;
}

Node *remove_head(Node *head)
{
    if (head != NULL) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}

Node *remove_tail(Node *head) {

    if (head != NULL) {
        Node *current = head, *previous = NULL;

        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        free(current);
        previous->next = NULL;

    }

    return head;
}

Node *remove_by_value(Node *head, char element) {

    if (head != NULL) {

        Node *current = head, *previous = NULL;

        // L'elemento si trova in testa
        if (current->letter == element) {
            head = remove_head(head);
        }
        else {

            while (current != NULL && current->letter != element) {
                previous = current;
                current = current->next;
            }

            if (current != NULL) {
                previous->next = current->next;
                free(current);
            }
            else {
                puts("The element wasn't in the list");
            }

        }

    }


    return head;
}

void print_list_ric(Node *head) {
    if (head == NULL) {
        puts("");
        return;
    }
    else {
        printf("%c ", head->letter);
        print_list_ric(head->next);

    }
}