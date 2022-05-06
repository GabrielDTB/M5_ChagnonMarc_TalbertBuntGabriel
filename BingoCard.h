//
// Created by gabrieltb on 5/5/22.
//

#ifndef BINGOCARD_H
#define BINGOCARD_H

class BingoCard
{
    private:
      short cardKeys[5][5]{};
      bool cardValues[5][5] = {{false, false, false, false, false},
                               {false, false, false, false, false},
                               {false, false, true, false, false},
                               {false, false, false, false, false},
                               {false, false, false, false, false}};
      short rowTallies[5] = {0, 0, 0, 0, 0};
      short columnTallies[5] = {0, 0, 0, 0, 0};
      short diagonalTallies[2] = {0, 0}; // Element 0 is the top left diagonal
    public:
      BingoCard();

      explicit BingoCard(const short[5][5]);

      // C++ doesn't really let us return an array from a function.
      // We can return a pointer to the array, but we would have to
      // set the array to static since it would otherwise be local and
      // get de-referenced.
      // I don't really want to do that, so I'm going to do something
      // that is, admittedly, more convoluted, but perfectly functional.
      short searchForValue(short) const;

      void markPosition(short);

      short getClearedLines() const;
};


#endif //BINGOCARD_H
