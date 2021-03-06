#ifndef S_H
#define S_H
#include <vector>
#include <string>
#include <map>
#include "block.h"

class Cell;

class S : public Block {
  Grid *g;
  Coordinate leftRef = {4, 0};
  std::map<int, vector<Coordinate>> states;
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 2;
  int heaviness;
  int width = 3;
  int height = 2;
  std::string type = "S";
public:
  S(Grid* gameGrid, int blockid, int lvl);
  void updateStates();
};

#endif
