#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

int cards[9] = {0,0,0,0,0,0,0,0,0};
int turn, amountPlayer;

int houseThinking();
int houseAi();
int playerAction();
int totalCards();
int drawCard();
int visualizeHand ();
int resetCards ();
int arrayContains (int iArray[9], int iInput);

int main () {
    srand(time(NULL));
    resetCards();
    turn = 0;
    drawCard();
    visualizeHand();

    while (turn == 0 && totalCards() < 22) {
        playerAction();
    }
    if (totalCards() < 22){
        amountPlayer = totalCards();
        resetCards();
        houseAi();
        if (amountPlayer > totalCards() | totalCards() > 21)
            printf("You win\n");
        else if (amountPlayer == totalCards())
            printf("Draw\n");
        else
            printf("The house wins\n");
    }
    else
        printf("The house wins\n");
}

int houseThinking() {
    printf("House: thinking");
    for (int i = (rand() % 5); i<6; i++) {
        printf(".");
    }
    printf("\n");
    return 0;
}

int houseAi() {
    drawCard();
    while (totalCards() < amountPlayer && 
          totalCards() < 22 && 
          totalCards() != 21) {
        
        houseThinking();
        printf("House: draw\n");
        drawCard();
        visualizeHand();
        sleep(1);
    }
    if (totalCards() < 22) {
        houseThinking();
        printf("House: stay\n");
    }
    return 0;
}

int playerAction() {
    int iInput;
    while (1) {
        printf("Do you want to (1)draw or (2)stay\n");
        scanf("%d", &iInput);
        if (iInput == 1){
            drawCard();
            visualizeHand();
            return 1;
        }
        if (iInput == 2){
            turn = 1;
            return 1;
        }
    }
    return 0;
}

int totalCards() {
    int iTotal = 0;
    for (int i = 0; i<9; i++) {
        if(cards[i] == 1)
            iTotal += i+1;
    }
    return iTotal;
}

int drawCard(){
    int randomCard = 0;
        while (arrayContains(cards, 0)) {
            randomCard = rand() % 8;
            if (cards[randomCard] == 0) {
                cards[randomCard] = 1;
                return 1;
            }
        }
    return 0;
}

int visualizeHand () {
    printf("current Cards:\n");
    for (int i = 0; i<9; i++) {
        if (cards[i] == 1)
            printf("|%d| ", (i+2));
    }
        printf("  total amount: %d\n", totalCards());
    return 1;
}

int resetCards () {
    for (int i = 0; i<9; i++) {
        cards[i] = 0;
    }
    return 1;
}

int arrayContains (int iArray[9], int iInput) {
    for (int i = 0; i<9; i++) {
        if (iArray[i] == iInput)
            return 1;
    }
    return 0;
}