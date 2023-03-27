#include <stdio.h>

int main() {
    unsigned int counter = 0;
    int number, min, number_of_values;

    printf("Enter number of values: ");
    scanf("%d", &number_of_values);

    if (number_of_values == 0) {
        printf("Need a value different from 0\n");
        return 0;
    }

    printf("Enter number: ");
    scanf("%d", &number);
    
    min = number;

    while (counter < number_of_values - 1) {

        if (number < min) {
            min = number;
        }

        counter++;
        printf("Enter number: ");
        scanf("%d", &number);

    }

    printf("Minimum: %d\n", min);
    return 0;
}