#include <stdio.h>
#define SIZE 100

int determina_max(int arr[], size_t size);
int determina_min(int arr[], size_t size);
int determina_secondo_max(int arr[], size_t size, int massimo);
int determina_secondo_min(int arr[], size_t size, int minimo);

int main() {

    int numeri[SIZE] = {0};
    int max, min, secondo_max, secondo_min;
    unsigned int size_utente;

    printf("Inserisci la dimensione dell'array (< 100): ");
    scanf("%u", &size_utente);

    for (size_t i = 0; i < size_utente; i++) {
        printf("Inserisci numero: ");
        scanf("%d", &numeri[i]);
    }

    max = determina_max(numeri, size_utente);
    min = determina_min(numeri, size_utente);
    secondo_max = determina_secondo_max(numeri, size_utente, max);
    secondo_min = determina_secondo_min(numeri, size_utente, min);
    printf("Massimo: %d\n", max);
    printf("Minimo: %d\n", min);
    printf("Secondo massimo: %d\n", secondo_max);
    printf("Secondo minimo: %d\n", secondo_min);



}

int determina_max(int arr[], size_t size)
{
    int massimo = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > massimo) {
            massimo = arr[i];
        }
    }
    return massimo;
}

int determina_min(int arr[], size_t size)
{
    int minimo = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }
    return minimo;
}

int determina_secondo_max(int arr[], size_t size, int massimo)
{
    int massimo2;
    
    if (arr[0] == massimo) {
        massimo2 = arr[1];
    }
    else {
        massimo2 = arr[0];
    }

    for (size_t i = 0; i < size; i++) {
        if (arr[i] > massimo2 && arr[i] < massimo) {
            massimo2 = arr[i];
        }
    }

    return massimo2;

}

int determina_secondo_min(int arr[], size_t size, int minimo)
{
    int minimo2;

    if (arr[0] == minimo) {
        minimo2 = arr[1];
    }
    else {
        minimo2 = arr[0];
    }

    for (size_t i = 0; i < size; i++) {
        if (arr[i] > minimo && arr[i] < minimo2) {
            minimo2 = arr[i];
        }
    }
    return minimo2;
}
