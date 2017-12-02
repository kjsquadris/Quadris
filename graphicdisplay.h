#ifndef GRAPHICDISPLAY_H__
#define GRAPHICDISPLAY_H__
#include <string>
#include "window.h"
#include "block.h"
#include "score.h"
//#include "subject.h"

class GraphicDisplay {
  const int cellSize = 40; //each cell dimension
  const int gridHeight = 1280; //height of entire window
  const int gridWidth = 880; //width of entire window
  const int subHeight = 720; //height of just quadris grid
  const int subWidth = 440; //width of just quadris grid
  string HiScore;
  string curScore;
  string lvl;
  XWindow xw;

public:
  GraphicDisplay(Board *b);

  void notify(Subject &fromCell) override;

  //setters
  void setNext(string s);
  void setHiScore(int hs);
  void setcurScore(int sc);
  void setlvl(int lv);

  //drawing the fields
  void drawNext();
  void drawScore();
  void drawlvl();
};


#endif
