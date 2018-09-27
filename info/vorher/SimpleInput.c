#include <stdio.h>

int main (void) {
    int iInput0 = 0;
    int iInput1 = 0;
    
    printf("Requires integer value ");
    scanf("%d %d", &iInput0, &iInput1);
    iInput0 = iInput1*iInput0;
    printf("fneef: %d\n", iInput0);
    
    return 0;
}