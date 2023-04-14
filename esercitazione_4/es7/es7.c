// Implementare in C un programma che chieda all’utente di inserire tre caratteri e stampi sullo standard output
// se il secondo di essi è compreso tra il primo e l’ultimo.
#include <stdio.h>

int main() {
    char c1, c2, c3;

    printf("Inserisci tre caratteri: ");
    scanf("%c %c %c", &c1, &c2, &c3);

    if (c1 <= c2 && c2 <= c3) {
        printf("Il secondo è compreso tra primo e terzo\n");
    }
    else {
        printf("Il secondo non è compreso tra primo e terzo\n");
    }

    
    return 0;
}