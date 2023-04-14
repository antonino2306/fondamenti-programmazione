// Calcolare il massimo valore tra tre numeri in input
#include <stdio.h>

float max(float a, float b, float c);

int main() {
    float a, b, c, massimo;
    
    printf("Inserisci 3 numeri: ");
    scanf("%f %f %f", &a, &b, &c);

    massimo = max(a, b, c);

    printf("Il valore massimo tra %.1f %.1f %.1f è: %.1f\n", a, b, c, massimo);

}

float max(float a, float b, float c) {
    if (a >= b) {

        if (a >= c) {
            return a;
        }
        else {
            return c;
        }

    }
    else if (b >= c) {
        return b;
    }
    else {
        return c;
    }
}
