#include <stdio.h>
#define SIZE 100

void riempi_arr(int arr[], size_t size);
void inverti_arr(int arr[], size_t size);
void stampa_arr(const int arr[], size_t size);

int main() {

    unsigned short int dim;
    int arr[SIZE] = {0};

    printf("Inserisci dimensione (max 100): ");
    scanf("%hu", &dim);

    riempi_arr(arr, dim);
    inverti_arr(arr, dim);
    stampa_arr(arr, dim);

    return 0;
}

void riempi_arr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Array[%lu]: ", i);
        scanf("%d", &arr[i]);
    }
    puts("");
}

void inverti_arr(int arr[], size_t size)
{
    for (size_t i = 0; i < (size / 2); i++) {
        int tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i ] = tmp;
    }
}


void stampa_arr(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Arr[%lu]: %d\n", i, arr[i]);
    }
}
