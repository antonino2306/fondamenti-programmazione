#include <stdio.h>

int main() {
    unsigned int counter = 0, flag = 1;
    const int exit_value = 9999;
    float average;
    int total = 0, number;

    do {
        printf("Enter number: ");
        scanf("%d", &number);

        if (number != exit_value) {
            total += number;
            counter++;
        }
        else {
            flag = 0;
        }
    } while (flag);

    if (counter == 0) {
        average = 0;
        printf("No numbers entered. Average = %.0f\n", average);
    }
    else {
        average = (float)total / counter;
        printf("La media dei valori inseriti è: %.1f\n", average);
    }


    return 0;
}