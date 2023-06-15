#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEL_MAX 10
#define MAX_LENGHT 40


struct contatto {
    char *nome;
    char *cognome;
    char num_telefono[TEL_MAX + 1];
    struct contatto *prev;
    struct contatto *succ;
};

typedef struct contatto Contatto;

void stampa_menu();
void carica_contatti_da_file(FILE *fp, Contatto **rubrica, unsigned int *num_contatti);
void inserisci_in_lista(Contatto **rubrica, char nome[], char cognome[], char telefono[]);
void elimina_rubrica(Contatto *rubrica, size_t num_contatti);
void scorri_rubrica(Contatto *rubrica);
int aggiungi_contatto(Contatto *rubrica, int *num_contatti, char nome_file[]);
void inserisci_dati(char nome[], char cognome[], char telefono[]);
void scrivi_su_file(FILE *fp, char nome[], char cognome[], char telefono[]);
void rimuovi_contatto(Contatto **rubrica, char telefono[], unsigned int *num_contatti);

int main(int argc, char *argv[]) {

    // Controlla gli argomenti da riga di comando e apri il file
    FILE *fp;

    if (argc < 2) {
        puts("Inserisci il percorso del file");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    //Carica tutt i contatti presenti nella rubrica in una lista circolare;
    Contatto *rubrica = NULL;
    unsigned int numero_contatti = 0;

    carica_contatti_da_file(fp, &rubrica, &numero_contatti);

    int input;

    do
    {
        stampa_menu();
        scanf(" %d", &input);

        switch (input)
        {
        case 1:
            scorri_rubrica(rubrica);
            break;
        
        case 2:
            
            if (aggiungi_contatto(rubrica, &numero_contatti, argv[1])) {
                puts("Contatto aggiunto correttamente");
            }
            else {
                puts("Errore nell'aggiunta del contatto");
            }
            break;

        case 3: 
            // Elimina un contatto ma non dal file
            char tel[TEL_MAX + 1];
            puts("Inserisci il numero da rimuovere");
            scanf(" %[0123456789]", tel);
            printf("%s\n", tel);
            rimuovi_contatto(&rubrica, tel, &numero_contatti);
        default:
            break;
        }
        
    } while (input != -1);


    elimina_rubrica(rubrica, numero_contatti);

}

void stampa_menu() {
    puts("Premi 1 per scorrere i contatti");
    puts("Premi 2 per aggiungere un nuovo contatto");
    puts("Premi 3 per rimuovere un contatto");
    puts("Premi -1 per uscire");
    printf("> ");
}

void inserisci_in_lista(Contatto **rubrica, char nome[], char cognome[], char telefono[])
{
    if (*rubrica == NULL) {

        *rubrica = (Contatto*)malloc(sizeof(Contatto));

        if (*rubrica != NULL) {
            
            (*rubrica)->nome = (char*)malloc(sizeof(strlen(nome)+1));
            (*rubrica)->cognome = (char*)malloc(sizeof(strlen(cognome)+1));
            
            strcpy((*rubrica)->nome, nome);
            strcpy((*rubrica)->cognome, cognome);
            strcpy((*rubrica)->num_telefono, telefono);
            
            (*rubrica)->prev = *rubrica;
            (*rubrica)->succ = *rubrica;
        }

    }
    else {
        Contatto *nuovo = NULL;
        
        nuovo = (Contatto*)malloc(sizeof(Contatto));

        if (nuovo != NULL) {

            nuovo->nome = (char*)malloc(sizeof(strlen(nome)+1));
            nuovo->cognome = (char*)malloc(sizeof(strlen(cognome)+1));

            strcpy(nuovo->nome, nome);
            strcpy(nuovo->cognome, cognome);
            strcpy(nuovo->num_telefono, telefono);

            nuovo->succ = *rubrica;
            nuovo->prev = (*rubrica)->prev;
            if ((*rubrica)->prev != NULL) {
                (*rubrica)->prev = nuovo;
                nuovo->prev->succ = nuovo;
            }


        }
    }
    
}

void carica_contatti_da_file(FILE *fp, Contatto **rubrica, unsigned int *num_contatti)
{
    char nome[MAX_LENGHT], cognome[MAX_LENGHT], tel[MAX_LENGHT+1];

    while (fscanf(fp, "%[^,]", nome) != EOF) {
        
        fgetc(fp);
        fscanf(fp, "%[^,]", cognome);
        fgetc(fp);
        fscanf(fp, "%10s", tel);
        fgetc(fp);
             
        inserisci_in_lista(rubrica, nome, cognome, tel);
        (*num_contatti)++;
    }

    fclose(fp);
}

void elimina_rubrica(Contatto *rubrica, size_t num_contatti)
{
    int i = 0;
    while (i < num_contatti) {
        Contatto *tmp = rubrica;
        rubrica = rubrica->succ;
        free(tmp->nome);
        free(tmp->cognome);
        free(tmp);

        i++;
    }
}

void rimuovi_contatto(Contatto **rubrica, char telefono[], unsigned int *num_contatti)
{

    if (*rubrica != NULL) {

        if (strcmp((*rubrica)->num_telefono, telefono) == 0) {
            // Rimuovo il primo elemento
            Contatto *tmp = *rubrica;
            
            if (*num_contatti > 1) {
                (*rubrica)->prev->succ = (*rubrica)->succ;
            
                (*rubrica)->succ->prev = (*rubrica)->prev;
                
                *rubrica = (*rubrica)->succ;
            }

            free(tmp);
            (*num_contatti)--;
        }
        else {

            Contatto *scorri_lista = *rubrica;

            int i = 0;
            while (i < *num_contatti && strcmp(scorri_lista->num_telefono, telefono) != 0) {
                scorri_lista = scorri_lista->succ;
                i++;
            }

            printf("%d %u\n", i, *num_contatti);

            if (i < *num_contatti) {

                Contatto *tmp = scorri_lista;

                scorri_lista->prev->succ = scorri_lista->succ;
                scorri_lista->succ->prev = scorri_lista->prev;

                free(tmp);
                (*num_contatti)--;

            }
            else {
                puts("Numero non in rubrica");
            }

        }

        if (*num_contatti == 0) {
            *rubrica = NULL;
        }
 
    }

}

void scorri_rubrica(Contatto *rubrica) {

    puts("Premi A per andare indietro, D per andare avanti. Premi Q per tornare indietro");

    int continua = 1;
    char c;
    do {

        printf("%s %s %s\n", rubrica->nome, rubrica->cognome, rubrica->num_telefono);
        printf("> ");
        scanf(" %c", &c);


        switch (c)
        {
        case 'a': case 'A':
            rubrica = rubrica->succ;
            break;
        
        case 'd': case 'D':
            rubrica = rubrica->prev;
            break;

        case 'q': case 'Q':
            continua = 0;
            break;
        default:
            break;
        }

    } while (continua);

}

int aggiungi_contatto(Contatto *rubrica, int *num_contatti, char nome_file[])
{
    FILE *fp;

    if ((fp = fopen(nome_file, "a")) == NULL) {
        return 0;
    }

    char nome[MAX_LENGHT], cognome[MAX_LENGHT], tel[TEL_MAX+1];

    inserisci_dati(nome, cognome, tel);

    inserisci_in_lista(&rubrica, nome, cognome, tel);
    scrivi_su_file(fp, nome, cognome, tel);

    fclose(fp);

    *num_contatti++;

    return 1;
}

void inserisci_dati(char nome[], char cognome[], char telefono[])
{
    printf("%s", "Nome: ");
    scanf(" %39[^\n]", nome);

    printf("%s", "Cognome: ");
    scanf(" %39[^\n]", cognome);

    printf("%s", "Telefono: ");
    scanf(" %10s", telefono);

}

void scrivi_su_file(FILE *fp, char nome[], char cognome[], char telefono[])
{
    fprintf(fp, "%s,%s,%s\n", nome, cognome, telefono);
}
