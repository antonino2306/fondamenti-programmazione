#include <stdio.h>

int main() {
    int flag = 1;
    char character;

    do {
        
        printf("%s", "Enter character: ");
        character = getchar();

        if (character >= '0' && character <= '9') {
            flag = 0;
        }
        else {
            printf("Character is: %c\n", character);
        }
        // Rimuove il carattere di ritorno a capo rimasto nello stdin
        // dall'istruzione precedente
        character = getchar();
    } while (flag);

    return 0;
}