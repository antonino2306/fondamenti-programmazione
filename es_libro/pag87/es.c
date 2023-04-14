#include <stdio.h>

int main() {
    unsigned int contatore, risultato_test, tot_passati = 0, tot_bocciati = 0;

    for (contatore = 0; contatore < 10; contatore++) {
        printf("Enter result, passed = 1, failed = 2: ");
        scanf("%d", &risultato_test);

        if (risultato_test == 1) {
            tot_passati++;
        }
        else if (risultato_test == 2) {
            tot_bocciati++;
        }
        else {
            printf("%s\n", "Invalid");
        }
    }

    printf("Summary: passed: %d \t failed: %d\n", tot_passati, tot_bocciati);
    if (tot_passati > 8) {
        printf("%s\n", "Bonus to instructor");
    }

    return 0;
}