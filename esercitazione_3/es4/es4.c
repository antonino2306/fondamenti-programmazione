#include <stdio.h>

int predecessore(int n);
int successore(int n);

int main() {
    int numero = 23;
    int pred = predecessore(numero);
    int succ = successore(numero);
    printf("Predecessore: %d;\nSuccessore: %d;\n", pred, succ);
    return 0;
}

int predecessore (int n) {
    return n - 1;
}

int successore (int n) {
    return n + 1;
}