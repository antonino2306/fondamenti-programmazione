#include <stdio.h>

int main() {
    
    unsigned int i = 0;

    while (i < 10) {

        if (i == 5) {
            i++;
            continue;
        }
        printf("#%u\n", i);
        i++;
    }

    return 0;
}