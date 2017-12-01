#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"

class TextDisplay: public Observer{
  std::vector<std::vector<char>> theDisplay;
  int level, score, HiScore,
  string next;

public:
 TextDisplay(int level, int score, int HiScore, string next); //constructor takes in the highscore

 string getNextBlock(); //get the next block that will appear
 int getHiScore(); //get the sc
 int getCurrScore(); //get current score
 int getLevel(); //get the current level
 void notify(Subject &fromCell); //receives notification from Cell

 friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

};

#endif
