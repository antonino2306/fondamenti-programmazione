#include <stdio.h>
#include <math.h>
#define SIZE 100

double calcolo_norma(const double vettore[], size_t dim);
unsigned int in_ordine_crescente(const double vettore[], size_t dim);
void riempi_vettore(double vettore[], size_t dim);
unsigned int det_dimensione();
void stampa_menu();
void scegli_operazione(double vettore[], size_t dim);

int main() {

    double v[SIZE] = {0};
    unsigned int dimensione;

    dimensione = det_dimensione();

    scegli_operazione(v, dimensione);

    
    printf("Programma terminato\n");
    return 0;
   
}

double calcolo_norma(const double vettore[], size_t dim)
{
    double norma = 0, somma_comp = 0;

    for (size_t i = 0; i < dim; i++) {
        somma_comp += pow(vettore[i], 2);
    }
    norma = sqrt(somma_comp);
    return norma;

}

unsigned int in_ordine_crescente(const double vettore[], size_t dim)
{
    unsigned int ordinato = 1;
    for (size_t i = 0; (i < dim - 1 ) && (ordinato); i++) {
        if (vettore[i] > vettore[i+1]) {
            ordinato = 0;
        }
    }
    return ordinato;
}

void riempi_vettore(double vettore[], size_t dim)
{
    for (size_t i = 0; i < dim; i++) {
        printf("Inserire componente: ");
        scanf("%lf", &vettore[i]);
    }
}

unsigned int det_dimensione()
{
    unsigned int dim;
    printf("Inserisci dimensione (Max 100): ");
    scanf("%u", &dim);
    
    if (dim > 100) {
        printf("Dimensione troppo grande. Riduco a 100");
        dim = 100;
    }
    return dim; 
}

void stampa_menu() {
    puts("Scegli cosa fare:");
    puts("\tPremi 1 per inserire valori");
    puts("\tPremi 2 per calcolare la norma");
    puts("\tPremi 3 per vedere se i valori sono in ordine crescente");
    puts("\tPremi 4 per uscire");
    printf("> ");
    
}

void scegli_operazione(double vettore[], size_t dim)
{
    unsigned int input_utente, ordinato;
    double norma;
    do {
        stampa_menu();
        scanf("%u", &input_utente);

        switch (input_utente) {
            case 1:
                riempi_vettore(vettore, dim);
                break;

            case 2:
                norma = calcolo_norma(vettore, dim);
                printf("Norma: %.2f\n", norma);
                break;
            
            case 3:
                ordinato = in_ordine_crescente(vettore, dim);

                if (ordinato) {
                    printf("Ordinato\n");
                }
                else {
                    printf("Non ordinato\n");
                }
                break;
            
            case 4:
                break;

            default:
                break;
        }
    } while (input_utente != 4);

}
