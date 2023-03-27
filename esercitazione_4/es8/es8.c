// Implementare in C un programma che chieda all’utente di inserire un carattere minuscolo e dica se esso è una
// vocale o consonante.
#include <stdio.h>
#include <ctype.h>

int non_lettera(char lettera);
void riconoscimento_lettere(char lettera);

int main() {
    char lettera;

    printf("Inserisci una lettera: ");
    scanf("%c", &lettera);

    if (non_lettera(tolower(lettera))) {
        printf("DEVI INSERIRE UNA LETTERA\n");
        return 1;
    }

    riconoscimento_lettere(lettera);
    
    return 0;
}

int non_lettera(char lettera)
{   
    if ((lettera < 'a') || (lettera > 'z')) {
        return 1;
    }
    else 
        return 0;
}

void riconoscimento_lettere(char lettera)
{
    switch (tolower(lettera)) {
        case 'a':
            printf("Vocale\n");
        break;
        
        case 'e':
            printf("Vocale\n");
        break;
        
        case 'i':
            printf("Vocale\n");
        break;
        
        case 'o':
            printf("Vocale\n");
        break;
        
        case 'u':
            printf("Vocale\n");
        break;

        default:
            printf("Consonante\n");
        break;
    }

}
