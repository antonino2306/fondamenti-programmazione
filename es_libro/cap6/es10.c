#include <stdio.h>
#define SIZE 9

void classifica_agente(unsigned int arr[], size_t size, unsigned int entrata);
void stampa_risultati(unsigned int arr[], size_t size);

int main() {
    unsigned int classifica_guadagni[SIZE] = {0};
    unsigned int numero_agenti, vendite_lorde;
    unsigned int guadagno;
    printf("Quanti agenti hanno lavorato? ");

    do {
        scanf("%u", &numero_agenti);
        if (numero_agenti <= 0) {
            printf("Devi inserire un numero >= 1: ");
        }
    } while (numero_agenti <= 0);

    for (unsigned int i = 0; i < numero_agenti; i++) {
        printf("Inserisci vendite lorde dell'agente: ");
        scanf("%u", &vendite_lorde);

        guadagno = 200 + vendite_lorde * 0.09;
        classifica_agente(classifica_guadagni, SIZE, guadagno);

    }

    stampa_risultati(classifica_guadagni, SIZE);


}

void classifica_agente(unsigned int arr[], size_t size, unsigned int entrata)
{
    unsigned int indice = (entrata / 100) - 2;

    if (indice <= 8) {
        arr[indice]++;
    }
    else {
        arr[8]++;
    }
}

void stampa_risultati(unsigned int arr[], size_t size)
{
    printf("\nRisultati settimanali:\n\n");
    for (size_t i = 0; i < size; i++) {

        if (i == 8) {
            printf("\tRange 1000 e oltre: %u impiegati\n", arr[i]);
        }
        else {
            printf("\tRange %lu00 - %lu99: %u impiegati\n", i + 2, i + 2, arr[i]);
        }

   }
   return 0;
}
