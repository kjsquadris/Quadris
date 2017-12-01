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

 void updateNextBlock(string s); //update the next field. s is the string in one of the Block objects
 string getNextBlock(); //get the next block that will appear
 void updateHiScore(int hs); //update HiScore field. hs is new HiScore from Score object
 int getHiScore(); //get the HiScore
 void updateCurrScore(int sc); //update score field. sc is score from Score object
 int getCurrScore(); //get current score
 void updateCurrLevel(int lv); //update level field. lv is level from Level object
 int getLevel(); //get the current level
 void notify(Subject &fromCell); //receives notification from Cell

 friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

};

#endif
