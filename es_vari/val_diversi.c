#include <stdio.h>
#define SIZE 100

void riempi_arr(int arr[], size_t size);
int controlla_arr(const int arr[], size_t size);

int main() {

    unsigned short int dim;
    int arr[SIZE] = {0};

    printf("Inserisci dimensione (max 100): ");
    scanf("%hu", &dim);

    riempi_arr(arr, dim);

    int diversi = controlla_arr(arr, dim);

    printf("%d\n", diversi);

    return 0;
}

void riempi_arr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Array[%lu]: ", i);
        scanf("%d", &arr[i]);
    }
    puts("");
}

void stampa_arr(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Arr[%lu]: %d\n", i, arr[i]);
    }
}

int controlla_arr(const int arr[], size_t size)
{
    int diversi = 1;

    for (size_t i = 0; i < size-1  && diversi; i++) {

        for (size_t j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                diversi = 0;
            }
        }
    }
    return diversi;
}