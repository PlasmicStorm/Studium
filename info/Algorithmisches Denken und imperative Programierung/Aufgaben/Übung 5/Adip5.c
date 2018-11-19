#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
    Author:
        Simon Liessem   3100948
        Jan Simon Mathy 3206479
        Vincent Pamatat 3187769
        Nicolas Gassen  3230009
        Marc Flintrop   3208023
*/

char *reverseString(char *sInput);
int isPalindrom(char *sInput);
char *encrypt(char*s);
char *decrypt(char*s);
char *encryptByN(char*s, int n);
char *decryptByN(char*s, int n);
char nextLetter(char cInput, int n);
char prevLetter(char cInput, int n);

int main() {
    char *sInput = "hello World";
    //Aufgabe 1a I
    printf("%s\n", reverseString(sInput));
    //Aufgabe 1a II
    if(isPalindrom(sInput))
        printf("'%s' ist ein Palindrom\n", sInput);
    else
        printf("'%s' ist kein Palindrom\n", sInput);
    //Aufgabe 1b I
    printf("%s\n", decrypt(encrypt("„Fix 4 Schwyz!“, quäkt Jürgen blöd vom Paß.")));
    //Aufgabe 1b II
    printf("%s\n", decryptByN(encryptByN("„Fix 4 Schwyz!“, quäkt Jürgen blöd vom Paß.", 23), 23));
}

char *reverseString(char *sInput) {
    unsigned long ulInputSize = strlen(sInput);
    char *sTemp = malloc(ulInputSize * sizeof(char));
    for(int i = 0; i < ulInputSize; i++) {
        sTemp[i] = sInput[ulInputSize - 1 - i]; 
    }
    return sTemp;
}

int isPalindrom(char *sInput) {
    return !strcmp(sInput , reverseString(sInput));
}

char *encrypt(char*s) {
    unsigned long ulInputSize = strlen(s);
    char *sEncrypted = malloc(ulInputSize * sizeof(char));
    for(int i = 0; i < ulInputSize; i++) {
        sEncrypted[i] = nextLetter(s[i], 13);
    }
    return sEncrypted;
}
    
char *decrypt(char*s) {
    unsigned long ulInputSize = strlen(s);
    char *sDecrypted = malloc(ulInputSize * sizeof(char));
    for(int i = 0; i < ulInputSize; i++) {
        sDecrypted[i] = prevLetter(s[i], 13);
    }
    return sDecrypted;
}

char *encryptByN(char*s, int n) {
    unsigned long ulInputSize = strlen(s);
    char *sEncrypted = malloc(ulInputSize * sizeof(char));
    for(int i = 0; i < ulInputSize; i++) {
        sEncrypted[i] = nextLetter(s[i], n);
    }
    return sEncrypted;
}

char *decryptByN(char*s, int n) {
    unsigned long ulInputSize = strlen(s);
    char *sDecrypted = malloc(ulInputSize * sizeof(char));
    for(int i = 0; i < ulInputSize; i++) {
        sDecrypted[i] = prevLetter(s[i], n);
    }
    return sDecrypted;
}

char nextLetter(char cInput, int n) {
    //printf("%c, %d, %d\n", cInput, cInput, n); //Debug
    
    if(cInput <= 64 || cInput >= 123 || 
       (cInput >= 91 && cInput <= 96))
        return cInput;
    if(cInput >= 97) //Konvertiere Kleinbuchstaben zu Großbuchstaben
        cInput -= 32;
    if(n == 0) //Beendet die Rekursion
        return cInput;
    if(cInput == 90) //prüft overflow an Stelle 'Z'
        return nextLetter(65, n - 1);
    return nextLetter(cInput + 1, n - 1);
}

char prevLetter(char cInput, int n) {
    //printf("-%c, %d, %d\n", cInput, cInput, n); //Debug
    
    if(cInput <= 64 || cInput >= 123 || 
       (cInput >= 91 && cInput <= 96))
        return cInput;
    if(cInput >= 97) //Konvertiere Kleinbuchstaben zu Großbuchstaben
        cInput -= 32;
    if(n == 0) //Beendet die Rekursion
        return cInput;
    if(cInput == 65) //prüft underflow an Stelle 'A'
        return prevLetter(90, n - 1);
    return prevLetter(cInput - 1, n - 1);
}