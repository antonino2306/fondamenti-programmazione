#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"


void crea_mappa(char mappa[][BASE], size_t altezza, size_t base) {

    for (size_t i = 0; i < altezza; i++) {
        mappa[i][0] = '|';

        for (size_t j = 1; j < base - 1; j++) {

            if (i == 0 || i == altezza -1) {
                mappa[i][j] = '-'; 
            }
            else {
                mappa[i][j] = ' ';
            }
        }

        mappa[i][base-1] = '|';
    }

}

void posiziona_pg(char mappa[][BASE], size_t altezza, size_t base, const char pg) {

    srand(time(NULL));

    size_t x = rand() % base;
    size_t y = rand() % altezza;

    mappa[y][x] = pg;
}

void stampa_mappa(const char mappa[][BASE], size_t altezza, size_t base) {
    puts("");
    for (size_t i = 0; i < altezza; i++) {

        for (size_t j = 0; j < base; j++) {
            printf("%c", mappa[i][j]);
        }
        puts("");
    }
}

unsigned int cerca_item_x(const char mappa[][BASE], size_t altezza, size_t base, const char item) {

    for (size_t i = 0; i < altezza; i++) {
        for (size_t j = 0; j < base; j++) {
            if (mappa[i][j] == item) {
                return j;
            }
        }
    }

}

unsigned int cerca_item_y(const char mappa[][BASE], size_t altezza, size_t base, const char item) {
    
    for (size_t i = 0; i < altezza; i++) {
        for (size_t j = 0; j < base; j++) {
            if (mappa[i][j] == item) {
                return i;
            }
        }
    }

}

void sposta_pg(char mappa[][BASE], size_t altezza, size_t base, int dir[], const char pg, unsigned int* punti) {
    
    size_t coord_x = cerca_item_x(mappa, altezza, base, pg);
    size_t coord_y = cerca_item_y(mappa, altezza, base, pg);

    size_t nuova_y = coord_y + dir[1];
    size_t nuova_x = coord_x + dir[0];

    char tmp = mappa[coord_y][coord_x];
    mappa[coord_y][coord_x] = mappa[nuova_y][nuova_x];
    mappa[nuova_y][nuova_x] = tmp;

    // Aggiorna punteggio
    if (mappa[coord_y][coord_x] == '*') {
        *punti += 1;
        mappa[coord_y][coord_x] = ' ';
    }

}

void muovi_pg_semplice(char mappa[][BASE], size_t altezza, size_t base, const char pg) {
    unsigned int gioca = 1, punteggio = 0;
    char comando_precedente = 'p';
    int direzione[2] = {0}; //direzione[0] destra e sinistra; direzione[1] su e giù

    char comando_attuale;

    
    do {
        printf("Punteggio: %u\n", punteggio);
        printf("> ");
        scanf("%c", &comando_attuale);
        system("clear");

        switch (comando_attuale) {
            case 'a':
                direzione[0] = -1;
                direzione[1] = 0;
                if (comando_attuale == comando_precedente || comando_precedente == 'p') {
                    sposta_pg(mappa, altezza, base, direzione, pg, &punteggio);
                }
                break;
            
            case 'd':
                direzione[0] = 1;
                direzione[1] = 0;
                if (comando_attuale == comando_precedente || comando_precedente == 'p') {
                    sposta_pg(mappa, altezza, base, direzione, pg, &punteggio);
                }
                break;

            case 's':
                direzione[0] = 0;
                direzione[1] = 1;
                if (comando_attuale == comando_precedente || comando_precedente == 'p') {
                    sposta_pg(mappa, altezza, base, direzione, pg, &punteggio);
                }
                break;

            case 'w':
                direzione[0] = 0;
                direzione[1] = -1;
                if (comando_attuale == comando_precedente || comando_precedente == 'p') {
                    sposta_pg(mappa, altezza, base, direzione, pg, &punteggio);
                }

            case '\n': default:
                break;
        }

        // comando_precedente = comando_attuale;
        size_t coord_x = cerca_item_x(mappa, altezza, base, pg);
        size_t coord_y = cerca_item_y(mappa, altezza, base, pg);

        printf("x: %lu\ny: %lu\n", coord_x, coord_y);

        if (coord_x == 0 || coord_x == base - 1 || coord_y == 0 || coord_y == altezza - 1) {
            gioca = 0;
            printf("%s\n", "Hai perso");
            printf("Punteggio: %u\n", punteggio);
        }
        else {
            stampa_mappa(mappa, altezza, base);
        }


    } while (gioca);

}

void genera_cibo(char mappa[][BASE], size_t altezza, size_t base) {
    
    unsigned int pg_x = cerca_item_x(mappa, altezza, base, '@');
    unsigned int pg_y = cerca_item_y(mappa, altezza, base, '@');
    unsigned int cibo_x, cibo_y;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        do {

            cibo_x = rand() % base;
            cibo_y = rand() % altezza;

        } while (cibo_x == pg_x || cibo_y == pg_y || cibo_x == 0 || cibo_x == base - 1 || cibo_y == 0 || cibo_y == altezza - 1);

        mappa[cibo_y][cibo_x] = '*';
    }


}