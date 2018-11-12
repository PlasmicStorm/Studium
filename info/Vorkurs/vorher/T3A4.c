#include <stdio.h>
#include <math.h>

int main () {
    
}

int expo(float x) {
    for (int i = 0; i < 100; i++) {
        x = powf(x,i)/ i!;
    }
}