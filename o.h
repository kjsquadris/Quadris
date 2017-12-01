#ifndef O_H
#define O_H
#include <vector>
#include <memory>
#include <string>
#include "block.h"

class Cell;

class O : public Block {
  // std::vector<std::unique_ptr<Cell>> cells;
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  std::string type;
public:
  void init() override;
  bool isValidRotate() override;
  void rotateCW() override;
  void rotateCCW() override;
};

#endif
