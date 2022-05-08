#include <iostream>
#include <iomanip>
#include "BingoCard.h"

using namespace std;

void displayBingoCard(BingoCard &);

int main()
{
    auto *card = new BingoCard;
    printBingoCard(*card);
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