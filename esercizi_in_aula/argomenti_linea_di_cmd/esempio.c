#include <stdio.h>

int main(int argc, char* argv[]) {
    
    printf("Hai inserito %d argomenti\n", argc);

    if (argc < 2) {
        puts("Errore: numero di parametri insufficiente");
        // return 1 indica che c'è stato un problema
        return 1;
    }

    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
}