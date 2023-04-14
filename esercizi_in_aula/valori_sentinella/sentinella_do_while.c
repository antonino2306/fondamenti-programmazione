#include <stdio.h>

int main() {
    int flag = 1;
    char carattere, vuoto;

    do {
        printf("Inserisci carattere: ");
        scanf("%c", &carattere);
        if (carattere >= '0' && carattere <= '9'){
            flag = 0;
        }
        else {
            printf("Carattere: %c\n", carattere);
            scanf("%c", &vuoto);
            // La scanf alla riga precedente permette di rimuovere il carattere di ritorno a capo
            // che era rimasto nello stdin dopo il primo inserimento di caratteri
        }

    }while(flag);
    
    return 0;
}