#ifndef CALLER_H
#define CALLER_H

class BingoGame;
class Caller
{
    private:
        BingoGame *bingoGamePtr;
        static const int ARR_SIZE = 75;
        int numsCalledArr [ARR_SIZE];
        int numsCalledCounter;

    public:
        Caller(BingoGame *);                                 // constructor with BingoGame parameter
        ~Caller();                                          // destructor deletes pointer to BingoGame
        void generateCurrentRoundValue();                    // caller generates current round value (between 1,75 inclusive)
        void setCurrentRoundValue();                        // assigns current round value to BingoGame
        void assignCallerToBingoGame();




};


#endif