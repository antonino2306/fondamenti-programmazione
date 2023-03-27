// Permettere all’utente di inserire due numeri e un operatore tra +, -, /, * e stampi il risultato
// dell’operazione.
#include <stdio.h>

float calcolo(float a, float b, char op);

int main() {
    float x, y, risultato;
    char op;

    printf("Inserisci due numeri: ");
    scanf("%f %f", &x, &y);

    printf("Inserisci una operazione tra + - * /: ");
    scanf("%s", &op);

    risultato = calcolo(x, y, op);

    printf("Risultato: %.2f\n", risultato);

    return 0;
}

float calcolo(float a, float b, char op) {
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        return 0;
        break;
    }
}