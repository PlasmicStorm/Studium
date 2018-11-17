#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void resetCards(int *cards);
int drawCard(int *cards);
void initializegenerator();

int main() {
    initializegenerator();
    int *cards = malloc(sizeof(int)*20);
    resetCards(cards);
    for(int i = 0; i <= 8; i++) {
        printf("%d\n", drawCard(cards));
    }
}

void resetCards(int *cards) {
    for(int i = 0; i <= 9; i++) {
        cards[i] = i+1;
    }
}

int drawCard(int *cards) {
    int random = 0, drawnCard = 0;
    draw:
    random = (rand() % 9) + 1;
    if(cards[random] != 0) {
        drawnCard = cards[random];
        cards[random] = 0;
        return drawnCard;
    }
    goto draw;
}

void initializegenerator() {
    srand(time(NULL));
}

