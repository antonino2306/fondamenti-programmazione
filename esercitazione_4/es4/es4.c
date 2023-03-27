// Definire e implementare in C un programma che chieda all’utente di inserire tre numeri interi e li metta in
// ordine crescente.
#include <stdio.h>

void ordinamento_crescente(int n1, int n2, int n3);

int main() {
    int n1, n2, n3;
    int primo, secondo, terzo;

    printf("Inserire tre numeri: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    
    ordinamento_crescente(n1, n2, n3);

    return 0;
}

void ordinamento_crescente(int n1, int n2, int n3)
{
    int primo, secondo, terzo;
    if (n1 <= n3) {
        primo = n1;

        if (n2 <= n1) {
            primo = n2;
            secondo = n1;
            terzo = n3;
        }
        else if (n2 <= n3) {
            secondo = n2;
            terzo = n3;
        }
        else {
            secondo = n3;
            terzo = n2;
        }
    }
    else {
        primo = n3;
        if (n2 <= n3) {
            primo = n2;
            secondo = n3;
            terzo = n1;
        }
        else if (n2 <= n1) {
            secondo = n2; 
            terzo = n1;
        }
        else {
            secondo = n1;
            terzo = n2;
        }
    }

    printf("I numeri in ordine crescente sono: %d %d %d\n", primo, secondo, terzo);

}
