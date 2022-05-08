#include <iostream>
#include <iomanip>
#include "BingoGame.h"
#include "BingoCard.h"
#include "Caller.h"

using namespace std;

void displayBingoCard(BingoCard &);

int main()
{
    // variable definitions
    int numBingoCards;

    cout << "\n generating Bingo Game.";
    BingoGame game1 = BingoGame();
    cout << "\n generating caller.";
    Caller caller1 = Caller(&game1);

    cout << "\nchecking size of vector: " << game1.numCardsInPlay;

    cout
            << "\nThis game will have three players, each with one Bingo card (future versions maybe user will decide how many cards?)";
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
            } else
            {
                cout << NORMAL_CODE;
            }
            cout << " " << left << setw(2) << card.cardKeys[column][row];
        }
        cout << endl;
    }
}