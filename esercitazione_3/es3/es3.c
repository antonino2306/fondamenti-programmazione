#include <stdio.h>

int lato (int p) {
    return p/4;
}

int area (int l) {
    return l * l;
}

int main() {
    int perimetro = 24;
    int Lato = lato(perimetro);
    int Area = area(Lato);
    printf("Area totale: %d\n", Area);
    return 0;
}