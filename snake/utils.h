#define ALTEZZA 20
#define BASE 40

// Funzioni all'avvio del gioco
extern void crea_mappa(char mappa[][BASE], size_t altezza, size_t base);
extern void posiziona_pg(char mappa[][BASE], size_t altezza, size_t base, const char pg);

// Funzione che si ripete spesso
extern void stampa_mappa(const char mappa[][BASE], size_t altezza, size_t base);
extern void muovi_pg_semplice(char mappa[][BASE], size_t altezza, size_t base, const char pg);

extern void genera_cibo(char mappa[][BASE], size_t altezza, size_t base);