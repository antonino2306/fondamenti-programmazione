#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char *stringhe[4];

    for (int i = 0; i < 4; i++) {
        char str_tmp[10];
        printf("Inserisci stringa\n");
        scanf(" %10[^\n]", str_tmp);

        stringhe[i] = (char*)calloc(strlen(str_tmp) + 1, sizeof(char));
        strcpy(stringhe[i], str_tmp);

    }

    for (int i = 0; i < 4; i++) {
        printf("%s\n", *(stringhe + i));
        free(stringhe[i]);
    }

    free(stringhe);

}