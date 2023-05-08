#include <stdio.h>

int main() {

    int arr[4] = {10, 20, 20, 40};
    int* const ptr = arr;

    //? Notazione array-offset
    for (int i = 0; i < 4; i++) {
        printf("Arr[%d]: %d\n", i, *(arr + i));
    }

    //? Notazione puntatore-indice
    for (int i = 0; i < 4; i++) {
        printf("Arr[%d]: %d\n", i, ptr[i]);
    }

    //? Notazione puntatore-offset
    for (int i = 0; i < 4; i++) {
        printf("Arr[%d]: %d\n", i, *(ptr + i));
    }

    //? Questa notazione va a modificare il valore di ptr
    //? Quindi non può essere usata se ptr è ad indirizzo costante
    // for (int i = 0; i < 4; i++) {
    //     printf("Arr[%d]: %d\n", i, *(ptr++));
    // }
}