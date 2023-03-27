#include <stdio.h> 

int main() {
    unsigned int m;
    float somma = 0;

    printf("Dimmi quanti elementi della serie armonica devo sommare: ");
    scanf("%u", &m);

    for (unsigned int i = 1; i <= m; i++) {
        somma += 1 / (float)i;
    }

    printf("La somma è: %.4f\n", somma);
    
   return 0;
}