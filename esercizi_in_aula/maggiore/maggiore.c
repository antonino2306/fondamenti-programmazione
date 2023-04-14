#include <stdio.h>

void stampa_max(float a, float b);

int main() {
    float x, y;
    
    printf("Inserisci due numeri: ");
    scanf("%f %f", &x, &y);
    stampa_max(x, y);
    

    return 0;

}

void stampa_max(float x, float y)
{
    if (x == y) {
        printf("Sono uguali\n");
    }

    else if (x > y) {
        printf("Il maggiore è: %.2f\n", x);
    }

    else {
        printf("Il maggiore è: %.2f\n", y);
    }
}
