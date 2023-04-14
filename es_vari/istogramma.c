#include <stdio.h>
#define SIZE 10

int main() {

    unsigned int arr[SIZE] = {0};
    printf("Inserisci valori nell'array:\n");

    for (size_t i = 0; i < SIZE; i++) {
        printf("arr[%lu]: ", i);
        scanf("%u", &arr[i]);
    }

    for (size_t i = 0; i < SIZE; i++) {
        printf("Arr[%lu]: %u ", i, arr[i]);
        for (int j = 0; j < arr[i]; j++) {
            printf("* ");
        }
        puts("");
    }
}