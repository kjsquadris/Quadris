#ifndef I_H
#define I_H
#include <vector>
#include <string>
#include <map>
#include "block.h"

class Cell;

class I : public Block {
  Grid *g;
  Coordinate leftRef = {3, 0};
  map<int, vector<Coordinate>> states;
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 2;
  int heaviness;
  int width = 4;
  int height = 1;
  std::string type = "iBlock";
public:
  I(Grid* gameGrid, int blockid, int lvl);
  void updateStates();
};

#endif
