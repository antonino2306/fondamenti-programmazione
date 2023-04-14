#include <stdio.h>
#include <math.h>
#define SIZE 100

void inserisci_resistenze(float arr[], size_t size, size_t* num_res);
float parallelo(const float arr[], size_t size);
float serie(const float arr[], size_t size);

int main() {

    float resistenze[SIZE] = {0};
    float resistenza_totale;
    size_t num_resistenze = 0;
    
    inserisci_resistenze(resistenze, SIZE, &num_resistenze);

    short int user_input;
    printf("Il circuito è in serie (1) o in parallelo (2): ");
    scanf("%hd", &user_input);

    switch (user_input)
    {
    case 1:
        resistenza_totale = serie(resistenze, num_resistenze);
        break;

    case 2:
        resistenza_totale = parallelo(resistenze, num_resistenze);
        break;    
    default:
        break;
    }

    printf("Resistenza totale: %.2f\n", resistenza_totale);

    return 0;
}

void inserisci_resistenze(float arr[], size_t size, size_t* num_res)
{
    printf("Quante resistenze devi inserire (max 100):");
    scanf("%lu", &*num_res);

    for (size_t i = 0; i < *num_res; i++) {
        printf("r[%lu]: ", i);
        scanf("%f", &arr[i]);
    }

    puts("");

}

float parallelo(const float arr[], size_t size)
{
    float somma_res = 0;

    for (size_t i = 0; i < size; i++) {
        somma_res += 1 / arr[i];
    }

    float parallelo = pow(somma_res, -1);

    return parallelo;
}

float serie(const float arr[], size_t size)
{
    float somma_res = 0;

    for (size_t i = 0; i < size; i++) {
        somma_res += arr[i];
    }
    return somma_res;
}
