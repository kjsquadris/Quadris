#ifndef L_H
#define L_H
#include <vector>
#include <string>
#include "block.h"

class Cell;

class L : public Block {
  Grid *g;
  Coordinate leftRef = {4, 0};
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  std::string type;
public:
  L(Grid*, int);
  bool isValidRotate() override;
  void rotateCW() override;
  void rotateCCW() override;
};

#endif
