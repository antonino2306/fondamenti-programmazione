#include <stdio.h>
#include <string.h>

#define MAXLENGHT 100

void trova_parole_comuni(FILE *input1, FILE *input2, FILE *out);

int main(int argc, char *argv[]) {

    if (argc < 3) {
        puts("Inserisci i percorsi dei due file da confrontare");
        return -1;
    }

    FILE *fp1 = NULL, *fp2 = NULL;

    if ((fp1 = fopen(argv[1], "r")) == NULL || (fp2 = fopen(argv[2], "r")) == NULL) {
        puts("Errore nell'apertura dei file");
        return -1;
    }

    FILE *output = NULL;

    if ((output = fopen("comuni.txt", "w")) == NULL) {
        puts("Errore nell' apertura del file di output");
        return -1;
    } 

    trova_parole_comuni(fp1, fp2, output);

    fclose(fp1);
    fclose(fp2);
    fclose(output);

}

void trova_parole_comuni(FILE *input1, FILE *input2, FILE *out)
{

    char tmp1[MAXLENGHT], tmp2[MAXLENGHT];

    while(fscanf(input1, "%s", tmp1) != EOF) {
        int trovato = 0;

        while (fscanf(input2, "%s", tmp2) != EOF && !trovato) {
            
            if (strcmp(tmp1, tmp2) == 0) {
                fprintf(out, "%s ", tmp1);
                trovato = 1;
            }

        }
        rewind(input2);

    }
    
    fprintf(out, "\n");
}
