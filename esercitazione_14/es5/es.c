#include <stdio.h>
#include <stdlib.h>

void scrivi_su_file(FILE *fp);


int main(int argc, char *argv[]) {

    FILE *fp;

    if (argc < 2) {
        puts("Inserisci il percorso del file");
        return -1;
    }

    if ((fp = fopen(argv[1], "w")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    scrivi_su_file(fp);

    fclose(fp);

    return 0;

}

void scrivi_su_file(FILE *fp)
{
    int continua = 1;

    do {

        int numero;
        
        puts("Inserisci un numero:");
        scanf("%d", &numero);

        fprintf(fp, "%d ", numero);

        puts("Premere 0 per smettere di inserire, altrimenti 1");
        scanf("%d", &continua);

    } while (continua);
}
