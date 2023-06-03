#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGHT 30
#define MAT_SIZE 7

struct student {
    char matricola[MAT_SIZE + 1];
    char nome[MAXLENGHT];
    char cognome[MAXLENGHT];
    struct student *next;
    struct student *prev;
};

typedef struct student Student;

void print_menu();
void print_list(Student *head);
void free_list(Student *head);
void search_by_mat_number(Student *head, char mat[]);
Student *insert_element(Student *head, char mat[], char nome[], char cognome[]);
Student *delete_by_mat_number(Student *head, char mat[]);

int main() {

    Student *list = NULL;

    int input;

    do {

        char mat[MAT_SIZE + 1], nome[MAXLENGHT], cognome[MAXLENGHT];
        print_menu();
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            puts("Inserisci il numero di matricola, il nome e il cognome dello studente");
            scanf(" %7s %30s %30s", mat, nome, cognome);
            // scanf(" %30[^\n]", nome);
            // scanf(" %30[^\n]", cognome);
            list = insert_element(list, mat, nome, cognome);
            break;

        case 2:
            puts("Inserisci il numero di matricola dello studente da eliminare");
            scanf(" %7s", mat);
            list = delete_by_mat_number(list, mat);
            break;
        
        case 3:
            puts("Inserisci il numero di matricola");
            scanf(" %7s", mat);
            search_by_mat_number(list, mat);
            break;
        
        default:
            break;
        }

        print_list(list);
    } while (input != 4);


    free_list(list);
    return 0;
}

void print_menu()
{
    puts("Premi 1 per inserire un nuovo elemento");
    puts("Premi 2 per cancellare uno studente");
    puts("Premi 3 per cercare uno studente per matricola");
    puts("Premi 4 per uscire");
    printf("%s", "> ");
}

void print_list(Student *head)
{
    while (head != NULL) {
        printf("%s %s %s\n", head->matricola, head->nome, head->cognome);
        head = head->next;
    }
}

void free_list(Student *head)
{
    while (head != NULL) {
        Student *tmp = head;
        head = head->next;
        free(tmp);
    }
}

void search_by_mat_number(Student *head, char mat[])
{
    while (head != NULL && strcmp(head->matricola, mat) != 0) {
        head = head->next;
    }

    if (head != NULL) {
        printf("%s %s\n", head->nome, head->cognome);
    }
    else {
        puts("Studente non presente in elenco");
    }
}

Student *insert_element(Student *head, char mat[], char nome[], char cognome[]) {

    if (head == NULL) {

        head = (Student*)malloc(sizeof(Student));
        strcpy(head->matricola, mat);
        strcpy(head->nome, nome);
        strcpy(head->cognome, cognome);
        head->next = NULL;
        head->prev = NULL;

    }
    else {

        Student *new = NULL;
        new = (Student*)malloc(sizeof(Student));

        if (new != NULL) {

            strcpy(new->matricola, mat);
            strcpy(new->nome, nome);
            strcpy(new->cognome, cognome);

            new->next = head;
            new->prev = NULL;
            head->prev = new;
            head = new;
        } 

    }

    return head;

}

Student *delete_by_mat_number(Student *head, char mat[]) {

    if (head != NULL) {

        if (strcmp(head->matricola, mat) == 0) {
            // Rimuovi il primo elemento
            
            Student *tmp = head;
            head = head->next;
            free(tmp);

            if (head != NULL) {
                head->prev = NULL;
            }
        }
        else {
            
            Student *current = head;

            while (current != NULL && strcmp(current->matricola, mat) != 0) {
                current = current->next;
            }

            if (current != NULL) {

                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                free(current);

            }
        }

    }

    return head;
}