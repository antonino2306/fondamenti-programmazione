#include <stdio.h>
#define SIZE 100

void scrivi_lista_su_file(FILE *fp);
void stampa_lista_da_file(FILE *fp);

int main(int argc, char* argv[]) {

    FILE *fp;
    int continua = 1;
    char s[SIZE];

    if (argc < 2) {
        printf("Devi passare il percorso del file\n");
        return -1;
    }

    if ((fp = fopen(argv[1], "w+")) == NULL) {
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    scrivi_lista_su_file(fp);

    stampa_lista_da_file(fp);

    fclose(fp);

    return 0;

}

void stampa_lista_da_file(FILE *fp)
{

    if (fp == NULL) {
        puts("Tentativo di usare la funzione su un puntatore null");
        return;
    }

    rewind(fp);

    char s[100];

    puts("Contenuto della lista:");
    while (fscanf(fp, " %99[^, \n]", s) != EOF) {
        getc(fp);
        printf("%s\n", s);
    }

}

void scrivi_lista_su_file(FILE *fp)
{

    int continua = 1;
    char str[SIZE];

    while (continua) {

        puts("Inserisci un nuovo elemento nella lista della spesa:");
        scanf(" %99[^\n]", str);

        fprintf(fp, "%s, ", str);

        puts("Se hai concluso inserisci 0: ");
        scanf("%d", &continua);

    }

}
