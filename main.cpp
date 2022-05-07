#include <iostream>
#include "BingoGame.h"
#include "BingoCard.h"
#include "Caller.h"
using namespace std;


int main() {
    
    cout << "\n generating Bingo Game.";
    BingoGame game1 = BingoGame();
    cout << "\n generating caller.";
    Caller caller1 = Caller(&game1);
    // caller1.generateCurrentRoundValue();

    // create BingoCards
    

    for (int i = 0; i < 10; i++) {
        cout << "\nplaying round " << (i + 1) << ".\n";
        game1.playRound();
        cout << "\ncaller has generated a number:\n";
        cout << game1.getCurrentRoundValue();
    }
    

}
