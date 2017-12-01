#ifndef O_H
#define O_H
#include <vector>
#include <string>
#include "block.h"

class Cell;

class O : public Block {
  // std::vector<std::unique_ptr<Cell>> cells;
  Grid *g;
  Coordinate leftRef = {4, 0};
  map<int, vector<Coordinate>> states;
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  std::string type = "oBlock";
public:
  O(Grid*, int);
  // bool isValidRotate(std::string dir) override;
  void updateStates();
  // void rotate(std::string dir) override;
  // void rotateCW() override;
  // void rotateCCW() override;
};

#endif
