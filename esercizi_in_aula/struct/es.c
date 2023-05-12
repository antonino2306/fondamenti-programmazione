#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void stampa_persona(struct Persona p);
void stampa_data(struct Data d);
void stampa_impiegato(struct Impiegato i);

int main() {
    struct Impiegato giuseppe;

    printf("Inserisci nome: ");
    scanf(" %20[^\n]", giuseppe.anagrafica.nome);

    printf("Inserisci età: ");
    scanf("%u", &giuseppe.anagrafica.eta);

    printf("Inserisci sesso: ");
    scanf(" %c", &giuseppe.anagrafica.sesso);

    printf("Inserisci data di nascita GG MM AAAA: ");
    scanf("%u %u %u", &giuseppe.anagrafica.nascita.giorno, &giuseppe.anagrafica.nascita.mese, &giuseppe.anagrafica.nascita.anno);

    printf("Inserisci stipendio: ");
    scanf("%u", &giuseppe.stripendio);

   system("clear");

   stampa_impiegato(giuseppe);

    return 0;

}

void stampa_persona(struct Persona p)
{
    printf("Nome: %s\n", p.nome);
    printf("Età: %u anni\n", p.eta);
    printf("Sesso: %c\n", p.sesso);
    stampa_data(p.nascita);
}

void stampa_data(struct Data d)
{
    printf("Data di nascita: %u/%u/%u\n", d.giorno, d.mese, d.anno);
}

void stampa_impiegato(struct Impiegato i)
{
    stampa_persona(i.anagrafica);
    printf("Stipendio: %u euro\n", i.stripendio);
}
