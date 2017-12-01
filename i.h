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
  std::string type = "iBlock";
public:
  I(Grid*, int);
  void updateStates();
};

#endif
