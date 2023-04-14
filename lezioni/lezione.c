#include <stdio.h>

int main() {
    float vendite_annue;
    char anno_bisestile;
    float vendite_quotidiane;

    
    printf("Vendite annuali: ");
    scanf("%f", &vendite_annue);

    printf("L'anno è bisestile inserisci y per si, n per no: ");
    scanf("%s", &anno_bisestile);

    if(anno_bisestile == 'y' || anno_bisestile == 'Y') {
        vendite_quotidiane = vendite_annue / 366;
    }
    else {
        vendite_quotidiane = vendite_annue / 365;
    }

    printf("Vendite quotidiane: %.2f\n", vendite_quotidiane);

    return 0;
}