#include <stdio.h>

unsigned int quantità_sale = 0;
unsigned const int capienza_barattolo = 1500;

void stampa_schermata_iniziale();
void usa_sale();
void info_barattolo();
void riempi_barattolo();


int main() {
    unsigned int flag = 1;
    unsigned int scelta_utente;
    do {
        stampa_schermata_iniziale();
        scanf("%u", &scelta_utente);

        switch (scelta_utente) {
            
            case 1: 
                info_barattolo(quantità_sale, capienza_barattolo);
                break;
            
            case 2:
                usa_sale(quantità_sale);
                break;
            
            case 3:
                riempi_barattolo(quantità_sale, capienza_barattolo);
                break;
            
            case 4:
                flag = 0;
                break;

            default:
                break;

        }
    } while (flag);
}

void stampa_schermata_iniziale() {
    printf("Che operazione vuoi fare:\n");
    printf("Sapere quanti grammi di sale ci sono nel barattolo: premi 1\n");
    printf("Usare il sale: premere 2\n");
    printf("Riempire il barattolo: premere 3\n");
    printf("Uscire: premere 4\n");
    printf("> ");
}

void usa_sale()
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

}

void info_barattolo()
{
    printf("Nel barattolo ci sono %u grammi su %u totali\n", quantità_sale, capienza_barattolo);
}

void riempi_barattolo()
{
    unsigned int flag = 1, grammi_inseriti;

    do {
        printf("Inserisci sale: ");
        scanf("%u", &grammi_inseriti);

        if ((grammi_inseriti + quantità_sale) > capienza_barattolo) {
            unsigned int grammi_eccesso = grammi_inseriti + quantità_sale - capienza_barattolo;
            printf("Stai inserendo %u grammi di sale in eccesso. Inserisci un valore inferiore\n", grammi_eccesso);
        }
        else {
            quantità_sale += grammi_inseriti;
            flag = 0;
        }
    } while (flag);

}