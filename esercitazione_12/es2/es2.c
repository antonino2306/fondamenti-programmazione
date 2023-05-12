#include <stdio.h>
#include <stdlib.h>

void riempi_array(float *arr, size_t dim);
float massimo(float *arr, float *indirizzo_ultimo_elemento, float *max);

int main() {
    size_t dim;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%lu", &dim);

    float *arr = (float*)calloc(dim, sizeof(float));

    riempi_array(arr, dim);
    float max = arr[0];

    max = massimo(arr, &arr[dim-1], &max);

    printf("Il massimo dell'array è: %.2f\n", max);
    free(arr);
}

void riempi_array(float *arr, size_t dim)
{
    for (size_t i = 0; i < dim; i++) {
        printf("[%lu]: ", i);
        scanf(" %f", (arr + i));
    }

}

float massimo(float *arr, float *indirizzo_ultimo_elemento, float *max)
{

    if (*arr > *max) {
        *max = *arr;
    }

    if (arr == indirizzo_ultimo_elemento) {
        return *max;
    }
    else {
        return massimo(arr + 1, indirizzo_ultimo_elemento, max);
    }

}
