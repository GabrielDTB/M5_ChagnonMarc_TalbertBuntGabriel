#include "Caller.h"
#include "BingoGame.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Caller::Caller(BingoGame *game)
{
    bingoGamePtr = game;
    assignCallerToBingoGame();
    numsCalledCounter = 0; // updated as each round is played.
}

/**
 * Used primarily for testing, this constructs a caller with a fixed set of values.
 * @param game the game that it gets assigned to
 * @param flag just makes the compiler use this constructor
 */
Caller::Caller(BingoGame *game, bool flag)
{
    bingoGamePtr = game;
    assignCallerToBingoGame();
    numsCalledCounter = 0; // updated as each round is played.

    usePregeneratedNumbers = true;
    for (unsigned int i = 0; i < 75; i++)
    {
        pregeneratedNumbers[i] = i + 1;
    }
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

    if (numsCalledCounter < ARR_SIZE)
    {
        while (newVal == false)
        {
            // Here for testing purposes
            if (usePregeneratedNumbers)
            {
                temp = pregeneratedNumbers[numsCalledCounter];
            } else
            {
                temp = (rand() % ARR_SIZE) + 1;
            }
            bool valFound = false;
            for (int i = 0; valFound == false && i < ARR_SIZE; i++)
            {
                if (numsCalledArr[i] == temp)
                {
                    valFound = true;
                } else if (numsCalledArr[i] == 0)
                {
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