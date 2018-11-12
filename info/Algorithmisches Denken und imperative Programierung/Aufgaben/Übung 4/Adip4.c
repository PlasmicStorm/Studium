#include <stdio.h>
#include <math.h>

#define pi 3.141592653589793238462643383279

long long fakultät(int n);
int binomialkoeffizient(int n, int k);
int succ(int x);
int pre(int x);
int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
double fSin(float x);

int main() {
    float fInput = 0;
    printf("\nAufgabe 1:\n");
    printf("Die Fakultät von 8 ist: %lld\n", fakultät(8));
    printf("10 über 2 ergibt: %d\n", binomialkoeffizient(10 ,2));
    printf("Beim modifizierten Lottoproblem mit n = 10 k = 5 lassen sich %lld Arten auswählen\n", 
           binomialkoeffizient(10, 5) * fakultät(5));
    
    printf("\nAufgabe 2:\n");
    printf("2 + 0 = %d\n", add(2, 0));
    printf("-3 + 2 = %d\n", add(-3, 2));
    printf("2 - 0 = %d\n", sub(2, 0));
    printf("-3 - 2 = %d\n", sub(-3, 2));
    printf("2 * 0 = %d\n", mult(2, 0));
    printf("-3 * 2 = %d\n", mult(-3, 2));
    
    printf("\nAufgabe 3:\nGeben sie eine Zahl ein: ");
    scanf("%f", &fInput);
    printf("Sin(%f) = %f\n", fInput, fSin(0.785));
    printf("Vergleichswert mit sin(x) aus math.h: %f\n", sin(fInput));
}

long long fakultät(int n) {
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
        return fakultät(n) / (fakultät(k) * fakultät(n - k));
    if(0 <= n && n < k)
        return 0;
    printf("ERROR: Eingabe ungültig\n");
    return 0;
}

// Gibt den Nachfolger des übergebenen Wertes zurück
int succ(int x) {
    return ++x;
}

// Gibt den Vorgänger des übergebenen Wertes zurück
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
    return(add(x, mult(x, pre(y))));
}

double fSin(float x) {
    double fOutput = 0;
    double temp = 0;
    printf("test: %f\n", fOutput);
    x = fmod(x, 2*pi);
    for(int n = 0; n <= 5; n++) {
        temp = pow(-1, n) * (pow(x, 2*n+1) / fakultät(2*n+1));
        fOutput += temp;
        printf("test: %f, %f\n", fOutput, temp);
    }
    return fOutput;
}
