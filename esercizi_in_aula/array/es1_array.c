// Scrivere un programma che gestisce un array di 6 interi che rappresentano i voti
// di 6 studenti. L'utente attraverso un comando deve poter scegliere di:
// - inserire i voti
// - stampare i voti dal primo all'ultimo
// - stampare i voti dall'ultimo al primo
// - stampare voto max e min, indicando anche la posizione
// - stampare il vodo medio

#include <stdio.h>
#define SIZE 6

void stampa_menu();
void inizializza_array(int array[], size_t size);
void stampa_voti(int array[], size_t size);
void stampa_inverso(int array[], size_t size);
void stampa_max_min(int array[], size_t size);
float voto_medio(int array[], size_t size);


int main() {
    int voti[SIZE] = {0}, comando;
    float media;
    do {
        stampa_menu();
        scanf("%d", &comando);

        switch (comando)
        {
            case 0:
                printf("Programma terminato\n"); 
                break;
            
            case 1:
                inizializza_array(voti, SIZE);
                break;
        
            case 2:
                stampa_voti(voti, SIZE);
                break;
        
            case 3:
                stampa_inverso(voti, SIZE);
                break;
            
            case 4: 
                stampa_max_min(voti, SIZE);
                break;
            case 5:
                media = voto_medio(voti, SIZE);
                printf("Media voti: %.2f\n\n", media);
                break;
            default:
                break;
        }
    } while(comando != 0);
    
    
    
    return 0;
}

void stampa_menu()
{
    printf("Decidi cosa vuoi fare:\n");
    printf("\t1 per inserire i voti\n");
    printf("\t2 per stampare i voti dal primo all'ultimo\n");
    printf("\t3 per stampare i voti dall'ultimo al primo\n");
    printf("\t4 per stampare voto massimo e minimo\n");
    printf("\t5 per stampare il voto medio\n");
    printf("\t0 per uscire\n");
    printf("> ");

}

void inizializza_array(int array[], size_t size)
{
    for(size_t i = 0; i < SIZE; i++) {
        printf("voti[%ld] = ", i);
        scanf("%d", &array[i]);
    }
}

void stampa_voti(int array[], size_t size)
{
    printf("I voti sono: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void stampa_inverso(int array[], size_t size)
{
    printf("I voti sono: ");
    for (size_t i = 1; i <= size; i++) {
        printf("%d ", array[size - i]);
    }
}

void stampa_max_min(int array[], size_t size)
{
    int max = array[0], min = array[0], pos_max = 0, pos_min = 0;

    for(size_t i = 1; i < size; i++) {
        if (max < array[i]) {
            max = array[i];
            pos_max = i;
        }

        if (min > array[i]) {
            min = array[i];
            pos_min = i;
        }
    }

    printf("Max = %d alla posizione %d\n", max, pos_max);
    printf("Min = %d alla posizione %d\n", min, pos_min);
}

float voto_medio(int array[], size_t size)
{
    float media;
    int somma_voti = 0;
    for (size_t i = 0; i < size; i++) {
        somma_voti += array[i];
    }
    media = (float)somma_voti / size;
    return media;
}
