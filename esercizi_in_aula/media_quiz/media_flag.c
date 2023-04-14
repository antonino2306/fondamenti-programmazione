#include <stdio.h>

int main() {
    unsigned int contatore = 0, totale = 0;
    int voto, flag = -1;
    float media;
    printf("Inserisci voto, -1 per terminare: ");
    scanf("%d", &voto);

    while (voto != flag) {
        totale += voto;
        contatore ++;
        printf("Inserisci voto, -1 per terminare: ");
        scanf("%d", &voto);
    }

    if (contatore == 0) {
        puts("Nessun voto inserito");
    }
    else {
        media = (float) totale / contatore;
        printf("Media voti: %.1f\n", media);
    }

}