#include <stdio.h>

int main() {
    
    printf("char - #bytes: %ld\n", sizeof(char));  // 1 byte
    printf("short - #bytes: %ld\n", sizeof(short int)); // 2 bytes
    printf("int - #bytes: %ld\n", sizeof(int)); // 4
    printf("long - #bytes: %ld\n", sizeof(long int)); // 8
    printf("float - #bytes: %ld\n", sizeof(float)); // 4
    printf("double - #bytes: %ld\n\n", sizeof(double)); // 8
    
    char a = 'a';
    double num = 2.33;

    printf("Dimensione di a char in byte: %ld\n", sizeof(a));
    printf("Dimensione di a int in byte: %ld\n\n", sizeof(((int)a)));

    printf("Dimensione di num double in byte: %ld\n", sizeof(num));
    printf("Dimensione di num int in byte: %ld\n", sizeof((int)num));
    return 0;
}