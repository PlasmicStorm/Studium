#include <stdio.h>
#include <math.h>
#define true 1;
#define false 0;
int isPrime (int iInput , int i);

int main () {
        //Variabeln
    int iInput;
        //Abfrage der Nutzereingabe
    printf("Geben sie eine gerade positive Ganzzahl ein: ");
    scanf("%d", &iInput);
    if (iInput < 0) {
        printf("ERROR: Die eingegebene Zahl ist negativ\n");
        return false;
    }
        //Nachschauen ob die eingegeben Zahl eie Primzahl ist
    if (isPrime(iInput, iInput/2)) {
        printf("Die gegebene Zahl ist eine Primzahl\n");
    }
    else {
        printf("Die gegebene Zahl ist keine Primzahl\n");
    }
    return true;
}

int isPrime (int iInput , int i) {
        //Fallunterscheidung
    if (iInput <= 2) {
        if (iInput == 2) {
            return true;
        }
        return false;
        //Prüfen der Teilbarkeit
    }
    if (iInput % i == 0)
        return false;
        //Terminierung wen die Zahle eine Primzahl ist
    if (i == 2)
        return true;
        //Recursion
    return isPrime(iInput, i-1);
}