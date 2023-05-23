#include <stdio.h>

void leggi_lista(FILE *fp);

int main(int argc, char *argv[]) {

    FILE *fp;

    if (argc < 2) {
        puts("Inserisci il percorso del file");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    leggi_lista(fp);

    rewind(fp);

    leggi_lista(fp);

    fclose(fp);
    return 0;

}

void leggi_lista(FILE *fp)
{
    char str[50];

    while (fscanf(fp, " %[^,\n]", str) != EOF) {
        getc(fp);
        printf("%s\n", str);
    }
    puts("----------------------------");
}
