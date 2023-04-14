#include <stdio.h>

void swap(int* a, int* b);

int main() {
    int n1, n2, n3, tmp;

    printf("Inserisci 3 numeri interi: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 > n2) {
        // tmp = n1;
        // n1 = n2; 
        // n2 = tmp;

        swap(&n1, &n2);
    }

    if (n2 > n3) {
        // tmp = n2;
        // n2 = n3;
        // n3 = tmp;
        swap(&n2, &n3);

        if (n1 > n2) {
            // tmp = n1;
            // n1 = n2;
            // n2 = tmp;
            swap(&n1, &n2);
        }
    }

    printf("Ordine crescente: %d %d %d\n", n1, n2, n3);
    return 0;
}

// Funzione aggiunta da me
void swap(int* a, int* b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

}