#include <stdio.h>
#include <math.h>

int main () {
    //variables
    int iInput;
    int iOutput = 0; 
    //User Input
    printf("Geben sie eine gerade positive Ganzzahl ein: ");
    scanf("%d", &iInput); 
    //Calculations
    for (int i = 1; i < iInput+1; i++) {
        iOutput += i*i;
    }
    //Output
    printf("Die Summe aller Quadratzahlen von 1 bis %d ist %d\n", iInput, iOutput);
    return 1;
}