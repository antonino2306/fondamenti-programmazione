#include <stdio.h>
#include "../es2/header.h"

size_t lunghezza_attuale_ricettario(FILE *fp) {
    char carattere_letto;
    size_t num_p = 0;
    while ((carattere_letto = fgetc(fp)) != EOF) {

        if (carattere_letto == ';') {
            num_p++;
        }

    }
    // In questo modo ritorno all'inizio del file per poter leggere le ricette
    rewind(fp);
    return num_p;
}

void carica_ricette_da_file(FILE *fp, Pietanza *array, size_t num_p, size_t indice_inizio) {
    //? Tutte le chiamate a fgetc servono per rimuovere le , e il ;
    for (size_t i = indice_inizio; i < num_p; i++) {

        fscanf(fp, " %30[^,]", (array + i)->nome);
        fgetc(fp);
        fscanf(fp, "%u", &((array + i)->num_ingredienti));
        fgetc(fp);

        (array+i)->ingredienti = (char**)calloc((array+i)->num_ingredienti, sizeof(char));
        (array+i)->dosi = (unsigned int*)calloc((array+i)->num_ingredienti, sizeof(unsigned int));


        for (size_t j = 0; j < (array+i)->num_ingredienti; j++) {
            
            (array+i)->ingredienti[j] = (char*)calloc(MAXLENGHT, sizeof(char));

            fscanf(fp, "%30[^,]", (array + i)->ingredienti[j]);
            fgetc(fp);
            fscanf(fp, "%u", &((array + i)->dosi[j]));
            fgetc(fp);
        }

        fscanf(fp, "%u",  &((array + i)->tempo_cottura));
        fgetc(fp);
        fscanf(fp, " %10[^;]", (array+i)->tipo_piatto);
        fgetc(fp);

    }

}

void scrivi_ricetta_su_file(FILE *fp, Pietanza ricetta) {

    fprintf(fp, "%s,%u,", ricetta.nome, ricetta.num_ingredienti);
    
    for (size_t i = 0; i < ricetta.num_ingredienti; i++) {

        fprintf(fp, "%s,%u,", ricetta.ingredienti[i], ricetta.dosi[i]);
    }

    fprintf(fp, "%u,%s;\n", ricetta.tempo_cottura, ricetta.tipo_piatto);

}