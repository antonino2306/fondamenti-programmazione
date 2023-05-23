#include <stdio.h>
#include <stdlib.h>

void riempi_arr(int const *arr, size_t dim);
void stampa_arr(const int *arr, int *last_el_adr);

int main() {

    size_t dim; 

    printf("Inserisci la dimensione dell'array: ");
    scanf("%lu", &dim);

    int *arr = (int*)calloc(dim, sizeof(int));

    riempi_arr(arr, dim);
    stampa_arr(arr, (arr + dim - 1));

    free(arr);
    return 0;

}

void riempi_arr(const int *arr, size_t dim)
{
    for (size_t i = 0; i < dim; i++) {
        printf("[%lu]: ", i);
        scanf("%d", arr + i);
    }
}

void stampa_arr(const int *arr, int *last_el_adr)
{
    if (arr != last_el_adr) {
        printf("%d ", *arr);
        return stampa_arr(arr + 1, last_el_adr);
    }
    else {
        printf("%d\n", *last_el_adr);
        return;
    }
}
