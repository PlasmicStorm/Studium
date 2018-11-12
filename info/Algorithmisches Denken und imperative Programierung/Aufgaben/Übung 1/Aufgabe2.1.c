#include <stdio.h>
#include <math.h>

int main () {
        //variables
    int iInput;    
    printf("Geben sie eine gerade positive Ganzzahl ein: ");
    scanf("%d", &iInput); //User Input
    printf("\nDie Summe aller Zahlen von 1 bis %d ist %d\n", iInput, (iInput * (iInput + 1)) / 2); //calculations
    return 1;
}