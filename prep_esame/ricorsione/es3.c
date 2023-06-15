//Siano dati due vettori V1 e V2, di dimensione N1 e N2, rispettivamente (con 1 <= N2 <= N1). La funzione restituisce il valore 1 in
//uscita se tutti gli elementi del vettore V2 si trovano nel vettore V1 nell’ordine inverso rispetto a quello in cui essi figurano in V2, ma non
// necessariamente in posizioni immediatamente consecutive
#include <stdio.h>
#include <stdlib.h>

int *riempi_array(size_t dim);
int controlla_ordine(int *v1, int *v2, int *ultimo_v1, int *ultimo_v2);
int main() {

    int *v1 = NULL, *v2 = NULL;
    size_t dim1, dim2;

    puts("Inserisci le dimensioni di v1 e v2 con v1 >= v2");
    scanf("%lu %lu", &dim1, &dim2);

    v1 = riempi_array(dim1);
    v2 = riempi_array(dim2);

    if (controlla_ordine(v1, v2, &v1[dim1-1], &v2[dim2-1])) {
        puts("Ordinato");
    }
    else {
        puts("Non ordinato");
    }

    free(v1);
    free(v2);
    return 0;
}


int *riempi_array(size_t dim)
{
    
    int *array = (int*)calloc(dim, sizeof(int));

    if (array != NULL) {
        for (size_t i = 0; i < dim; i++) {

            printf("[%lu]: ", i);
            scanf("%d", (array + i));

        }
    }

    return array;
    
}

int controlla_ordine(int *v1, int *v2, int *ultimo_v1, int *ultimo_v2)
{

    if (v2 == ultimo_v2 && *v2 == *ultimo_v1) {
        return 1;
    }

    if (v1 == ultimo_v1 && (v2 != ultimo_v2 || *v2 != *ultimo_v1)) {
        return 0;
    }

    if (*v2 == *ultimo_v1) {
        controlla_ordine(v1, v2+1, ultimo_v1-1, ultimo_v2);
    }
    else {
        controlla_ordine(v1, v2, ultimo_v1-1, ultimo_v2);
    }


}
