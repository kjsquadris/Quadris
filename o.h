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
  std::map<int, vector<Coordinate>> states;
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  int numStates = 1;
  int heaviness;
  int width = 2;
  int height = 2;
  std::string type = "oBlock";
public:
  O(Grid* gameGrid, int blockid, int lvl);
  // bool isValidRotate(std::string dir) override;
  void updateStates();
  // void rotate(std::string dir) override;
  // void rotateCW() override;
  // void rotateCCW() override;
};

#endif
