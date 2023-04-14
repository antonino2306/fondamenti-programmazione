// Definire e implementare in C un programma che permetta di stabilire (utilizzando il costrutto switch) la
// stagione corrispondente al mese inserito come intero dall’utente. Qualora il mese sia Marzo, Giugno,
// Settembre e Dicembre, tutti mesi a cavallo di due stagioni, si richieda all’utente di specificare anche il giorno.
// Se il giorno è compreso tra 1 e 20 si considera la stagione precedente altrimenti quella successiva.
#include <stdio.h>

int main() {
    unsigned int mese, giorno;

    printf("Inserisci il numero del mese: ");
    scanf("%d", &mese);

    switch (mese)
    {
    case 1: case 2:
        printf("Inverno\n");
        break;
    case 3:
        printf("Inserisci anche il giorno: ");
        scanf("%d", &giorno);

        if (giorno >= 21) {
            printf("Primavera\n");
            break;
        }
        printf("Inverno\n");
        break;
    case 4: case 5:
        printf("Primavera\n");
        break;
    case 6:
        printf("Inserisci anche il giorno: ");
        scanf("%d", &giorno);

        if (giorno >= 21) {
            printf("Estate\n");
            break;
        }
        printf("Primavera\n");
        break;
    case 7: case 8:
        printf("Estate\n");
        break;
    case 9:
        printf("Inserisci anche il giorno: ");
        scanf("%d", &giorno);

        if (giorno >= 21) {
            printf("Autunno\n");
            break;
        }
        printf("Estate\n");
        break;
    case 10: case 11:
        printf("Autunno\n");
        break;
    case 12:
        printf("Inserisci anche il giorno: ");
        scanf("%d", &giorno);
        
        if (giorno >= 21) {
            printf("Inverno\n");
            break;
        }
        printf("Autunno\n");
        break;
    default:
        break;
    }

    return 0;
}