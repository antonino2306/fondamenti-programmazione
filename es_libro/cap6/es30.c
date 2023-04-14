#include <stdio.h> 
#define SIZE 1000

void init_array(unsigned int arr[], size_t size);
void cerca_primi(unsigned int arr[], size_t size);
void stampa_primi(const unsigned int arr[], size_t size);

int main() {

    unsigned int numeri[SIZE];

    init_array(numeri, SIZE);
    cerca_primi(numeri, SIZE);
    stampa_primi(numeri, SIZE);

    return 0;
}

void init_array(unsigned int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        arr[i] = 1;
    }
}

void cerca_primi(unsigned int arr[], size_t size)
{
    for (size_t i = 2; i < size; i++) {
        
        if (arr[i] == 1) {

            for (size_t j = i+1; j < size; j++) {

                if (j % i == 0) {
                    arr[j] = 0;
                }
            }
        }
    }
}

void stampa_primi(const unsigned int arr[], size_t size)
{
    printf("\n\n");
    for (size_t i = 2; i < size; i++) {

        if (arr[i] == 1) {
            printf("%lu ", i);
        }
    }
    printf("\n\n");
}
