// L'utente inserisce un numero n e il programma stampa a schermo
// A scala decrescente il conto da 1 a n intervallato da ?
#include <stdio.h>

int main() {
    int n;

    printf("Inserisci n: ");
    scanf("%d", &n);

    for (unsigned int i = 0; i < n; i++) {

        for(unsigned int j = 1; j <= n-i; j++) {
            printf("%d", j);

            if (j < n - i) {
                printf("?");
            }
            else {
                printf("\n");
            }
        }
    }
    return 0;
}
