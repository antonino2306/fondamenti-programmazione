#include <stdio.h>
#define SIZE 100

int stabilisci_dimensione();
void inizializza_array(int arr[], size_t size);
void determina_max(int const v1[], const int v2[], int max[], size_t size);
void determina_min(int const v1[], const int v2[], int min[], size_t size);
void determina_medio(int const v1[], int const v2[], int medio[], size_t size);
void stampa_array(int const arr[], size_t size);


int main() {
    int arr1[SIZE] = {0}, arr2[SIZE] = {0}, max[SIZE] = {0}, min[SIZE] = {0}, medio[SIZE] = {0};
    unsigned int dim;
    
    dim = stabilisci_dimensione();

    printf("Primo array:\n");
    inizializza_array(arr1, dim);
    printf("Secondo array:\n");
    inizializza_array(arr2, dim);

    determina_max(arr1, arr2, max, dim);
    determina_min(arr1, arr2, min, dim);
    determina_medio(arr1, arr2, medio, dim);

    printf("Max: ");
    stampa_array(max, dim);
    printf("Min: ");
    stampa_array(min, dim);
    printf("Medio: ");
    stampa_array(medio, dim);
    

    return 0;
}

void inizializza_array(int arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        printf("\tPosizione [%lu]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n\n");
}

int stabilisci_dimensione()
{
    unsigned int dim;
    printf("Inserisci la dimensione dell'array (MAX 100)");
    printf("\n> ");
    scanf("%d", &dim);

    if (dim > 100) {
        printf("Hai inserito un valore troppo grande lo abbasso a 100");
        dim = 100;
    }
    return dim;
}

void determina_max(const int v1[], const int v2[], int max[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (v1[i] >= v2[i]) {
            max[i] = v1[i];
        }
        else {
            max[i] = v2[i];
        }
    }
}

void determina_min(int const v1[], int const v2[], int min[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (v1[i] <= v2[i]) {
            min[i] = v1[i];
        }
        else {
            min[i] = v2[i];
        }
    }
}

void determina_medio(int const v1[], const int v2[], int medio[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        medio[i] = (v1[i] + v2[i]) / 2;
    }
}

void stampa_array(const int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
