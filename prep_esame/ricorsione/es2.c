//? Determinare il minimo di un array in modo ricorsivo
#include <stdio.h>
#include <stdlib.h>

int *riempi_array(size_t dim);
int min(int *array, int *ultimo_elemento, int minimo);

int main() {

    int *array = NULL;
    size_t dim;
    puts("Inserisci la dimensione dell'array");
    scanf("%lu", &dim);

    array = riempi_array(dim);

    printf("Il minimo nell'array è: %d", min(array, &array[dim-1], array[0]));

    free(array);
    return 0;
}

int *riempi_array(size_t dim)
{
    
    int *array = (int*)calloc(dim, sizeof(int));

    for (size_t i = 0; i < dim; i++) {

        printf("[%lu]: ", i);
        scanf("%d", (array + i));

    }

    return array;
    
}

int min(int *array, int *ultimo_elemento, int minimo)
{

    if (*array < minimo) {
        minimo = *array;
    }

    if (array == ultimo_elemento) {
        return minimo;
    }
    else {

        return min(array + 1, ultimo_elemento, minimo);
    }

}
