#include "Caller.h"
#include "BingoGame.h"
#include "BingoCard.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Caller::Caller(BingoGame *game)
{
    bingoGamePtr = game;
    assignCallerToBingoGame();
    // initialize every element of numsCalledArr to 0. As game is played, each element will be updated to
    //  the round's number.
    for (int i= 0; i < ARR_SIZE; i++) {
        numsCalledArr[i] = 0;
    }
    numsCalledCounter = 0; // updated as each round is played.
}

Caller::~Caller()
{
    delete bingoGamePtr;
    bingoGamePtr = nullptr;
}

void Caller::assignCallerToBingoGame()
{
    bingoGamePtr->callerPtr = this;
}

void Caller::generateCurrentRoundValue()
{
    bool newVal = false;
    int temp;
    bool valFound;
    unsigned seed = time(0); // for seeding the random number generator
    srand(seed);

    if (numsCalledCounter < ARR_SIZE) {
        while (newVal == false) {
            temp = (rand() % ARR_SIZE) + 1;
            bool valFound = false;
            for (int i = 0; valFound == false && i < ARR_SIZE; i++) {
                if (numsCalledArr[i] == temp) {
                    valFound = true;
                } else if (numsCalledArr[i] == 0) {
                    numsCalledArr[i] = temp;
                    numsCalledCounter += 1;
                    setCurrentRoundValue(); // must occur after numsCalledCounter += 1.
                    newVal = true;
                    valFound = true;
                }
            }
        }
    }
}

void Caller::setCurrentRoundValue()
{
    bingoGamePtr->currentRoundVal = numsCalledArr[numsCalledCounter - 1];
}