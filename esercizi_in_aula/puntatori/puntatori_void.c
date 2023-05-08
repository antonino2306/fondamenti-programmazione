#include <stdio.h>

int main() {

    int x = 5;
    void *x_ptr = &x;

    // L'unico modo per derefernziare un puntatore void è fare il casting 
    int *x_ptr_int = x_ptr;
    *x_ptr_int = 8;


    printf("x = %d\n", *((int*)x_ptr));
}