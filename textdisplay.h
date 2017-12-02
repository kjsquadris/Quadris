#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
//#include "observer.h"
//#include "subject.h"
#include "Board.h"

class TextDisplay {

  Board *b;

public:
 TextDisplay(Board *b); //constructor

 /*std::string getNextBlock(); //get the next block that will appear
 int getHiScore(); //get the HiScore
 int getCurrScore(); //get current score
 int getLevel(); //get the current level*/
 //void notify(Subject &fromCell); //receives notification from Cell

 //need setters
 /*void setNextBlock(string s);
 void setHiScore(int hs);
 void setCurrScore(int sc);
 void setLevel(int l);*/

 //draws the board
 void drawBoard();

};


#endif
