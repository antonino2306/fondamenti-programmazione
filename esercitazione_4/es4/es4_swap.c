#include <stdio.h>

void ordinamento_crescente(int n1, int n2, int n3);

int main() {
    int n1, n2, n3;

    printf("Inserisci 3 numeri: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    ordinamento_crescente(n1, n2, n3);
    
    return 0;

}

void ordinamento_crescente(int n1, int n2, int n3) {
    int tmp;
    if (n1 <= n3) {

        if (n2 <= n1) {
            // Scambia n2 ed n1
            tmp = n2;
            n2 = n1;
            n1 = tmp;
        }

        if (n3 <= n2) {
            // Scambia n3 ed n2
            tmp = n2;
            n2 = n3;
            n3 = tmp;
        }
    }
    else {
        // Scambia n1 ed n3
        tmp = n1;
        n1 = n3;
        n3 = tmp;

        if (n3 <= n2) {
            // Scambia n3 ed n2
            tmp = n2;
            n2 = n3;
            n3 = tmp;
        }

        if(n2 <= n1) {
            // Scambia n1 ed n2
            tmp = n2;
            n2 = n1;
            n1 = tmp;
        }

    }

    printf("Ordine crescente: %d %d %d\n", n1, n2, n3);
}