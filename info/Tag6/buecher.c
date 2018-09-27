#include "buecher.h"
#include <stdio.h>
#include <string.h>
    
int buchAnlegen(char ISBN[10], char BuchName[20], char Autor[20]) {
    buch bNew;
    strncpy(bNew.cISBN, ISBN, 10);
    strncpy(bNew.cBuchName, BuchName, 20);
    strncpy(bNew.cAutor, Autor, 20);
    printf("%s", bNew.cBuchName);
    
    return 0;
}

void buchBearbeiten() {
    
}

void buchLoeschen() {
    
}