#include <stdio.h>
#define SIZE 100
#define TOL_MAX 0.00000001

int main() {
    double num[SIZE] = {0};
    double totale = 0;
    size_t num_inseriti = 0;

    do {
        printf("Inserisci un numero: ");
        scanf("%lf", &num[num_inseriti]);

        if (num[num_inseriti] != 0) {
            totale += num[num_inseriti];
            num_inseriti++;
        }
    } while (num_inseriti < SIZE && totale < 50);

    if (num_inseriti > 3) {
         
        for (size_t i = 0; i < num_inseriti - 1; i++) {

            for (size_t j = i+1; j < num_inseriti; j++) {

                double rapp = num[i] / num[j];
                double inv_rapp = num[j] / num[i];

                if ((rapp - num[0] < TOL_MAX && rapp - num[0] > -1*TOL_MAX) || (inv_rapp - num[0] < TOL_MAX && inv_rapp - num[0] > -1*TOL_MAX)) {
                    printf("Coppia: %lf %lf\n", num[i], num[j]);
                }
            } 
        }
    }
 
    return 0;
}