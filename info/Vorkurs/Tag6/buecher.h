#ifndef _BUECHER_H
#define _BUECHER_H
#include "buecher.h"


struct buch {
    char cISBN[10];
    char cBuchName[20];
    char cAutor[20];
};

typedef struct buch buch;

int buchListe[20];
int buchAnlegen();
void buchBearbeiten();
void buchLoeschen();

#endif