#include <stdio.h>
#define SIZE 10

void stampa_menu();
int cerca_numero(unsigned int arr[], size_t size, int num);

int main() {

    unsigned int sequenza[SIZE] = {0};
    unsigned int continua = 1, trovato;
    int input_utente;

    // Inizializza l'array
    for (size_t i = 0; i < SIZE; i++) {
        printf("Inserisci un numero > 0 ");
        scanf("%u", &sequenza[i]);
    }

    do {
        stampa_menu();
        scanf("%d", &input_utente);

        if (input_utente != -1) {
            trovato = cerca_numero(sequenza, SIZE, input_utente);
            if (trovato) {
                printf("Numero già presente\n");
            }
            else {
                printf("Non presente\n");
            }

        }
        else {
            continua = 0;
        }
    } while (continua);


}

void stampa_menu() {
    printf("Inserisci un numero per vedere se si trova nell'array: ");
    printf("Altrimenti inserisci -1 per uscire\n");
    printf("> ");
}

int cerca_numero(unsigned int arr[], size_t size, int num)
{
    unsigned int trovato = 0;
    for(size_t i = 0; i < size && !trovato; i++) {

        if (arr[i] == num) {
            trovato = 1;
        }
        
    }

    return trovato;
}
