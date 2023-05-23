#include <stdio.h>

size_t lunghezza_attuale_ricettario(FILE *fp);
void carica_ricette_da_file(FILE *fp, Pietanza *array, size_t  num_p, size_t indice_inizio);
void scrivi_ricetta_su_file(FILE *fp, Pietanza ricetta);