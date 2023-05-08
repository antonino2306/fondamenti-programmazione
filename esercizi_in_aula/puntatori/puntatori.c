#include <stdio.h>


int main() {
    int num = 5;
    int *num_ptr = &num;
    int y = 25;

    printf("Indirizzo della variabile num: %p\n", &num);
    printf("Valore contenuto in num_ptr:   %p\n", num_ptr);

    printf("Inserisci un valore in num: ");
    scanf(" %d", num_ptr);

    printf("Nuovo valore di num = *num_ptr. %d = %d\n", num, *num_ptr);

    printf("num + y = %d = *num_ptr + y = %d\n", num + y, y + *num_ptr);
}