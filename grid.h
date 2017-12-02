#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <map>
#include "graphicsdisplay.h"
#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include "block.h"
#include "level.h"

class Grid {
  std::vector<std::vector<Cell>> theGrid; //actual Grid
  //std::map<int, Block*> bmap;
  bool GameOver;

public:
  ~Grid(); //destructor

  void init(TextDisplay *td, Observer *ob);
  void setGameOver(bool over);
  bool getGameOver();
  int rowScore(); //updates score based on rows cleared
  void blockScore(Score *sc, Block *b); //updates score when block is cleared
  //void setBlockType(int r, int c, Block b); //calls cell's setBlockType at {r, c}
  //void unsetBlockType(int r, int c); //calls cell's unsetBlockType at {r, c}

};

#endif
