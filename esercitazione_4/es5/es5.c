// Implementare in C un programma che chieda all’utente di inserire tre lunghezze dei lati di un triangolo e stampi
// sullo standard output se il triangolo è scaleno, isoscele o equilatero.
#include <stdio.h>

int triangolo_non_esiste(float l1, float l2, float l3);
void classifica_triangolo(float l1, float l2, float l3);

int main() {
    float l1, l2, l3;

    printf("Inserisci le misure dei lati del triangolo: ");
    scanf("%f %f %f", &l1, &l2, &l3);

    if (triangolo_non_esiste(l1, l2, l3)) {
        printf("Il triangolo non esiste\n");
        return 1;
    }

    classifica_triangolo(l1, l2, l3);

    return 0;
}

int triangolo_non_esiste(float l1, float l2, float l3)
{
    if ((l1 < l2 + l3) && (l2 < l1 + l3) && (l3 < l2 + l1)) {
        return 0; 
    }
    else 
        return 1;
}

void classifica_triangolo(float l1, float l2, float l3)
{
    if (l1 == l2 || l1 == l3 || l2 == l3) {
        if (l1 == l2 && l2 == l3) {
            printf("Il triangolo è equilatero\n");
        }
        else {
            printf("Il triangolo è isoscele\n");
        }
    }
    else {
        printf("Il triangolo è scaleno\n");
    }
}
