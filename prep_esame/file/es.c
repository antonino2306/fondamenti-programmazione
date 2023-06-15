// Ricerca di una parola in un file di testo
#include <stdio.h>
#include <string.h>
#define MAXLENGHT 50

unsigned int conta_occorrenze(FILE *fp, char parola[]);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        puts("Inserire percorso file");
        return -1;
    }

    char parola[MAXLENGHT + 1];

    puts("Inserisci la parola da cercare");
    scanf(" %s", parola);

    FILE *fp = NULL;

    if  ((fp = fopen(argv[1], "r")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    unsigned int num_occorrenze = conta_occorrenze(fp, parola);

    printf("La parola %s è presente %u volte nel file\n", parola, num_occorrenze);
    
    fclose(fp);
    return 0;

}

unsigned int conta_occorrenze(FILE *fp, char parola[])
{
    unsigned int conta = 0;
    char tmp[MAXLENGHT + 1];

    while (fscanf(fp, "%s", tmp) != EOF) {

        if (strcmp(parola, tmp) == 0) {
            conta++;
        }

    }
    return conta;
}
