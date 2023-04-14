#include <stdio.h>

float media(float a, float b, float c);
float max(float a, float b, float c);
float min(float a, float b, float c);
float semidispersione(float n_max, float n_min);

int main() {
    float t1, t2, t3;
    float t_medio, t_max, t_min, incertezza;
    
    printf("Inserisci i 3 tempi misurati in secondi: ");
    scanf("%f %f %f", &t1, &t2, &t3);

    t_medio = media(t1, t2, t3);
    t_max = max(t1, t2, t3);
    t_min = min(t1, t2, t3);
    incertezza = semidispersione(t_max, t_min);

    printf("%.1f \u00b1 %.1f\n", t_medio, incertezza);
    return 0;
}

float media(float a, float b, float c) {
    return (a + b + c) / 3;
}

float max(float a, float b, float c) {
    if (a >= b) {

        if (a >= c) {
            return a;
        }
        else {
            return c;
        }

    }
    else if (b >= c) {
        return b;
    }
    else {
        return c;
    }
}

float min(float a, float b, float c) {
    if (a <= b) {

        if (a <= c) {
            return a;
        }
        else {
            return c;
        }

    }
    else if (b <= c) {
        return b;
    }
    else {
        return c;
    }
}

float semidispersione(float n_max, float n_min) {
    return (n_max - n_min) / 2;
}