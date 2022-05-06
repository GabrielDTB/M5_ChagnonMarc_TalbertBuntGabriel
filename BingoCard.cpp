//
// Created by gabrieltb on 5/5/22.
//

#include "BingoCard.h"
#include <cstdlib>

BingoCard::BingoCard()
{
    short keyBuffer[5];
    // Generate and assign all the bingo keys
    for (short column = 0; column < 5; column++)
    {
        // Generate a full column of keys
        for (short &key: keyBuffer)
        {
            key = (rand() % 15 + 1) + (15 * column);
        }
        // Insert a column of keys in ascending numerical order
        for (short row = 0; row < 5; row++)
        {
            short smallest = 76;
            short smallestIndex;
            // Find the smallest key remaining in the buffer
            for (short index = 0; index < 5; index++)
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

BingoCard::BingoCard(const short cardArray[5][5])
{
    for (short column = 0; column < 5; column++)
    {
        for (short row = 0; row < 5; row++)
        {
            cardKeys[column][row] = cardArray[column][row];
        }
    }
}