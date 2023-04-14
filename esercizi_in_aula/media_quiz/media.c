#include <stdio.h>

int main() {
    unsigned int grade, student_number, counter = 0, total = 0;
    float average;

    printf("Inserisci il numero degli studenti che hanno sostenuto il quiz: ");
    scanf("%d", &student_number);

    if (student_number == 0) {
        average = 0;
        printf("Nessuno studente ha sostenuto il quiz. Media: %.1f\n", average);
        return 0;
    }

    while (counter < student_number) {
        printf("%s", "Inserisci voto: ");
        scanf("%d", &grade);
        total += grade;
        counter++;
    }

    average = (float)total / (float)counter;
    printf("La media è: %.2f\n", average);

    return 0;
}

//TODO modificare il programma: chiedere prima il numero di voti da inserire