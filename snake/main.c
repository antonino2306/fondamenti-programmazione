#include <stdio.h>
#include "utils.h"



int main() {

    char mappa[ALTEZZA][BASE];
    const char snake_face = '@';

    crea_mappa(mappa, ALTEZZA, BASE);
    posiziona_pg(mappa, ALTEZZA, BASE, snake_face);
    genera_cibo(mappa, ALTEZZA, BASE);
    stampa_mappa(mappa, ALTEZZA, BASE);

    muovi_pg_semplice(mappa, ALTEZZA, BASE, snake_face);


    return 0;
}