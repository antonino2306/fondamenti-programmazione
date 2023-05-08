#include <stdio.h>
#include <stdlib.h>

void inserisci_risultati(short int *id, float *tempi, const size_t numero_part);
void stampa_elenco_risultati(short int *id, float *tempi, const size_t numero_part);
void determina_primo_secondo(float *tempi, const size_t numero_part, size_t *indice_primo, size_t *indice_secondo);
void stampa_vincitori(short int *id, float *tempi, size_t indice_primo, size_t indice_secondo);

int main() {
    size_t numero_corridori;

    puts("Inserisci il numero dei partecipanti alla gara: ");
    scanf("%lu", &numero_corridori);

    if (numero_corridori < 2) {
        puts("Devi inserire un numero > 2");
        return 1;
    }

    short int *id_partecipanti = (short int*)calloc(numero_corridori, sizeof(short int));
    float *tempi_corridori = (float*)calloc(numero_corridori, sizeof(float));

    inserisci_risultati(id_partecipanti, tempi_corridori, numero_corridori);    

    stampa_elenco_risultati(id_partecipanti, tempi_corridori, numero_corridori);

    size_t indice_primo, indice_secondo;

    determina_primo_secondo(tempi_corridori, numero_corridori, &indice_primo, &indice_secondo);

    stampa_vincitori(id_partecipanti, tempi_corridori, indice_primo, indice_secondo);

    free(id_partecipanti);
    free(tempi_corridori);

    return 0;


}

void inserisci_risultati(short int *id, float *tempi, const size_t numero_part)
{
    for (size_t i = 0; i < numero_part; i++) {
        printf("%s", "Inserisci l'id del corridore: ");
        scanf("%hd", (id + i));

        printf("%s","Inserisci il tempo del corridore: ");
        scanf("%f", (tempi + i));
        puts("");
    }
}

void stampa_elenco_risultati(short int *id, float *tempi, const size_t numero_part)
{
    for (size_t i = 0; i < numero_part; i++) {
        printf("%hd\t%.3f\n", *(id + i), *(tempi + i));
    }
}

void determina_primo_secondo(float *tempi, const size_t numero_part, size_t *indice_primo, size_t *indice_secondo)
{

    float t_min = *tempi;
    *indice_primo = 0;

    for (size_t i = 0; i < numero_part; i++) {
        if (tempi[i] < t_min) {
            t_min = tempi[i];
            *indice_primo = i;
        }
    }

    float t_2min;
    if (indice_primo == 0) {
        t_2min = *(tempi + 1);
        *indice_secondo = 1;
    }
    else {
        t_2min = *tempi;
        *indice_secondo = 0;
    }

    for (size_t i = 0; i < numero_part; i++) {
        if (tempi[i] > t_min && tempi[i] < t_2min) {
            t_2min = tempi[i];
            *indice_secondo = i;
        }
    }

}

void stampa_vincitori(short int *id, float *tempi, size_t indice_primo, size_t indice_secondo)
{
    printf("Primo classificato:   %hd \t %.3f\n", *(id + indice_primo), *(tempi + indice_primo));
    printf("Secondo classificato: %hd \t %.3f\n", *(id + indice_secondo), *(tempi + indice_secondo));

}
