#include <stdio.h>

int main() {
    unsigned long long int n;

    printf("Di quale numero vuoi sapere i divisori? ");
    scanf("%llu", &n);


    if (n != 0) {
        unsigned int conta_divisori = 0;
    
        printf("I divisori di %llu sono: ", n);
        
        for (unsigned long long int i = 1; i <= n; i++) {
            
            if (n % i == 0) {
                conta_divisori++;
                printf("%llu ", i);
            }
        }
        
        if (conta_divisori == 2) {
            printf("\n%llu è primo\n", n);
        }
        else {
            printf("\n%llu non è primo\n", n);
        }
    }
    else {
        printf("Tutti i numeri dividono 0\n");
    }

    return 0;
}