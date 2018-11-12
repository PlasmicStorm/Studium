#include <stdio.h>

int main(){
    
}

int istSchaltjahr (int iInput) {
    if (iInput % 4 == 0 && iInput % 100 =! 0)
        return 1;
    if (iInput % 400 == 0)
        return 1;
    return 0;
}