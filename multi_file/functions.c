#include <stdio.h>
#include "variables_declaration.h"

void stampa_schermata_iniziale() {
    printf("Scegli cosa vuoi fare:\n");
    printf("Premi a per calcolare l'area del cerchio\n");
    printf("Premi s per calcolare la somma di n numeri\n");
    printf("Premi b per calcolare il tuo BMI\n");
    printf("Premi q per uscire\n");
    printf("> ");
}

void calcola_area_cerchio(){
    float raggio, area;
    printf("Inserisci il raggio del cerchio in cm: ");
    scanf("%f", &raggio);

    area = PI * raggio * raggio;
    printf("L'area è %.2f cm^2\n", area);
    printf("-----------------------------\n");

}

void somma_n_numeri(){
    unsigned int contatore;
    int numero, somma = 0;

    printf("Dimmi quanti numeri vuoi sommare: ");
    scanf("%u", &contatore);

    for (unsigned int i = 0; i < contatore; i++) {
        printf("Inserisci numero: ");
        scanf("%d", &numero);

        somma += numero;
    }

    printf("La somma è %d\n", somma);
    printf("-----------------------------\n");

}

void calcola_bmi(){
    float peso, altezza;
    float bmi;
    printf("Inserisci peso (Kg) e altezza (m): ");
    scanf("%f %f", &peso, &altezza);

    bmi = peso / (altezza * altezza);
    printf("Il tuo bmi è di %.2f\n", bmi);

    if (bmi < 16) {
        printf("Sei cosi secco che voli via col vento\n");
    }
    else if (bmi >= 16 && bmi <= 18) {
        printf("Sei sottopeso\n");
    }
    else if (bmi > 18 && bmi <= 25) {
        printf("Sei normopeso\n");
    }
    else if (bmi > 25) {
        printf("Vai alla fottuta palestra obeso di merda\n");
    }

    printf("-----------------------------------------\n");

}