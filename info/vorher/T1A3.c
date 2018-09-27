#include <stdio.h>

int main (void){
    int n = 7231;
    if ((n % 2) == 0){
        n = n/2;
    }
    else{
        n = (n + 1)/2;
    }
    printf("%i\n", n);
    return n;
}