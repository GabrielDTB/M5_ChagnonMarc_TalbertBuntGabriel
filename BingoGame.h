#ifndef BINGOGAME_H
#define BINGOGAME_H
#include <vector>
#include "BingoCard.h"

class BingoGame
{
    private:
        int currentRoundVal;
        std::vector<BingoCard> cardsInPlay;
    
    public:
        BingoGame();
        int numCardsInPlay;
        int getCurrentRoundValue();
        void playRound();
        int checkForWin();

};


#endif