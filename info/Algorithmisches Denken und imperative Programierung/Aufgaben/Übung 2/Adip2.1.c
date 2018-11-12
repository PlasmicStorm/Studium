#include <stdio.h>
#include <math.h>

long fibRec(long n);
void first50Fib();

int main(){
    int iInput = 0;
    printf("Enter a Number: ");
    scanf("%i", &iInput);
    printf("The fibonacci of the given number is %ld\n", fibRec(iInput));
    first50Fib();
}

long fibRec(long n){
    if(n <= 1) 
        return n;
    return fibRec(n-1) + fibRec(n-2);
}

void first50Fib(){
    unsigned long long fib0 = 0;
    unsigned long long fib1 = 1;
    unsigned long long temp = 0;
    for(int i = 0; i <50; i++){
        printf("%i: %llu\n", i+1, fib0);
        temp = fib1+fib0;
        fib0 = fib1+temp;
        fib1 = temp+fib0;
    }
}