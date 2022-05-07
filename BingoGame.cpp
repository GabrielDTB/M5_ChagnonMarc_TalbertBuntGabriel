#include "BingoGame.h"
#include "BingoCard.h"
#include <vector>
using namespace std;

BingoGame::BingoGame()
{
    vector<BingoCard*> cardsInPlay;
    callerPtr = nullptr;

}

BingoGame::~BingoGame()
{
    delete callerPtr;
    callerPtr = nullptr;

    // check if any BingoCards still exist; if so, call each card's destructor
    /*
    if (cardsInPlay.size() > 0) {

    }
    */
}

void BingoGame::assignCallerToBingoGame(Caller* c)
{
    callerPtr = c;
}

void BingoGame::addCardToGame(BingoCard* bCard)
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
BingoGame then 'asks' each BingoCard if it was a winner. If there are winners, their BingoCards
are printed and the game ends.
*/
void BingoGame::playRound()
{
    callerPtr->generateCurrentRoundValue();


}

int BingoGame::checkForWin()
{

    return 1;

}