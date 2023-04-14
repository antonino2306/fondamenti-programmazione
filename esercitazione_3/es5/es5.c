#include <stdio.h>
void disegna();

int main() {
    disegna();
    return 0;
}

void disegna()
{
    for(int i = 1; i <= 8; i++) {

        if(i % 2 == 0) {
            printf(" ");
        }

        for(int j = 0; j < 8; j++) {
            printf("$ ");
        }

        printf("\n");

    }
}
