struct Data {

    unsigned int giorno;
    unsigned int mese;
    unsigned int anno;

};

struct Persona {
    char nome[20];
    unsigned int eta;
    char sesso;
    struct Data nascita;
};

struct Impiegato {
    struct Persona anagrafica;
    unsigned int stripendio;
};
