#include <stdio.h>
#define SIZE 4

void init_array(int arr[], size_t size);
int cerca_intervallo(const int arr[], size_t size);
int determina_min(const int arr[], size_t size);

int main() {

    int numeri[SIZE] = {0};
    int trovato;
    init_array(numeri, SIZE);
    
    trovato = cerca_intervallo(numeri, SIZE);

    printf("%d\n", trovato);

    return 0;

}

void init_array(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("[%lu]: ", i);
        scanf("%d", &arr[i]);
    }
}

int cerca_intervallo(const int arr[], size_t size)
{
    int min = determina_min(arr, size);
    int sequenza = 1; 

    for (int i = min; i < min + size; i++) {
        int trovato = 0;
 
        for (size_t k = 0; k < size && !trovato; k++) {
            if (arr[k] == i) {
                trovato = 1;
            }

        }
        if (trovato == 0) {
            sequenza = 0;
        }
    }
    return sequenza;
}

int determina_min(const int arr[], size_t size)
{
    int minimo = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }
    return minimo;
}