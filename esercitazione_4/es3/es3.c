// Implementare in C un programma che consenta all’utente di inserire un anno e di verificare se esso è bisestile.
// Suggerimento: un anno è bisestile se è divisibile per 4 ma non per 100, oppure se è divisibile per 400
#include <stdio.h>

void bisestile(int anno);
void bisestile_logici(int anno);


int main() {
    int anno;

    printf("Inserisci una anno: ");
    scanf("%d", &anno);

    // bisestile(anno);
    bisestile_logici(anno);

    return 0;
}

void bisestile(int anno)
{
    if ((anno % 4) == 0) {
        if ((anno % 100) != 0) {
            printf("L'anno è bisestile\n");
        }
        else if ((anno % 400) == 0) {
            printf("L'anno è bisestile\n");
        }
        else {
            printf("L'anno non è bisestile\n");
        }
    }
    else {
        printf("L'anno non è bisestile\n");
    }
}

void bisestile_logici(int anno)
{
    if (((anno % 4) == 0) && ((anno % 100) != 0)) {
        printf("L'anno è bisestile\n");
    }
    else if ((anno % 400) == 0) {
        printf("L'anno è bisestile\n");
    }
    else {
        printf("L'anno non è bisestile\n");
    }
}
