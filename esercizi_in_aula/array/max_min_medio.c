#include <stdio.h>
#define SIZE 6

void inizializza_array(int arr[], size_t size);
void determina_max(int v1[], int v2[], int max[], size_t size);
void determina_min(int v1[], int v2[], int min[], size_t size);
void determina_medio(int v1[], int v2[], int medio[], size_t size);
void stampa_array(int arr[], size_t size);


int main() {
    int arr1[SIZE] = {0}, arr2[SIZE] = {0}, max[SIZE] = {0}, min[SIZE] = {0}, medio[SIZE] = {0};
    
    printf("Primo array:\n");
    inizializza_array(arr1, SIZE);
    printf("Secondo array:\n");
    inizializza_array(arr2, SIZE);

    determina_max(arr1, arr2, max, SIZE);
    determina_min(arr1, arr2, min, SIZE);
    determina_medio(arr1, arr2, medio, SIZE);

    printf("Max: ");
    stampa_array(max, SIZE);
    printf("Min: ");
    stampa_array(min, SIZE);
    printf("Medio: ");
    stampa_array(medio, SIZE);
    

    return 0;
}

void inizializza_array(int arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        printf("\tPosizione [%lu]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n\n");
}

void determina_max(int v1[], int v2[], int max[], size_t size)
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

void determina_min(int v1[], int v2[], int min[], size_t size)
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

void determina_medio(int v1[], int v2[], int medio[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        medio[i] = (v1[i] + v2[i]) / 2;
    }
}

void stampa_array(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
