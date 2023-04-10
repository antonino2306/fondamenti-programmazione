#include <stdio.h>
#define SIZE 100

unsigned int inserisci_dimensione();
void inserisci_valori(int arr[], size_t size);
void somma_elementi(const int arr1[], const int arr2[], int arr3[], size_t size);
void stampa_array(const int arr[], size_t size);

int main() {
    int array1[SIZE] = {0}, array2[SIZE] = {0}, somma[SIZE] = {0};

    unsigned int dim = inserisci_dimensione();
    
    puts("Array 1");
    inserisci_valori(array1, dim);
    puts("Array 2");
    inserisci_valori(array2, dim);

    somma_elementi(array1, array2, somma, dim);
    stampa_array(somma, dim);

}

unsigned int inserisci_dimensione() {
    unsigned int d;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%u", &d);

    return d;
}

void inserisci_valori(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("array[%lu]: ", i);
        scanf("%d", &arr[i]);

    }
}

void somma_elementi(const int arr1[], const int arr2[], int arr3[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
}

void stampa_array(const int arr[], size_t size){
    for(size_t i = 0; i < size; i++) {
        printf("Somma[%lu]: %d\n", i, arr[i]);
    }
}
