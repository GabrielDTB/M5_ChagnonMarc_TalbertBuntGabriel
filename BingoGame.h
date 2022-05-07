#ifndef BINGOGAME_H
#define BINGOGAME_H
#include <vector>
#include "BingoCard.h"
#include "Caller.h"

class BingoCard;

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
        void addCardToGame(BingoCard*);                                           // function to add BingoCard to BingoGame (via  vector of pointers to the cards)
        //void assignCallerToBingoGame(Caller*);                        // function called in Caller construction to assign Caller to callerPtr
        friend void Caller::assignCallerToBingoGame();                  // friend function that sets callerPtr when Caller is initialized
        friend void Caller::setCurrentRoundValue();                     // friend function allowing Caller to set currentRoundVal
        int getCurrentRoundValue();                                     // return current round value (which was updated by Caller)
        void playRound();                                               // sets in motion a round, described in greater detail in BingoGame.cpp
        int checkForWin();                                              // returns 1 if any of the associated BingoCards are winners

};


#endif