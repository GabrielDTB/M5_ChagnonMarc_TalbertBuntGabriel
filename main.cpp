#include <iostream>
#include "BingoGame.h"
#include "BingoCard.h"
#include "Caller.h"
using namespace std;




int main() {
    // variable definitions
    int numBingoCards;
    
    cout << "\n generating Bingo Game.";
    BingoGame game1 = BingoGame();
    cout << "\n generating caller.";
    Caller caller1 = Caller(&game1);

    cout << "\nchecking size of vector: " << game1.numCardsInPlay;

    cout << "\nThis game will have three players, each with one Bingo card (future versions maybe user will decide how many cards?)";
    BingoCard bcard1(&game1);
    BingoCard bcard2(&game1);
    BingoCard bcard3(&game1);

    // round for practice
    cout << "\nRound 1.";
    game1.playRound();
    cout << game1.checkForWin();
    // print cards each round... also i think we need to "mark" the cards, maybe changing the tiles to 0 like she suggested?

    cout << "\nRound 2.";
    game1.playRound();
    cout << game1.checkForWin();

    /*
    for (int i = 0; i < 10; i++) {
        cout << "\nplaying round " << (i + 1) << ".\n";
        game1.playRound();
        cout << "\ncaller has generated a number:\n";
        cout << game1.getCurrentRoundValue();
    }
    */
    
    return 0;
}
