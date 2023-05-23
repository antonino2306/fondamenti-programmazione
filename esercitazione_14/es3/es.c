#include <stdio.h>
#define SIZE 30

struct _alunno {
    
    char nome[SIZE];
    char cognome[SIZE];
    unsigned int voto;

};

typedef struct _alunno Alunno;

int main(int argc, char *argv[]) {

    Alunno a;
    FILE *fp;

    if (argc < 2) {
        puts("Inserisci il percorso del file");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    fscanf(fp, " %30[^,], %30[^,], %u", a.nome, a.cognome, &(a.voto));
    printf("nome: %s cognome: %s voto: %u\n", a.nome, a.cognome, a.voto);

    fclose(fp);
    return 0;
}