#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

void riempi_array(double arr[], const size_t dim);
void stampa_array(const double arr[], const size_t dim);
void max(const double arr1[], const size_t dim, double* max);
void max_tra_insiemi(const double arr1[], const double arr2[], const size_t dim, double* max_insiemi);
void min(const double arr[], const size_t dim, double* min);
void min_tra_insiemi(const double arr1[], const double arr2[], const size_t dim, double* min_insiemi);

int main() {

    double insieme_a[SIZE], insieme_b[SIZE];
    
    puts("Inserisci gli elementi del primo insieme: ");
    riempi_array(insieme_a, SIZE);

    puts("Inserisci gli elementi del secondo insieme");
    riempi_array(insieme_b, SIZE);

    system("clear");

    puts("Insieme A:");
    stampa_array(insieme_a, SIZE);

    puts("Insieme B:");
    stampa_array(insieme_b, SIZE);

    double max_ab, min_ab;

    max_tra_insiemi(insieme_a, insieme_b, SIZE, &max_ab);
    min_tra_insiemi(insieme_a, insieme_b, SIZE, &min_ab);
    printf("Max{A, B} = %.2lf\n", max_ab);
    printf("min{A, B} = %.2lf\n", min_ab);

}

void riempi_array(double arr[], const size_t dim)
{
    for (size_t i = 0; i < dim; i++) {
        printf("[%lu]: ", i);
        scanf("%lf", arr + i);
    }
}

void stampa_array(const double arr[], const size_t dim)
{
    for (size_t i = 0; i < dim; i++) {
        printf("[%lu] = %0.2lf\n", i, *(arr + i));
    }
    puts("");
}

void max(const double arr1[], const size_t dim, double *max)
{
    *max = *arr1;
    for (size_t i = 0; i < dim; i++) {
        if (*(arr1 + i) >= *max) {
            *max = *(arr1 + i);
        }
    }
}

void max_tra_insiemi(const double arr1[], const double arr2[], const size_t dim, double *max_insiemi)
{
    double max1, max2;
    max(arr1, dim, &max1);
    max(arr2, dim, &max2);

    if (max1 > max2) {
        *max_insiemi = max1;
    }
    else {
        *max_insiemi = max2;
    }

}

void min(const double arr[], const size_t dim, double *min)
{
    *min = *arr;
    for (size_t i = 0; i < dim; i++) {
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
    }
}

void min_tra_insiemi(const double arr1[], const double arr2[], const size_t dim, double *min_insiemi)
{
    double min1, min2;

    min(arr1, dim, &min1);
    min(arr2, dim, &min2);

    if (min1 < min2) {
        *min_insiemi = min1;
    }
    else {
        *min_insiemi = min2;
    }
}
