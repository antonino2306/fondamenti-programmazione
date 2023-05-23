#include <stdio.h>
#define SIZE 100

void stampa_lista_da_file(FILE *fp);

int main(int argc, char* argv[]) {

    FILE *fp;
    int continua = 1;
    char s[SIZE];

    if (argc < 2) {
        printf("Devi passare il percorso del file\n");
        return -1;
    }


    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Errore nell'apertura del file\n");
        return -1;
    }

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
    while (fscanf(fp, " %99[^,\n]", s) != EOF) {
        fgetc(fp);
        printf("%s\n", s);
    }

}
