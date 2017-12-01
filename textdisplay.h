#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include <memory>
#include "observer.h"

class TextDisplay: public Observer{
  std::vector<std::vector<char>> theDisplay;
  string next;
  unique_ptr<Score> sc;
  unique_ptr<Level> lv;

public:
 TextDisplay(string next, Score sc, Level lv); //constructor takes in level and Score.might have issue with next block

 string getNextBlock(); //get the next block that will appear
 int getHiScore(); //get the HiScore
 int getCurrScore(); //get current score
 int getLevel(); //get the current level
 void notify(Subject &fromCell); //receives notification from Cell
 void updateNext(string b); //update next block

 friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

};

#endif
