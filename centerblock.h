#ifndef CENTERBLOCK_H
#define CENTERBLOCK_H
#include <vector>
#include <string>
#include "block.h"

class Cell;

class CenterBlock : public Block {
  Grid* g;
  Coordinate leftRef = {3, 5};
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  std::string type = "*";
public:
  CenterBlock(Grid* gameGrid, int blockid, int lvl);
  void updateStates();
};

#endif
