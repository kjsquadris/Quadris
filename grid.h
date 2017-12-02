#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <memory>
#include "graphicsdisplay.h"
#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include "block.h"
#include "level.h"

class Grid {
  std::vector<std::vector<Cell>> theGrid; //actual Grid

public:
  ~Grid(); //destructor

  void init(TextDisplay *td, Observer *ob);
  void rowScore(Level *lvl, Score *sc); //updates score based on rows cleared
  void blockScore(Block b); //updates score when block is cleared
  void setBlockType(int r, int c, Block b); //calls cell's setBlockType at {r, c}
  void unsetBlockType(int r, int c); //calls cell's unsetBlockType at {r, c}

  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
