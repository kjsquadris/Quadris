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
  int lvlfourBlocks; // keeps track of the number of blocks dropped in level 4
  int lvlfourRows; // keeps track of # of rows cleared in level 4
  bool isSeedAvailable;
  std::string scriptfile;
public:
  // creation of board
  Board(std::string scriptfile, int level);
  Board(unsigned int seed, std::string scriptfile, int level);
  void init();

  // getters
  int getLevel();
  Grid* getGrid() {};
  std::string getNextBlock() {};

  // for gameover purposes
  bool checkStartPos();
  bool gameOver();
  void restart();

  // for scoring purposes
  void rowClearScore(int rowsCleared);
  void blockClearScore(Block b);
  int getHiScore();
  int getCurrentScore();

  // moves
  void moveLeft();
  void moveRight();
  void moveDown();
  void rotateCW();
  void rotateCCW();
  void drop();
  void replaceBlock(std::string s);
  void hint();

  // change level
  void levelUp();
  void levelDown();
};

#endif
