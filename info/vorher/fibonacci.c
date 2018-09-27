#include <stdio.h>
#include <time.h>

int fibonacciRecoursion (int n);
int fibRec(int x0, int x1, int n);
int fibonacciLoop (int n);
    
int main (void) {
    int iInput = 0;
    printf("please input a number \n");
    scanf("%d", &iInput);
    clock_t begin = clock();
    printf("%d \n", fibonacciRecoursion(iInput));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time: %lf \n", time_spent);
}

int fibonacciRecoursion (int n) {
    if (n<0)
        return 0;
    return fibRec(0, 1, n-1);
}

int fibRec(int x0, int x1, int n) {
    if(n==0)
        return x1;
    return fibRec(x1, x0 + x1, n-1);
}

int fibonacciLoop (int n){
    if (n<1)
        return 0;
    int x0 = 0, x1 = 1;
    for (int i = 1; i<n; i++){
        x1 = x0 + x1;
        x0 = x1 - x0;
    }
    return x1;
}