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

void inserisci_in_lista(Contatto **rubrica, char nome[], char cognome[], char telefono[]);
void elimina_rubrica(Contatto *rubrica);
void scorri_rubrica(Contatto *rubrica);
int aggiungi_contatto(Contatto *rubrica, int *num_contatti, char nome_file[]);
void inserisci_dati(char nome[], char cognome[], char telefono[]);
void scrivi_su_file(FILE *fp, char nome[], char cognome[], char telefono[]);

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

    char nome[MAX_LENGHT], cognome[MAX_LENGHT], tel[MAX_LENGHT+1];

    while (fscanf(fp, "%[^,]", nome) != EOF) {
        
        fgetc(fp);
        fscanf(fp, "%[^,]", cognome);
        fgetc(fp);
        fscanf(fp, "%10s", tel);
        fgetc(fp);
             
        inserisci_in_lista(&rubrica, nome, cognome, tel);
        numero_contatti++;
    }

    fclose(fp);

    scorri_rubrica(rubrica);

    if (aggiungi_contatto(rubrica, &numero_contatti, argv[1])) {
        puts("Contatto aggiunto correttamente");
    }
    else {
        puts("Errore nell'aggiunta del contatto");
    }


    scorri_rubrica(rubrica);


    elimina_rubrica(rubrica);

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
            
            (*rubrica)->prev = NULL;
            (*rubrica)->succ = NULL;
        }

    }
    else {
        Contatto *nuovo = NULL;
        Contatto *corrente = *rubrica, *precedente = NULL;

        nuovo = (Contatto*)malloc(sizeof(Contatto));

        if (nuovo != NULL) {

            nuovo->nome = (char*)malloc(sizeof(strlen(nome)+1));
            nuovo->cognome = (char*)malloc(sizeof(strlen(cognome)+1));

            strcpy(nuovo->nome, nome);
            strcpy(nuovo->cognome, cognome);
            strcpy(nuovo->num_telefono, telefono);

            
            if (nuovo->nome[0] < corrente->nome[0]) {
                // Inserisco in testa
                nuovo->succ = *rubrica;
                (*rubrica)->prev = nuovo;
                nuovo->prev = NULL;
                *rubrica = nuovo;
            }

            while (corrente != NULL && nuovo->nome[0] > corrente->nome[0]) {

                precedente = corrente;
                corrente = corrente->succ;

            }

            if (corrente == NULL) {
                // Inserisco in coda alla lista
                precedente->succ = nuovo;
                nuovo->prev = precedente;
                nuovo->succ = NULL;
            }
            else {
                //Inserisco il nodo in mezzo alla lista
                nuovo->succ = corrente->succ;
                if (corrente->succ != NULL) {
                    corrente->succ->prev = nuovo;
                }
                nuovo->prev = corrente;
                corrente->succ = nuovo;
            }


        }
    }
    
}

void elimina_rubrica(Contatto *rubrica)
{

    while (rubrica != NULL) {
        Contatto *tmp = rubrica;
        rubrica = rubrica->succ;
        free(tmp->nome);
        free(tmp->cognome);
        free(tmp);

    }
}

void scorri_rubrica(Contatto *rubrica) {

    puts("Premi A per andare indietro, D per andare avanti");

    int continua = 1;
    char c;
    do {

        printf("%s %s %s\n", rubrica->nome, rubrica->cognome, rubrica->num_telefono);
        printf("> ");
        scanf(" %c", &c);


        switch (c)
        {
        case 'a': case 'A':
            if (rubrica->prev != NULL) {
                rubrica = rubrica->prev;
            }
            else {
                puts("Vai avanti");
            }
            break;
        
        case 'd': case 'D':
            if (rubrica->succ != NULL) {
                rubrica = rubrica->succ;
            }
            else {
                puts("Vai indietro");
            }
            break;

        case 'q':
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
