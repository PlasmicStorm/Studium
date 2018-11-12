#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInt(int low, int high) {
    return low + (rand() % (unsigned int) (high-low+1));
}
/*
int visualize(char cArry[][]) {
    for (int i= 0; i<10; i++) {
        for (int j=0; j<10; i++) {
            printf("%c ", cArry[j][i]);
        }
        printf("\n");
    }
    return 0;
}
*/

int main (void) {
    srand(time(NULL));
    char cArr[100][10];
    int iHeights[100];

    iHeights[0] = 5;
    for (int i = 1; i<100; i++) {
        iHeights[i] = iHeights[i-1] + randomInt(0, 2)-1;
    }
    
    for (int i = 0; i<100; i++) {
        for (int j = 0; j < 10; j++) {
            if(j < iHeights[i])
                cArr[i][j] = 'A';
            else
                cArr[i][j] = 'O';
        }
    }
    
    for (int i= 0; i<10; i++) {
        for (int j=0; j<100; j++) {
            printf("%c", cArr[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}
