#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <map>
#include "cell.h"
#include "graphicsdisplay.h"
#include "block.h"
#include "level.h"

class Board {
  int level;
  std::unique_ptr<Grid> g; // pointer to the Grid
  std::unique_ptr<Score> s; // pointer to the Score
  std::unique_ptr<Level> l; // pointer to the Level
  std::map<int, std::unique_ptr<Block>> bmap; // pair that keeps track of all the blocks created
  std::unique_ptr<Block> nextBlock; // points to the next block
  unsigned int seed;
  int numBlocks = 0;
  bool isSeedAvailable;
  std::string scriptfile;
public:
  Board();
  void init();
  void rowsCleared();
  bool gameOver();
  void moveLeft();
  void moveRight();
  void moveDown();
  void rotateCW();
  void rotateCCW();
  void drop();
  void levelUp();
  void levelDown();
  void restart();
  void replaceBlock(std::string s);
  void hint();
};


#endif
