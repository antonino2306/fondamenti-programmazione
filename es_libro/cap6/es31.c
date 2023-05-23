#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindroma(const char* const str_left, const char* const str_right);


int main() {
    size_t dim;
    char *str;

    printf("Inserisci la dimensione della stringa: ");
    scanf("%lu", &dim);

    str = (char*)calloc(dim+1, sizeof(char));

    char formato[11];
    sprintf(formato, " %%%lu[^\n]", dim);

    puts("Inserisci stringa:");
    scanf(formato, str);

    if(palindroma(str, strchr(str, '\0') - 1)) {
        puts("La stringa è palindroma");
    }
    else {
        puts("La stringa non è palindroma");
    }

    free(str);
}

int palindroma(const char* const str_left, const char* const str_right)
{
    if (str_left == str_right) {
        return 1;
    }
    else if (*str_left != *str_right) {
        // l' if - else serve per ignorare gli spazi
        if (*str_left == ' ') {
            return palindroma(str_left + 1, str_right);
        }
        else if (*str_right == ' ') {
            return palindroma(str_left, str_right - 1);
        }
        else {
            return 0;
        }
    }
    else {
        return palindroma(str_left + 1, str_right - 1);
    }
    
}
