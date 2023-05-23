//* Programma che legge gli elementi di un array da un file
#include <stdio.h>
#define SIZE 100

int init_da_file(FILE *fp, int v[]);
void stampa_array(int arr[], int n);

int main(int argc, char* argv[]) {

    FILE *fp;
    int n, v[SIZE];

    if (argc < 2) {
        printf("Devi passare il nome del file da aprire\n");
        return -1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    n = init_da_file(fp, v);
    stampa_array(v, n);

    fclose(fp);

    return 0;
}

int init_da_file(FILE *fp, int v[])
{
    
    // Leggiamo il numero di elementi da acquisire
    int n;

    fscanf(fp, "%d", &n);

    // Controllo sulla dimensione
    if (n > SIZE) {
        printf("Il file contiene troppi elementi\n");
        n = SIZE;
    }

    for (size_t i = 0; i < n; i++) {

        fscanf(fp, "%d", &v[i]);

    }

    return n;
}

void stampa_array(int arr[], int n)
{
    for (size_t i = 0; i < n; i++) {
        printf("[%zu]: %d\n", i, arr[i]);        
    }
}
