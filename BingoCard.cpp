//
// Created by gabrieltb on 5/5/22.
//

#include "BingoCard.h"
#include <cstdlib>

BingoCard::BingoCard()
{
    unsigned int keyBuffer[5];
    // Generate and assign all the bingo keys
    for (unsigned int column = 0; column < 5; column++)
    {
        // Generate a full column of keys
        for (unsigned int &key: keyBuffer)
        {
            key = (rand() % 15 + 1) + (15 * column);
        }
        // Insert a column of keys in ascending numerical order
        for (unsigned int row = 0; row < 5; row++)
        {
            unsigned int smallest = 76;
            unsigned int smallestIndex;
            // Find the smallest key remaining in the buffer
            for (unsigned int index = 0; index < 5; index++)
            {
                if (keyBuffer[index] != 0 & keyBuffer[index] < smallest)
                {
                    smallest = keyBuffer[index];
                    smallestIndex = index;
                }
            }
            cardKeys[column][row] = smallest;
            keyBuffer[smallestIndex] = 0;
        }
    }
    // Finally, assign the middle square as free
    cardKeys[2][2] = 0;
}

BingoCard::BingoCard(const unsigned int cardArray[5][5])
{
    for (unsigned int column = 0; column < 5; column++)
    {
        for (unsigned int row = 0; row < 5; row++)
        {
            cardKeys[column][row] = cardArray[column][row];
        }
    }
}

unsigned int BingoCard::getClearedLines() const
{
    unsigned int clearedLines = 0;
    for (const unsigned int &tally: rowTallies)
    {
        if (tally == 5) clearedLines++;
    }
    for (const unsigned int &tally: columnTallies)
    {
        if (tally == 5) clearedLines++;
    }
    for (const unsigned int &tally: diagonalTallies)
    {
        if (tally == 5) clearedLines++;
    }
    return clearedLines;
}

bool BingoCard::searchForValue(unsigned int value)
{
    unsigned int column = (value - 1) / 15; // 1-15 will give 0, 16-30 will give 1, etc.
    for (unsigned int row = 0; row < 5; row++)
    {
        if (cardKeys[column][row] == value)
        {
            lastFoundValue[0] = column;
            lastFoundValue[1] = row;
            return true;
        }
    }
    return false;
}