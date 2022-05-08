#include "BingoGame.h"
#include "BingoCard.h"
#include <vector>
#include <iostream>

using namespace std;

BingoGame::BingoGame()
{
    vector<BingoCard *> cardsInPlay(0);
    numCardsInPlay = 0;
    callerPtr = nullptr;

}

void BingoGame::addCardToGame(BingoCard *bCard)
{
    cardsInPlay.push_back(bCard);
    numCardsInPlay += 1;
    return;
}

int BingoGame::getCurrentRoundValue()
{
    return currentRoundVal;
}

/*
playRound first validates that a Caller is associated with the BingoGame and at least
one BingoCard is associated with the BingoGame. Then, it calls the Caller, who generates
the next round's number, passes it back to BingoGame. BingoGame then passes the number
to all associated BingoCards. Each BingoCard is responsible for updating its 5 x 5 panel
and checking if it won on that round.
*/
void BingoGame::playRound()
{
    if (callerPtr == nullptr || numCardsInPlay < 1) {
        cout << "\nGame is not correctly set up (either missing a caller or any Bingo Cards). " <<
        "Please resolve setup then rerun this program.";
        exit (EXIT_FAILURE);
    }
    // caller generates a new (random) value. Caller will assign to BingoGame
    callerPtr->generateCurrentRoundValue();

    // BingoGame iterates over each BingoCard in cardsInPlay, and passes the round's number to the cards.
    for (BingoCard *bCard: cardsInPlay)
    {
        bCard->markValue(getCurrentRoundValue());
    }
        return;
}

// returns the number of winners (value could be in range [0,numCardsInPlay])
int BingoGame::checkForWin()
{
    int numWinners = 0;
    for (BingoCard *bCard: cardsInPlay)
    {
        if (bCard->getClearedLines() > 0) {
            numWinners += 1;
        }
    }
    return numWinners;
}