#include <stdio.h>
#include <stdlib.h>

void printArray(int *iArray, int size);
void fillArray(int *iArray, int size, int value);

int main() {
    int iTestArray[] = {2,3,2,5,2,3,5,7,8,9};
    //fillArray(iTestArray, 10, 4);
    printArray(iTestArray, 10);
    rotateArray(iTestArray, 10);
    printArray(iTestArray, 10);
}

void printArray(int *iArray, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d]\n", iArray[i]);
    }
}

void fillArray(int *iArray, int size, int value) {
    for (int i = 0; i < size; i++) {
        iArray[i] = value;
    }
}

void rotateArray(int *iArray, int size) {
    int temp_0,
        temp_1;
    for (int i = 0; i < size + 1 i++) {
        temp_0 = iArray[i-1];
        temp_1 = iArray[i];
        iArray[i] = temp_0;
    }
}