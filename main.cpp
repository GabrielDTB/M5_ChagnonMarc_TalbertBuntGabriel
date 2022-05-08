#include <iostream>
#include <iomanip>
#include "BingoGame.h"
#include "BingoCard.h"
#include "Caller.h"

using namespace std;

//void printBingoCard(BingoCard &);

int main()
{
    // variable definitions
    int numBingoCards;
    int gameRound;
    int numWinners;

    cout << "\n generating Bingo Game.";
    BingoGame game1 = BingoGame();
    cout << "\n generating caller.";
    Caller caller1 = Caller(&game1);

    cout << "\nThis game will have three players, each with one Bingo card.";
    BingoCard bcard1(&game1);
    BingoCard bcard2(&game1);
    BingoCard bcard3(&game1);

    numWinners = 0;
    for (gameRound = 1; gameRound < 76; gameRound++)
    {
        cout << "\nRound " << gameRound << "! Caller's number is.... ";
        game1.playRound();
        cout << game1.getCurrentRoundValue() << "!";
        cout << "\nCheck those Bingo Cards:" << endl;
        displayBingoCardsInGame(&game1, false);
        cout << endl;
        numWinners = game1.checkForWin();
        if (numWinners > 0) gameRound = 76;
        /*
        if (numWinners > 0) {
            gameRound = 76;
        }
        */
    }

    if (numWinners > 0)
    {
        cout << "\nWe have ";
        if (numWinners == 1)
        {
            cout << "a winner! Here is the winning card:\n";
        } else
        {
            cout << numWinners << " winners! Here are the winning cards:\n";
        }
        displayBingoCardsInGame(&game1, true);
    } else
    {
        cout << "\nUnforunately, there were no winners.";
    }
    cout << "\nHere are the numbers called by the Caller:" << endl;
    displayNumbersCalled(&caller1);

    return 0;
}

// function to handle printing each individual BingoCard.
void printBingoCard(BingoCard &card)
{
    string RED_BACKGROUND_CODE = "\033[48;2;255;0;0m";
    string NORMAL_CODE = "\033[0m";
    string UNDERLINE_CODE = "\033[4m";
    cout << UNDERLINE_CODE << " B  I  N  G  O " << NORMAL_CODE << endl;
    for (unsigned int row = 0; row < 5; row++)
    {
        for (unsigned int column = 0; column < 5; column++)
        {
            if (card.cardValues[column][row])
            {
                cout << RED_BACKGROUND_CODE;
            }
            cout << " " << left << setw(2) << card.cardKeys[column][row] << NORMAL_CODE;
        }
        cout << endl;
    }
    /* for testing, can delete once we figure out why red background persists across row
    cout << endl;
    for (unsigned int row = 0; row < 5; row++)
    {
        for (unsigned int column = 0; column < 5; column++)
        {

            cout << " " << left << setw(2) << card.cardValues[column][row];
        }
        cout << endl;
    }
    */
}

// function to handle printing all BingoCards (iterates over BingoGame's cardsInPlay member)
void displayBingoCardsInGame(BingoGame *bGame, bool displayWinnersOnly)
{
    if (displayWinnersOnly)
    {
        for (BingoCard *g: bGame->cardsInPlay)
        {
            if (g->getClearedLines() > 0)
            {
                cout << "\n";
                printBingoCard(*g);
            }
        }
    } else
    {
        for (BingoCard *g: bGame->cardsInPlay)
        {
            cout << "\n";
            printBingoCard(*g);
        }
    }
}

void displayNumbersCalled(Caller *callerPtr)
{
    for (int i = 0; i < Caller::ARR_SIZE; i++)
    {
        if (callerPtr->numsCalledArr[i] != 0)
        {
            cout << callerPtr->numsCalledArr[i] << " ";
        } else
        {
            i = Caller::ARR_SIZE;
        }
    }
}