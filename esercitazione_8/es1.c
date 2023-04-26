#include <stdio.h>
#define SIZE 100

unsigned int input_dimensione();
void riempi_matrice(int arr[][SIZE], size_t righe, size_t colonne);
int valore_massimo(const int arr[][SIZE], size_t righe, size_t colonne);
int valore_minimo(const int arr[][SIZE], size_t righe, size_t colonne);
int calcolo_somma(const int arr[][SIZE], size_t righe, size_t colonne);
float calcolo_media(const int arr[][SIZE], size_t righe, size_t colonne);

int main() {

    int matrice[SIZE][SIZE] = {0};
    puts("Numero righe");
    unsigned int righe = input_dimensione();
    puts("Numero colonne");
    unsigned int colonne = input_dimensione();

    riempi_matrice(matrice, righe, colonne);

    int max = valore_massimo(matrice, righe, colonne);
    int min = valore_minimo(matrice, righe, colonne);
    int somma = calcolo_somma(matrice, righe, colonne);
    float media = calcolo_media(matrice, righe, colonne);

    printf("Valore massimo: %d\n", max);
    printf("Valore minimo: %d\n", min);
    printf("Somma dei valori: %d\n", somma);
    printf("Media dei valori: %.2f\n", media);

    return 0;
}

unsigned int input_dimensione()
{
    unsigned int dim;
    do {
        scanf("%u", &dim);
    } while (dim > 100);
    
    return dim;
}

void riempi_matrice(int arr[][SIZE], size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            printf("[%lu][%lu]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

int valore_massimo(const int arr[][SIZE], size_t righe, size_t colonne)
{
    int max = arr[0][0];
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int valore_minimo(const int arr[][SIZE], size_t righe, size_t colonne)
{
    int min = arr[0][0];
    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int calcolo_somma(const int arr[][SIZE], size_t righe, size_t colonne)
{
    int tot = 0;

    for (size_t i = 0; i < righe; i++) {
        for (size_t j = 0; j < colonne; j++) {
            tot += arr[i][j];
        }
    }
    return tot;
}

float calcolo_media(const int arr[][SIZE], size_t righe, size_t colonne)
{
    int somma = calcolo_somma(arr, righe, colonne);
    int num_elementi = righe * colonne;
    float media = (float)somma / num_elementi;
    return media;
}
