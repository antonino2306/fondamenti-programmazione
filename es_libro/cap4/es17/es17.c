#include <stdio.h>

int main() {
    unsigned int contatore = 0, num_clienti = 3, lim_credito_iniz, lim_credito_fin, saldo_credito;
    long unsigned int num_conto;

    while (contatore < 3) {
        printf("%s","Inserisci numero di conto (10 cifre): ");
        scanf("%ld", &num_conto);
        
        printf("%s", "Inserisci il tuo attuale limite di credito: ");
        scanf("%u", &lim_credito_iniz);

        printf("%s", "Inserisci saldo attuale di credito: ");
        scanf("%u", &saldo_credito);

        lim_credito_fin = lim_credito_iniz / 2;

        printf("Il tuo nuovo limite di credito è: %d\n", lim_credito_fin);

        if (saldo_credito > lim_credito_fin) {
            printf("%s\n", "Il tuo saldo di credito supera il limite");
        }
        
        contatore++;
    }
    return 0;
}