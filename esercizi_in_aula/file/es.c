#include <stdio.h>

int main(int argc, char* argv[]) {

    FILE *fp;
    int x;

    if (argc < 2) {
        printf("Devi passare il nome del file da aprire\n");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    fscanf(fp, "%d", &x);

    printf("Valore letto = %d\n", x);

    fclose(fp);

    return 0;

}