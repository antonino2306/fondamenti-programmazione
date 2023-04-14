#include <stdio.h>
#define SIZE 400

int main() {
    int array_1[SIZE] = {0};
    int array_2[SIZE] = {0};
    int uguali = 1;
    
    for (size_t i = 0; i < SIZE && uguali; i++) {
        if (array_1[i] != array_2[i]) {
            uguali = 0;
        } 
    }

    if (uguali) {
        printf("Sono uguali\n");
    }
    else {
        printf("Sono diversi\n");
    }

    return 0;
}