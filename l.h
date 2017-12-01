#ifndef L_H
#define L_H
#include <vector>
#include <string>
#include <map>
#include "block.h"

class Cell;

class L : public Block {
  Grid *g;
  Coordinate leftRef = {4, 0};
  map<int, vector<Coordinate>> states;
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 4;
  std::string type = "lBlock";
public:
  L(Grid*, int);
  void updateStates();
  // bool isValidRotate(std::string dir) override;
  // void rotate(std::string dir) override;
  // void rotateCW() override;
  // void rotateCCW() override;
};

#endif
