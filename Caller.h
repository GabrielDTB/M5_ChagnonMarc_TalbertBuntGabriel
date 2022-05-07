#ifndef CALLER_H
#define CALLER_H

class Caller
{
    private:
        BingoGame* bingoGamePtr;
        int numsCalledArr [75];
        int numsCalledCounter;

    public:
        Caller();
        Caller(BingoGame*);
        ~Caller();
        void assignCallerToBingoGame(BingoGame*);
        int generateCurrentRoundValue();
        void setCurrentRoundValue();




};


#endif