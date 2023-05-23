#include <stdio.h>
#define SIZE 100

void copia_da_file(FILE *fp, int arr[], size_t dim);
void stampa_array(const int arr[], size_t dim);

// todo provare a farlo con le allocazioni dinamiche

int main(int argc, char *argv[]) {

    int array[SIZE];
    FILE *fp;

    if (argc < 2) {
        puts("Inserisci il percorso del file");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        puts("Errore nell'apertura del file");
        return -1;
    }

    unsigned int dim;
    fscanf(fp, "%u", &dim);

    if (dim > SIZE) {
        dim = SIZE;
    }

    copia_da_file(fp, array, dim);

    stampa_array(array, dim);

    fclose(fp);

    return 0;

}

void copia_da_file(FILE *fp, int arr[], size_t dim)
{

    for (size_t i = 0; i < dim; i++) {

        fscanf(fp, "%d", (arr + i));

    }

}

void stampa_array(const int arr[], size_t dim) {

    for (size_t i = 0; i < dim; i++) {

        printf("%d ", arr[i]);

    }
    puts("");
}