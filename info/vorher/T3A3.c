#include <stdio.h>

int main(){
    
}

int power (duble a, int b) {
    int k = 0;
    if(a == 0)
        return 0;
    while (a >1) {
        if (a % 2 =! 0) {
            a--;
            k = k + b;
        }
        else {
            a = a/2;
            b = b*2;
        }        
    }
    return k + b;
}