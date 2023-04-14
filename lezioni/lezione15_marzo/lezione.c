#include <stdio.h>

int main() {
    char x;
    char y;
    char z;
    printf("Inserisci un carattere: ");
    // La scanf in questo caso prende il carattere inserito che viene tolto dallo stdin
    // Rimane nello stdin il carattere di ritorno a capo che verrà presa dall prossima scanf
    // che usa %c. Per evitare il problema si può usare una scanf vuota;
    scanf("%c\n", &x);
    printf("%c", x);
    scanf("%c", &y);
    scanf("%c", &z);
    printf("%c\n",x);




    return 0;
}