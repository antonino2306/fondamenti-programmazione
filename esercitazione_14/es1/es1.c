#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *fp;

    if (argc < 2) {
        puts("Devi inserire il percorso del file");
        return -1;
    }

    if ((fp = fopen(argv[1], "a")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    puts("File aperto correttamente");

    fclose(fp);

    return 0;

}