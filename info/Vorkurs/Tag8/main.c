#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX 255

int solveLabyrinth(char *a, int sizeX, int sizeY);
int findPath(int posX, int posY, int direction, 
             int sizeX, int sizeY, char labyrinth[sizeX][sizeY]);
void print2dArray(int sizeX, int sizeY, char a[sizeX][sizeY]);
int uniq(char *a, char *b);
int numSum(char *a);
int cmpfunc(const void * a, const void * b);

int storedNumbers[60];

int main() {
//    uniq("TestA.txt",
//         "TestB.txt");
//    numSum("TestA.txt");
    solveLabyrinth("labyrinth.txt",16,16);
    return 1;
}

int solveLabyrinth(char *a, int sizeX, int sizeY) {
    FILE *fIn = fopen(a, "r");
    char labyrinth[sizeY][sizeX];
    printf("lade Datei in Array\n");
    char buffer[MAX];
    
    for(int i = 0; i < sizeY; i++) {
        if(fgets(buffer, MAX, fIn) == NULL)
            printf("Größe des Labyrinths nicht korrekt\n");
        printf("kompletter string: %s", buffer);
        for(int j = 0; j < sizeX; j++) {
            labyrinth[i][j] = buffer[j];
            printf("%c", labyrinth[i][j]);
            printf("(X %d,Y %d,RAW %c)\n", j, i, buffer[j]);
        }
        printf("\n");
    }
    printf("\n");
    print2dArray(16, 16, labyrinth);
    printf("trying to solve\n");
    findPath(3,6,0,sizeX,sizeY,labyrinth);
    printf("\n");
    print2dArray(16, 16, labyrinth);
    printf("%c\n", labyrinth[0][9]);
    return 1;
}

int findPath(int posX, int posY, int direction, 
             int sizeX, int sizeY, char labyrinth[sizeX][sizeY]) {
    printf("0\n");
    long paths[4] = {6,6,6,6};
    printf("1\n");
    if(labyrinth[posX][posY] == ' ')
        labyrinth[posX][posY] = '-';
    printf("2\n");
    printf("%c\n", labyrinth[1][0]);
    if(labyrinth[posX][posY-1] == ' '){
        paths[0] = direction * 10 + 1;
                printf("found new path at %i, %i\n", posX, posY);
                  paths[0] = findPath(posX, posY-1, paths[0], sizeX, sizeY, labyrinth);
    }
    if(labyrinth[posX+1][posY] == ' '){
        paths[1] = direction * 10 + 2;
        printf("found new path at %i, %i\n", posX+1, posY);
                  paths[1] = findPath(posX, posY-1, paths[1], sizeX, sizeY,  labyrinth);
    }
    if(labyrinth[posX][posY+1] == ' '){
        paths[2] = direction * 10 + 3;
        printf("found new path at %i, %i\n", posX, posY+1);
                  paths[2] = findPath(posX, posY-1, paths[2], sizeX, sizeY,  labyrinth);
    }
    if(labyrinth[posX-1][posY] == ' '){
        paths[3] = direction * 10 + 4;
                  paths[3] = findPath(posX, posY-1, paths[3], sizeX, sizeY,  labyrinth);
        printf("found new path at %i, %i\n", posX-1, posY);
    }
    printf("end of operation \n");
    printf("paths: %ld, %ld, %ld, %ld \n", paths[0]
                                         , paths[1]
                                         , paths[2]
                                         , paths[3]);
    if(paths[1] % 10 == 8){
        labyrinth[posX][posY] = '.';
        printf("found Solution");
    }
    if(labyrinth[posX][posY-1] == '*')
        return paths[0] * 10  + 8;
    if(labyrinth[posX+1][posY] == '*')
        return paths[1] * 10  + 8;
    if(labyrinth[posX][posY+1] == '*')
        return paths[2] * 10  + 8;
    if(labyrinth[posX-1][posY] == '*')
        return paths[3] * 10  + 8;
    return 0;
}

void print2dArray(int sizeX, int sizeY, char a[sizeX][sizeY]) {
    for(int i = 0; i < sizeY; i++) {
        for(int j = 0; j < sizeX; j++) {
            printf("%c", a[i][j]);
            //printf("%c (%d,%d)\n", a[i][j], i , j);
        }
        printf("\n");
    }
}

int numSum(char *a) {
//  storedNumbers = malloc(sizeof(int));
    FILE *fIn = fopen(a, "r");
    char buffer[256];
    int summe = 0;
    
    if(fgets(buffer, MAX, fIn) == NULL){
        printf("Fehler beim Öffnen der Datei");
        return 0;
    }
    
    int length = atoi(buffer);
    printf("Länge des Inputs beträgt: %d\n", length);
    
    if(length<0)
        return 0;
    for(int i = 0; i < length; i++) {
        fgets(buffer, MAX, fIn);
        storedNumbers[i] = atoi(buffer);
        printf("Aktuelles Element: %s", buffer);
    }
    printf("\nSortiere Elemente \n");
    qsort(storedNumbers, length, sizeof(int), cmpfunc);
    for(int i = 0; i < length; i++){
        printf("%d\n", storedNumbers[i]);
        summe += storedNumbers[i];
    }
    printf("Summe aller Zahlen: %d\n", summe);
    return 1;
}

int uniq(char *a, char *b) {
    
    FILE *fIn = fopen(a, "r");
    FILE *fOut;
    char buffer[256];
    char temp[256];
    int contains;
    
    if(fIn == NULL){
        printf("Datei konnte nicht geöffnet werden\n");
        return 0;
    }
    
    printf("Datei wurde erfolgreich geöffet\n");
    
    while(fgets(buffer, MAX, fIn) != NULL) {
        contains = 0;
        fOut = fopen(b, "r+");
        if(fOut == NULL) {
            printf("Second file can't. he just ... can't");
            return 0;
        }
        while(fgets(temp, MAX, fOut) != NULL) {
            if(strcmp(temp, buffer) == 0) 
                contains = 1;
        }
        if(contains == 0) {
            fprintf(fOut, "%s", buffer);
        }
        fclose(fOut);
    }
    printf("\n");
    return 1;
}
          
int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}