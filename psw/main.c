#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define SIZE 20


void stampa_menu();
void crea_password(char psw[], size_t size, unsigned short int lv, unsigned short int lungh_psw);
char genera_num();
char genera_lettera();
char genera_char_sp();

int main() {

    unsigned short int livello_password, lunghezza_password = 0;
    char password[SIZE] = {'0'};
    
    do {

        stampa_menu();
        scanf("%hu", &livello_password);

        crea_password(password, SIZE, livello_password, lunghezza_password);
        printf("%s\n", password);
    
    } while (livello_password != 99);

    return 0;
}

void stampa_menu() {
    puts("Scegli il livello di difficoltà della password: ");
    puts("1: basso");
    puts("2: medio");
    puts("3: alto");
    puts("99 per uscire");
    printf("%s", "> ");
}

void crea_password(char psw[], size_t size, unsigned short int lv, unsigned short int lungh_psw)
{
    srand(time(NULL));
    char carattere;

    switch (lv)
    {
    case 1:
        lungh_psw = 10;
        for (size_t i = 0; i < lungh_psw ; i++) {
            short int num = rand() % 2;

            if (num)  {
                carattere = genera_num();
            }
            else {
                carattere = genera_lettera();
            }
            
            psw[i] = carattere;
        }
        break;
    case 2:
        lungh_psw = 15;

        for (size_t i = 0; i < lungh_psw - 1; i++) {
            short int num = rand() % 2;
            
            if (num) {
                carattere = genera_num();
            }
            else {
                carattere = genera_lettera();
            }

            psw[i] = carattere;
        }

        psw[lungh_psw - 1] = genera_char_sp();
        break;
    case 3:
        lungh_psw = 20;

        for (size_t i = 0; i < lungh_psw; i++) {
            short int selettore = rand() % 5;

            if ((selettore % 2) == 0) {
                carattere = genera_lettera();
            }
            else if (selettore == 1) {
                carattere = genera_num();
            }
            else {
                carattere = genera_char_sp();
            }

            psw[i] = carattere;
        }
        break;    
    default:
        break;
    }
}

char genera_num()
{
    char num = 48 + (rand() % 10);
    return num;
}

char genera_lettera()
{
    char lettera = 97 + (rand() % 26);
            
    short int maiusc = rand() % 2;

    if (maiusc) {
        lettera -= 32;
    }

    return lettera;
}

char genera_char_sp()
{
    char sp;
    short int select_sp = rand() % 2;
    
    if (select_sp) {
        sp =  33 + (rand() % 12);
    }
    else {
        sp = 58 + (rand() % 6);
    }

    return sp;
}
