#ifndef GRAPHICDISPLAY_H__
#define GRAPHICDISPLAY_H__
#include "window.h"
#include "block.h"
#include "string"
#include "score.h"
#include "subject.h"

class GraphicDisplay: public Observer {
  const int gridSize, winSize;
  XWindow xw;
  string nextBlock;
  int HiScore;
  int curScore;

public:
  GraphicDisplay(int gridSize, int winSize);

  void setNextBlock(Block *b);
  void updateScore(Score s);
  void notify(Subject &fromCell) override;
};


#endif
