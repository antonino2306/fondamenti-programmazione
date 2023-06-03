#include <stdio.h>
#include "header.h"

extern void stampa_menu() {
    
    puts("1. premi a per aggiungere un nuovo attrezzo");
    puts("2. premi b per modificare le informazioni su un attrezzo esistente");
    puts("3. premi c per eliminare un record");
    puts("4. premi d per visualizzare la lista degli attrezzi");
    puts("5. premi q per uscire");
    printf("%s", "> ");
}

void crea_nuovo_record(FILE *fp) {

    Attrezzo nuovo_attrezzo;

    printf("%s", "Inserisci codice record: ");
    scanf(" %u", &nuovo_attrezzo.record);

    printf("%s", "Inserisci il nome dell'attrezzo: ");
    scanf(" %30[^\n]", nuovo_attrezzo.nome);

    printf("%s", "Inserisci quantità: ");
    scanf(" %u", &nuovo_attrezzo.quantita);

    printf("%s", "Inserisci prezzo: ");
    scanf(" %f", &nuovo_attrezzo.prezzo);

    fprintf(fp, "%u,%s,%u,%.2f;\n",
            nuovo_attrezzo.record, nuovo_attrezzo.nome, 
            nuovo_attrezzo.quantita, nuovo_attrezzo.prezzo);
    

    fflush(fp);

}

void modifica_record(FILE *fp) {

}

void elimina_record(FILE *fp) {

    rewind(fp);

    unsigned int record_da_eliminare, r_letto;

    printf("%s", "Inserisci codice del prodotto: ");
    scanf("%u", &record_da_eliminare);

    // Devo copiare le righe precedenti a quella da eliminare
    // In un nuovo file, saltare quella che devo eliminare e
    // copiare tutte le altre nel nuovo file

}

unsigned int conta_record(FILE *fp) {

    unsigned int n_record = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        
        if (c == ';') {
            n_record++;
        }

    }

    return n_record;
}

void stampa_lista_record(FILE *fp) {
    
    unsigned int num_record = conta_record(fp);
    Attrezzo att_letto;

    rewind(fp);

    for (size_t i = 0; i < num_record; i++) {

       fscanf(fp, "%u", &att_letto.record);
       fgetc(fp);
       

       fscanf(fp, "%40[^,]", att_letto.nome);
       fgetc(fp);

       fscanf(fp, "%u", &att_letto.quantita);
       fgetc(fp);

       fscanf(fp, "%f", &att_letto.prezzo);
       fgetc(fp);

       printf("%u %10s   %u   %.2f\n", att_letto.record,
                att_letto.nome, att_letto.quantita, att_letto.prezzo);

    } 

}

extern void esegui_comando(char input, FILE *fp) {
    
    switch(input) {

        case 'a':
            crea_nuovo_record(fp);
            break;
        
        case 'b':
            modifica_record(fp);
            break;
        
        case 'c':
            elimina_record(fp);
            break;

        case 'd':
            stampa_lista_record(fp);
            break;
    
        default: break;
    }
}
