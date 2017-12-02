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
  std::map<int, vector<Coordinate>> states;
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  int currState = 0;
  int numStates = 4;
  int heaviness;
  int width = 3;
  int height = 2;
  std::string type = "lBlock";
public:
  L(Grid* gameGrid, int blockid, int lvl);
  void updateStates();
  // bool isValidRotate(std::string dir) override;
  // void rotate(std::string dir) override;
  // void rotateCW() override;
  // void rotateCCW() override;
};

#endif
