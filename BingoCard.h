//
// Created by gabrieltb on 5/5/22.
//

#ifndef BINGOCARD_H
#define BINGOCARD_H

class BingoCard
{
    private:
      unsigned int cardKeys[5][5]{};
      bool cardValues[5][5] = {{false, false, false, false, false},
                               {false, false, false, false, false},
                               {false, false, true,  false, false},
                               {false, false, false, false, false},
                               {false, false, false, false, false}};
      unsigned int rowTallies[5] = {0, 0, 1, 0, 0};
      unsigned int columnTallies[5] = {0, 0, 1, 0, 0};
      unsigned int diagonalTallies[2] = {1, 1}; // Element 0 is the top left diagonal

      static unsigned int lastFoundValue[2];

      bool searchForValue(unsigned int);

    public:
      BingoCard();

      explicit BingoCard(const unsigned int[5][5]);

      void markPosition(unsigned int);

      unsigned int getClearedLines() const;
};


#endif //BINGOCARD_H
