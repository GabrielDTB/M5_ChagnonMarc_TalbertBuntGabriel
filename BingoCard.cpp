//
// Created by gabrieltb on 5/5/22.
//

#include "BingoCard.h"
#include <random>

using namespace std;

/**
 * Constructor that generates random values for the bingo card
 * and assigns itself to the passed in BingoGame.
 * @param b BingoGame to assign itself to
 */
BingoCard::BingoCard(BingoGame *b)
{
    // Set up the random number generator
    random_device rd;
    mt19937 gen(rd());

    // Generate and assign all the bingo keys
    for (unsigned int column = 0; column < 5; column++)
    {
        // Narrows the random numbers generated to the appropriate range for the column
        uniform_int_distribution<> dist((column * 15) + 1, (column * 15) + 15);

        unsigned int keyBuffer[5];

        // Generate a full column of keys
        for (unsigned int row = 0; row < 5; row++)
        {
            unsigned int key;
            bool keyWasDuplicate;

            // Generate a key and validate that it is not a duplicate
            do
            {
                keyWasDuplicate = false;
                // We first assume the key isn't going to be a duplicate, then check later
                key = dist(gen);

                // Checks if the key was a duplicate
                for (unsigned int index = 0; index < row; index++)
                {
                    if (key == keyBuffer[index])
                    {
                        // Loop again if the key was a duplicate
                        keyWasDuplicate = true;
                        break;
                    }
                }
            } while (keyWasDuplicate);

            keyBuffer[row] = key;
        }

        // Insert a column of keys from keyBuffer into cardKeys in ascending numerical order
        for (unsigned int row = 0; row < 5; row++)
        {
            unsigned int smallest = -1; // The biggest number it can hold
            unsigned int smallestIndex;

            // Find the smallest key remaining in the buffer ...
            for (unsigned int index = 0; index < 5; index++)
            {
                if (keyBuffer[index] != 0 & keyBuffer[index] < smallest)
                {
                    smallest = keyBuffer[index];
                    smallestIndex = index;
                }
            }
            // ... then insert it into cardKeys
            cardKeys[column][row] = smallest;

            keyBuffer[smallestIndex] = 0;
        }
    }
    // Finally, assign the middle square as free.
    // Doing it this way produces an uneven
    // distribution in the N column numbers
    // (the middle numbers are cut out more often
    // while the edge numbers can't be cut out)
    // but it doesn't really matter that much.
    cardKeys[2][2] = 0;

    b->addCardToGame(this);
}

/**
 * Constructor that assigns passed in values to the bingo card
 * and assigns the card to a passed in bingo game.
 * @param bGame the bingo game it gets assigned to
 * @param cardArray the array of keys that get put in
 */
BingoCard::BingoCard(BingoGame *bGame, const unsigned int cardArray[5][5])
{
    // Insert all the keys from the input array into cardKeys
    for (unsigned int column = 0; column < 5; column++)
    {
        for (unsigned int row = 0; row < 5; row++)
        {
            cardKeys[column][row] = cardArray[column][row];
        }
    }
    // Ensure the center square is 0
    cardKeys[2][2] = 0;

    bGame->addCardToGame(this);
}

/**
 * Searches whether a key exists in the bingo card keys.
 * Updates the last found key variable if it finds it.
 * @param key the key to search for
 * @return true if it was found, false if not
 */
bool BingoCard::searchForKey(unsigned int key)
{
    // Find the proper column to search for the key
    unsigned int column = (key - 1) / 15;

    // Search for the key
    for (unsigned int row = 0; row < 5; row++)
    {
        if (cardKeys[column][row] == key)
        {
            lastFoundKey[0] = column;
            lastFoundKey[1] = row;
            return true;
        }
    }
    return false;
}

/**
 * Marks the corresponding value for a key if it exists in the list of keys.
 * Basically marks the bingo card square if it matches.
 * @param key the key to search for
 */
void BingoCard::markValue(unsigned int key)
{
    if (searchForKey(key))
    {
        unsigned int column = lastFoundKey[0];
        unsigned int row = lastFoundKey[1];

        // Mark the value
        cardValues[column][row] = true;

        // Update the tallies
        columnTallies[column]++;
        rowTallies[row]++;
        if (column == row)
        {
            diagonalTallies[0]++;
        } else if (column + row == 5)
        {
            diagonalTallies[1]++;
        }
    }
}

/**
 * Totals up the cleared lines from the columns, rows, and diagonals.
 * @return the total number of cleared lines
 */
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