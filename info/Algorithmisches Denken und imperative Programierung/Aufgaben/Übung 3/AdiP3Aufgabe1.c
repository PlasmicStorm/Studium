#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializegenerator() {
    srand(time(NULL));
}

int karteziehen() {
    // Sie koennen Zufallszahlen generieren, indem Sie die Funktion rand() aufrufen
    // z.B. int zufall = rand();
    return((rand() % 9) + 2);

}

int main() {
    initializegenerator();
    // Code fuer den Spielablauf
    printf("%d\n", karteziehen());
    return 0;
}