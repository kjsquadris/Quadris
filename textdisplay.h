#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "Board.h"

class TextDisplay: public Observer{
  std::vector<std::vector<char>> theDisplay;
  string next;
  int currScore;
  int HiScore;
  int lvl;

public:
 TextDisplay(Board b); //constructor

 string getNextBlock(); //get the next block that will appear
 int getHiScore(); //get the HiScore
 int getCurrScore(); //get current score
 int getLevel(); //get the current level
 void notify(Subject &fromCell); //receives notification from Cell


 friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

};

#endif
