#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
    Author:
        Simon Liessem   3100948
        Jan Simon Mathy 3206479
        Vincent Pamatat 3187769
        Nicolas Gassen  3230009
        Marc Flintrop   3208023
*/

#define pi 3.141592653589793238462643383279

long long fakultaet(int n);
int binomialkoeffizient(int n, int k);
int succ(int x);
int pre(int x);
int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
double dSin(float x);
double dCos(float x);
double dExp(float x);
void pythagorasTriplet(int x);
void initializegenerator();
void muenzrueckgabe();

int main() {
    initializegenerator();
    float fInput = 0;
    int iInput = 0;
    printf("\nAufgabe 1:\n");
    printf("Die Fakultät von 8 ist: %lld\n", fakultaet(8));
    printf("10 über 2 ergibt: %d\n", binomialkoeffizient(10 ,2));
    printf("Beim modifizierten Lottoproblem mit n = 10 k = 5 lassen sich %lld Arten auswählen\n", 
           binomialkoeffizient(10, 5) * fakultaet(5));
    
    printf("\nAufgabe 2:\n");
    printf("2 + 0 = %d\n", add(2, 0));
    printf("-3 + 2 = %d\n", add(-3, 2));
    printf("2 - 0 = %d\n", sub(2, 0));
    printf("-3 - 2 = %d\n", sub(-3, 2));
    printf("2 * 0 = %d\n", mult(2, 0));
    printf("-3 * 2 = %d\n", mult(-3, 2));
    
    printf("\nAufgabe 3:\nGeben sie eine Zahl ein: ");
    scanf("%f", &fInput);
    printf("Sin(%f) = %f\n", fInput, dSin(fInput));
    printf("Vergleichswert mit sin(x) aus math.h: %f\n", sin(fInput));
    printf("Cos(%f) = %f\n", fInput, dCos(fInput));
    printf("Vergleichswert mit cos(x) aus math.h: %f\n", cos(fInput));
    printf("Exp(%f) = %f\n", fInput, dCos(fInput));
    
    printf("\nAufgabe 4: Alle Pythagoras Triplets bis 50\n");
    pythagorasTriplet(50);
    
    muenzrueckgabe();
}

long long fakultaet(int n) {
    long long llOutput = 1;
    
    if(n < 0) {
        printf("ERROR: Fakultät kann nicht gebildet werden (n < 1)\n");
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        llOutput *= i+1;
    }
    
    return llOutput;
}

int binomialkoeffizient(int n, int k) {
    if(0 <= k && k <= n)
        return fakultaet(n) / (fakultaet(k) * fakultaet(n - k));
    if(0 <= n && n < k)
        return 0;
    printf("ERROR: Eingabe ungültig\n");
    return 0;
}

int succ(int x) {
    return ++x;
}

int pre(int x) {
    return --x;
}

int add(int x, int y) {
    if(y > 0)
        return add(succ(x), pre(y));
    if(y < 0)
        return add(pre(x), succ(y));
    return x;
}

int sub(int x, int y) {
    if(y > 0)
        return sub(pre(x), pre(y));
    return x;
}

int mult(int x, int y) {
    if(y == 0)
        return 0;
    return add(x, mult(x, pre(y)));
}

double dSin(float x) {
    double dOutput = 0;
    double dTemp;
    for(int n = 0; n <= 5; n++) {
        dTemp = pow(-1, n) * (pow(x, (2*n)+1) / fakultaet((2*n)+1));
        dOutput += dTemp;
    }
    return dOutput;
}

double dCos(float x) {
    double dOutput = 0;
    double dTemp;
    for(int n = 0; n <= 5; n++) {
        dTemp = pow(-1, n) * (pow(x, 2*n) / fakultaet(2*n));
        dOutput += dTemp;
    }
    return dOutput;
}

double dExp(float x) {
    double dOutput = 0;
    double dTemp;
    for(int n = 0; n <= 10; n++) {
        dTemp = pow(x, n) / fakultaet(n);
        dOutput += dTemp;
    }
    return dOutput;
}

void pythagorasTriplet(int x) {
    int temp = 0;
    for(int a = 0; a <= x; a++) {
        for(int b = 0; b <= x; b++) {
            for(int c = 0; c <= x; c++) {
                temp = pow(a, 2) + pow(b, 2);
                if(a < b && b < c && temp == pow(c, 2))
                    printf("%d, %d, %d\n", a, b, c);
            }
        }
    }
}

void initializegenerator() {
    srand(time(NULL));
}

void muenzrueckgabe() {
    int muenzen[] = {50, 20, 10, 5, 2, 1};
    int iLow = rand() % 200, 
        iHigh = 0;
    
    getInput:
        printf("Enter a Number higher than %d\n>", iLow);
        scanf("%d", &iHigh);
        if(iHigh < iLow)
            goto getInput;
    
    int iDiff = iHigh - iLow;
    printf("Rückgeld: ");
    for(int i = 0; i <= 5; i++) {
        while(iDiff - muenzen[i] >= 0) {
            iDiff -= muenzen[i];
            printf("(%d) ", muenzen[i]);
        }
    }
    printf("\n");
}