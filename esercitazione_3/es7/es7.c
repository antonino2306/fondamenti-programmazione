#include <stdio.h>

float calcolo_bmi(float massa, float h); 

int main() {
    float peso, altezza;
    float bmi;
    printf("Inserisci peso (Kg) e altezza (m): ");
    scanf("%f %f", &peso, &altezza);
    
    bmi = calcolo_bmi(peso, altezza);

    printf("Il tuo BMI è: %.2f\n", bmi);
    
    return 0;
}

float calcolo_bmi(float massa, float h) {
    return massa / (h * h);
}