#include <stdio.h>

void prelievo();
void deposito();
void stampa_istruzioni();
void visualizza_saldo();

unsigned int borsellino = 0;

int main() {
    unsigned int flag = 1;

    printf("Quanti soldi vuoi inserire nel borsellino: ");
    scanf("%u", &borsellino);

    do {
        unsigned int scelta_utente;
        
        stampa_istruzioni();
        scanf("%u", &scelta_utente);

        switch (scelta_utente) {
            
            case 1:
                prelievo();
                break;
            
            case 2:
                deposito();
                break;

            case 3:
                visualizza_saldo();
                break;
            
            case 4: 
                flag = 0;
                break;
            
            default: 
                break;

        }
    } while (flag);

    return 0;
}

void stampa_istruzioni() {
    printf("Inserisci:\n");
    printf("1 per prelevare\n");
    printf("2 per depositare\n");
    printf("3 per visualizzare il saldo\n");
    printf("4 per uscire\n");
    printf("> ");
}

void prelievo() {
    unsigned int denaro_da_prelevare;
    unsigned int flag = 1;
    
    do {
        printf("Inserisci quantità di denaro da prelevare: ");
        scanf("%u", &denaro_da_prelevare);

        if (denaro_da_prelevare > borsellino) {
            printf("Saldo insufficiente, prelieva di meno. Saldo attuale: %u\n", borsellino);
        }
        else {
            flag = 0;
        }
    } while (flag);

    borsellino -= denaro_da_prelevare;
}

void deposito() {
    unsigned int denaro_da_depositare;

    printf("Quanto vuoi depositare: ");
    scanf("%u", &denaro_da_depositare);

    borsellino += denaro_da_depositare;
    
}

void visualizza_saldo() {
    printf("Nel tuo borsellino hai %u euro\n", borsellino);
}