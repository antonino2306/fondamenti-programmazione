#include <stdio.h>
#include <stdlib.h>

void print_reverse(const char* const str, const char* const str_first_adr);

int main() {
    size_t dim;
    const char *str;

    printf("Inserisci la dimensione della stringa: ");
    scanf("%lu", &dim);

    str = (char*)calloc(dim+1, sizeof(char));

    char formato[11];
    sprintf(formato, " %%%lu[^\n]", dim);

    puts("Inserisci stringa:");
    scanf(formato, str);

    print_reverse(str + dim - 1, str);

    free(str);
}

void print_reverse(const char* const str, const char* const str_first_adr)
{
    if (str == str_first_adr) {
        printf("%c\n", *str_first_adr);
        return;
    }
    else {
        printf("%c", *str);
        return print_reverse((str - 1), str_first_adr);
    }
}
