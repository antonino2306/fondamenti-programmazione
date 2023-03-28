#include <stdio.h>

void stampa_istruzioni() {
    printf("Inserisci:\n");
    printf("1 per prelevare\n");
    printf("2 per depositare\n");
    printf("3 per visualizzare il saldo\n");
    printf("4 per uscire\n");
    printf("> ");
}

unsigned int prelievo(unsigned int borsellino) {
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
    return borsellino;

}

unsigned int deposito(unsigned int borsellino) {
    unsigned int denaro_da_depositare;

    printf("Quanto vuoi depositare: ");
    scanf("%u", &denaro_da_depositare);

    borsellino += denaro_da_depositare;
    return borsellino;
}

void visualizza_saldo(unsigned int borsellino) {
    printf("Nel tuo borsellino hai %u euro\n", borsellino);
}