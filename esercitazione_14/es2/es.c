#include <stdio.h>

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

    int x, y;
    fscanf(fp, "%d %d", &x, &y);
    printf("x: %d, y: %d\n", x, y);

    fclose(fp);
    return 0;


}