#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"

class TextDisplay: public Observer{
  std::vector<std::vector<char>> theDisplay;
  string nextBlock;
  int HiScore;
  int curScore;

public:
 TextDisplay();

 string setNextBlock(Block *b);
 void updateScore(Score s);
 void notify(Subject &fromCell);

 friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);


};

#endif
