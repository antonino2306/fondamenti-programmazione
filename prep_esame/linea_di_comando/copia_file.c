#include <stdio.h>

void copia_file(FILE *input, FILE *output);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        puts("Inserisci il percorso del file da copiare");
        return -1;
    }

    FILE *fp_input = NULL;

    if ((fp_input = fopen(argv[1], "r")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    FILE *fp_output = NULL;

    if ((fp_output = fopen("output.txt", "w")) == NULL) {
        puts("Errore nell'apertura del file");
        fclose(fp_input);
        return -1;
    }

    copia_file(fp_input, fp_output);
    fclose(fp_input);
    fclose(fp_output);

}

void copia_file(FILE *input, FILE *output)
{
    char c;

    while ((c = getc(input)) != EOF) {
        fprintf(output, "%c", c);
    }

    // fprintf(output, "%c", EOF);
}
