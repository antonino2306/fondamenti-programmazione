#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 11

void init_array(unsigned int arr[], size_t size);
unsigned int controlla_quotazioni(const unsigned int arr[], size_t size);

int main() {

    unsigned int quotazioni[SIZE] = {1, 2, 2, 1, 4, 6, 1, 6, 6, 1, 2};

    unsigned int titolo_costante = controlla_quotazioni(quotazioni, SIZE);
    printf("Numero di volte in cui le quotazioni rimangono costanti nei giorni: %u\n", titolo_costante);
}


unsigned int controlla_quotazioni(const unsigned int arr[], size_t size) {
    unsigned int giorni_costanti = 0;
    size_t i = 0;

    while (i < size-1) {
        int serie = 0;
        for (size_t j = i+1; j < size && serie != -1; j++) {
            if (arr[i] == arr[j]) {
                serie++;
            }
            else {
                if (serie != 0) {
                    giorni_costanti++;
                    i += serie;
                }
                else {
                    i++;
                }
                serie = -1;
            }
        }
    }
    return giorni_costanti;
}
