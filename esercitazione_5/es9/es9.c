#include <stdio.h>

int main() {
    unsigned int numero_corridori, identificativo;
    float tempo;
    float tempo_primo, tempo_secondo;
    unsigned int id_primo, id_secondo;

    do {  
        printf("Inserisci numero di corridori: ");
        scanf("%u", &numero_corridori);
    } while(numero_corridori == 0);

    
    
    if (numero_corridori == 1) {
        printf("Hai partecipato da solo quindi hai vinto\n");
        return 0;
    }

    for (unsigned int i = 0; i < numero_corridori; i++) {
        printf("Inserisci id e tempo in secondi: ");
        scanf("%d %f", &identificativo, &tempo);

        if (i == 0) {
            tempo_primo = tempo;
            id_primo = identificativo;
        }

        if (tempo < tempo_primo) {
            tempo_secondo = tempo_primo;
            tempo_primo = tempo;
            id_secondo = id_primo;
            id_primo = identificativo;
        }
        else {
            if (i == 1) {
                tempo_secondo = tempo;
                id_secondo = identificativo;
            }

            if (tempo < tempo_secondo) {
                tempo_secondo = tempo;
                id_secondo = identificativo;
            }
        }     
    }

    printf("Primo arrivato:   %u %.4f \n", id_primo, tempo_primo);
    printf("Secondo arrivato: %u %.4f\n", id_secondo, tempo_secondo);
    return 0;
}