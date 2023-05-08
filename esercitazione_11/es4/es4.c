#include <stdio.h>
#include <stdlib.h>


void conta_caratteri(char *str, unsigned int *n_vocali, unsigned int *n_altri);

int main() {

    size_t lunghezza_str;
    scanf("%lu", &lunghezza_str);

    char *str = (char*)malloc((lunghezza_str+1) * sizeof(char));

    puts("Inserisci stringa:");
    
    //? In questo modo riesco a fare leggere alla scanf tanti caratteri quanto
    //? la lunghezza inserita in input
    char formato[12];
    sprintf(formato, " %%%lu[^\n]", lunghezza_str);
    scanf(formato, str);

    printf("%s\n",str);

    unsigned int num_vocali = 0, num_altri_char = 0;

    conta_caratteri(str, &num_vocali, &num_altri_char);

    printf("Numero di vocali: %u\nNumero di altri caratteri: %u\n", num_vocali, num_altri_char);

    free(str);


}

void conta_caratteri(char *str, unsigned int *n_vocali, unsigned int *n_altri)
{
    size_t i = 0;
    while (*(str + i) != '\0') {
        switch (*(str + i))
        {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                (*n_vocali)++;
                break;
            
            default:
                (*n_altri)++;
                break;
        }
        i++;
    }
}
