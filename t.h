#ifndef T_H
#define T_H
#include <vector>
#include <string>
#include <map>
#include "block.h"

class Cell;

class T : public Block {
  Grid *g;
  Coordinate leftRef = {4, 0};
  map<int, vector<Coordinate>> states;
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 4;
  std::string type = "tBlock";
public:
  T(Grid*, int);
  void updateStates();
};

#endif
