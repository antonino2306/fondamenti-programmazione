#include <stdio.h>

#define RIGHE 5
#define COLONNE 6

void vendite_agente(unsigned int arr[][COLONNE], size_t num_righe, size_t num_colonne);
void vendite_prodotto(unsigned int arr[][COLONNE], size_t num_righe, size_t num_colonne);
void stampa_tabella(unsigned int arr[][COLONNE], size_t num_righe, size_t num_colonne);

int main() {
    unsigned int sales[RIGHE][COLONNE] = {0};
    unsigned int num_distinte;
    unsigned int codice_impiegato, codice_prodotto, prezzo_vendita;

    printf("Inserisci il numero delle distinte dello scorso mese: ");
    scanf("%u", &num_distinte);

    // Popolo l'array
    for (unsigned int i = 0; i < num_distinte; i++) {
        printf("Inserisci distinta: [codice impiegato] [codice prodotto] [prezzo vendita]: ");
        scanf("%u %u %u", &codice_impiegato, &codice_prodotto, &prezzo_vendita);

        if (codice_impiegato > 4 || codice_prodotto > 5) {
            printf("I dati inseriti non sono validi");
        }
        else {
            sales[codice_impiegato][codice_prodotto] += prezzo_vendita;
        }
    }

    vendite_agente(sales, RIGHE, COLONNE);
    vendite_prodotto(sales, RIGHE, COLONNE);
    stampa_tabella(sales, RIGHE, COLONNE);

    return 0;

}

void vendite_agente(unsigned int arr[][COLONNE], size_t num_righe, size_t num_colonne) {
    
    for (size_t i = 0; i < num_righe-1; i++) {
        for (size_t j = 0; j < num_colonne - 1; j++) {
            arr[i][num_colonne-1] += arr[i][j];
        }
    }

}

void vendite_prodotto(unsigned int arr[][COLONNE], size_t num_righe, size_t num_colonne)
{ 
    for (size_t i = 0; i < num_colonne - 1; i++) {
        for (size_t j = 0; j < num_righe - 1; j++) {
            arr[num_righe-1][i] += arr[j][i];
        }
    }
}

void stampa_tabella(unsigned int arr[][COLONNE], size_t num_righe, size_t num_colonne)
{
    printf("%s %5s %5s %5s %5s %5s\n", "Prodotto", "Agente 0", "Agente 1", "Agente 2", "Agente 3", "Totale Prodotto");
    for(size_t i = 0; i < num_colonne; i++) {
        if (i == 5) {
            printf("T");
        }
        else {
            printf("%lu", i);
        }
        for (size_t j = 0; j < num_righe; j++) {
            printf("%10u", arr[j][i]);
        }
        printf("\n");
    }
}
