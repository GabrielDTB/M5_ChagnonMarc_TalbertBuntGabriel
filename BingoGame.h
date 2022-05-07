#ifndef BINGOGAME_H
#define BINGOGAME_H
#include <vector>
#include "BingoCard.h"
#include "Caller.h"

class BingoGame
{
    private:
        int currentRoundVal;
        std::vector<BingoCard*> cardsInPlay;
        Caller* callerPtr;
    
    public:
        BingoGame();                                                    // constructor
        ~BingoGame();                                                   // destructor, deletes pointers to Caller and BingoCards
        int numCardsInPlay;                                             // int to track number of BingoCards associated with the BingoGame
        void addCardToGame(BingoCard*);                                 // function to add BingoCard to BingoGame (via  vector of pointers to the cards)
        friend void Caller::assignCallerToBingoGame(BingoGame*);        // friend function allowing Caller to assign self to callerPtr
        friend void Caller::setCurrentRoundValue();                     // friend function allowing Caller to set currentRoundVal
        int getCurrentRoundValue();                                     // return current round value (which was updated by Caller)
        void playRound();                                               // sets in motion a round, described in greater detail in BingoGame.cpp
        int checkForWin();                                              // returns 1 if any of the associated BingoCards are winners

};


#endif