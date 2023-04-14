#include <stdio.h>

int main() {
    int flag = 1;
    char carattere, vuoto;
    printf("Inserisci carattere: ");
    scanf("%c", &carattere);
    scanf("%c", &vuoto);
    // Riga 8 e Riga 14 servono per fare in modo che il prossimo carattere
    // ad essere preso non sia il ritorno a capo che è rimasto nello stdin
    // ma il prossimo carattere inserito da tastiera.
    while (flag) {
        printf("Carattere inserito: %c\n", carattere);
        printf("Inserisci carattere: ");
        scanf("%c", &carattere);
        scanf("%c", &vuoto);
        if (carattere >= '0' && carattere <= '9') {
            flag = 0;
        }
    }

    return 0;
}