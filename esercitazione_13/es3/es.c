#include <stdio.h>
#define MAXLENGHT 30

struct pietanza {

    char nome[MAXLENGHT];
    char **ingredienti;
    unsigned int *dosi;
    unsigned int tempo_cottura;
    char tipo_piatto[10];

};

typedef struct pietanza Pietanza;

int main(int argc, char *argv[]) {

    FILE *fp;
    Pietanza *ricettario;

   

    

}