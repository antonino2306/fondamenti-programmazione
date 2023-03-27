#include <stdio.h>

void drawA();
void drawB();
void drawC();
void drawD();

int main(void) {
    
    drawA();

    drawB();

    drawC();

    drawD();
    return 0;
}

void drawA()
{
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%s", "*");
        }
        puts("");
    }
}

void drawB()
{
    for (int i = 10; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%s", "*");
        }
        puts("");
    }
}

void drawC()
{
    for (int i = 10; i >= 1; i--) {
        for (int j = 1; j <= 10 - i; j++) {
            printf("%s", " ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%s", "*");
        }
        puts("");
    }
}

void drawD()
{
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10 - i; j++) {
            printf("%s", " ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%s", "*");
        }
        puts("");
    }
}
