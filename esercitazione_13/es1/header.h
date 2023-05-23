#define MAXLENGHT 30

struct pietanza {

    char nome[MAXLENGHT];
    char **ingredienti;
    unsigned int *dosi;
    unsigned int tempo_cottura;
    char tipo_piatto[10];

};

typedef struct pietanza Pietanza;

void crea_array(unsigned int *arr, size_t dim);
void riempi_array(Pietanza *arr, size_t dim, size_t *numero_ingredienti);
void inserisci_ingredienti(char **arr_ingredienti, size_t dim, unsigned int *arr_dosi);
void stampa_lista_pietanze(Pietanza *arr, size_t dim, size_t dim_ingredienti);
void libera_memoria(Pietanza *arr, size_t dim, size_t dim_ingredienti);
void stampa_ingredienti(char **arr_ingredienti, size_t dim_ingredienti);