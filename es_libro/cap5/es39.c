#include <stdio.h>

int mcd(int x, int y);

int main() {
    int num1, num2;

    printf("Inserisci i due numeri: ");
    scanf("%d %d", &num1, &num2);

    printf("mcd(%d, %d) = %d\n", num1, num2, mcd(num1, num2));

    return 0;
}

int mcd(int x, int y)
{
    if (y == 0) {
        return x;
    }
    else {
        return mcd(y, x % y);
    }
}
