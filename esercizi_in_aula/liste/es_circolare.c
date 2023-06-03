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
void free_list(Student *head, size_t num_elementi);
Student *insert_element(Student *head, char mat[], char nome[], char cognome[], size_t *num_elementi);
Student *delete_by_mat_number(Student *head, char mat[], size_t *num_elementi);
void print_list(Student *head, size_t num_elementi);
void search_by_mat_number(Student *head, char mat[], size_t num_elementi);

int main() {

    Student *list = NULL;
    size_t num_elementi = 0;

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
            list = insert_element(list, mat, nome, cognome, &num_elementi);
            break;

        case 2:
            puts("Inserisci il numero di matricola dello studente da eliminare");
            scanf(" %7s", mat);
            list = delete_by_mat_number(list, mat, &num_elementi);
            break;
        
        case 3:
            puts("Inserisci il numero di matricola");
            scanf(" %7s", mat);
            search_by_mat_number(list, mat, num_elementi);
            break;
        
        default:
            break;
        }

        print_list(list, num_elementi);
    } while (input != 4);


    free_list(list, num_elementi);
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

void free_list(Student *head, size_t num_elementi)
{
    for (size_t i = 0; i < num_elementi; i++) {

        Student *tmp = head;
        head = head->next;
        free(tmp);
        
    }
}

Student *insert_element(Student *head, char mat[], char nome[], char cognome[], size_t *num_elementi)
{
    if (head == NULL) {
        // Crea il primo elemento;
        head = (Student*)malloc(sizeof(Student));
        
        // Se l'allocazione di memoria è riuscita inizializzo i campi
        if (head != NULL) {
            strcpy(head->matricola, mat);
            strcpy(head->nome, nome);
            strcpy(head->cognome, cognome);
            head->next = head;
            head->prev = head;
            // ++ ha precedenza maggiore di *
            (*num_elementi)++;
        }
    }
    else {
        
        Student *new = NULL;
        new = (Student*)malloc(sizeof(Student));

        if (new != NULL) {

            strcpy(new->matricola, mat);
            strcpy(new->nome, nome);
            strcpy(new->cognome, cognome);

            new->next = head;
            new->prev = head->prev;
            head->prev = new;
            
            new->prev->next = new;
            
            (*num_elementi)++;
            
        }

    }
    
    return head;
}

Student *delete_by_mat_number(Student *head, char mat[], size_t *num_elementi)
{

    if (head != NULL) {

        if (strcmp(head->matricola, mat) == 0) {
            // Rimuovo l'elemento puntato da head
            Student *tmp = head;
            
            head->next->prev = head->prev;
        
            head->prev->next = head->next;
            
            head = head->next;
            free(tmp);
            (*num_elementi)--;
        }

    }
    else {
        int i = 0;
        Student *current = head;
        while (i < *num_elementi && strcmp(current->matricola, mat) != 0) {
            current = current->next;
            i++;
        }

        if (i < *num_elementi) {

            Student *tmp = current;

            current->next->prev = current->prev;

            current->prev->next = current->next;

            free(tmp);
            (*num_elementi)--;

        }
    }

    return head;
}

void print_list(Student *head, size_t num_elementi)
{
    for (size_t i = 0; i < num_elementi; i++) {
        
        printf("%s %s %s\n", head->matricola, head->nome, head->cognome);
        head = head->prev;

    }
}

void search_by_mat_number(Student *head, char mat[], size_t num_elementi)
{
    size_t i = 0;

    while (i < num_elementi && strcmp(head->matricola, mat) != 0) {
        head = head->next;
        i++;
    }

    if (i < num_elementi) {
        printf("%s %s\n", head->nome, head->cognome);
    }
    else {
        puts("Studente non presente in elenco");
    }
}
