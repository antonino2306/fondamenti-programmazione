// Implementare in C un programma che chieda
// l’anno di nascita all’utente e risponda se tale anno è quello in cui l’uomo è andato sulla Luna o quanti anni prima
// o quanti anni dopo.
#include <stdio.h>

int main() {
    int anno_nascita, differenza;
    const int anno_allunaggio = 1969;

    printf("Inserisci l'anno di nascita: ");
    scanf("%d", &anno_nascita);

    if (anno_nascita == anno_allunaggio) {
        printf("Sei nato quando l'uomo andava sulla luna\n");
    }
    else if (anno_nascita > anno_allunaggio) {
        differenza = anno_nascita - anno_allunaggio;
        printf("Sei nato %d anni dopo il viaggio sulla luna\n", differenza);
    }
    else {
        differenza = anno_allunaggio - anno_nascita;
        printf("Sei nato %d anni prima il viaggio sulla luna\n", differenza);
    }

    return 0;

}