#define MAXLENGHT 30
struct prodotto {
    char nome[MAXLENGHT];
    float prezzo;
    unsigned int percentuale_sconto;
    struct prodotto *succ;
    struct prodotto *prec;
};

typedef struct prodotto Prodotto;

void stampa_menu_principale();
void stampa_sottomenu();

Prodotto *aggiungi_promozione(Prodotto *volantino, char nome[], float prezzo, unsigned int sconto);
void elimina_volantino(Prodotto *volantino);
void stampa_volantino(Prodotto *volantino);
void sfoglia_volantino(Prodotto *volantino);

Prodotto *elimina_promozione(Prodotto *volantino, char nome[]);
void trova_sconto_massimo(Prodotto *volantino);