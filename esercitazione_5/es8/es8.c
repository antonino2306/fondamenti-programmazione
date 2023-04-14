#include <stdio.h>

int main() {
    unsigned int n, numero = 0;

    printf("Dimmi quante righe deve avere il triangolo di Floyd: ");
    scanf("%u", &n);

    for(int contatore_righe = 0; contatore_righe < n; contatore_righe++) {

        for (int contatore_colonne = 0; contatore_colonne <= contatore_righe; contatore_colonne++) {
            numero++;
            if (numero < 10) {
                printf("%u  ", numero); 
            }
            else {
                printf("%u ", numero);
            }
        }
        printf("\n");
    }

    return 0;
}