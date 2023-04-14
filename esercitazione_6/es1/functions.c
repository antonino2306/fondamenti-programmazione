#include <stdio.h>

void stampa_schermata_iniziale() {
    printf("Che operazione vuoi fare:\n");
    printf("Sapere quanti grammi di sale ci sono nel barattolo: premi 1\n");
    printf("Usare il sale: premere 2\n");
    printf("Riempire il barattolo: premere 3\n");
    printf("Uscire: premere 4\n");
    printf("> ");
}

int usa_sale(unsigned int quantità_sale)
{
    unsigned int grammi_usati, flag = 1;
    
    do {
        printf("Quanti grammi vuoi usare: ");
        scanf("%u", &grammi_usati);
        
        if (grammi_usati > quantità_sale) {
            printf("Non c'è abbastanza sale. Grammi rimasti: %u\n", quantità_sale);
        }
        else {
            flag = 0;
        }

    } while (flag);

    quantità_sale -= grammi_usati;
    printf("Hai usato %u grammi di sale, ne rimangono %u\n", grammi_usati, quantità_sale);

    if (quantità_sale < 20) {
        printf("Barattolo quasi vuoto, riempilo\n");
    }

    return quantità_sale;
}

void info_barattolo(unsigned int q_sale, unsigned const int capienza_barattolo)
{
    printf("Nel barattolo ci sono %u grammi su %u totali\n", q_sale, capienza_barattolo);
}

int riempi_barattolo(unsigned int q_sale, unsigned const int capienza_barattolo)
{
    unsigned int flag = 1, grammi_inseriti;

    do {
        printf("Inserisci sale: ");
        scanf("%u", &grammi_inseriti);

        if ((grammi_inseriti + q_sale) > capienza_barattolo) {
            unsigned int grammi_eccesso = grammi_inseriti + q_sale - capienza_barattolo;
            printf("Stai inserendo %u grammi di sale in eccesso. Inserisci un valore inferiore\n", grammi_eccesso);
        }
        else {
            q_sale += grammi_inseriti;
            flag = 0;
        }
    } while (flag);

    return q_sale;
}
