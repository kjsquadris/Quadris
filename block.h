#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <memory>
#include <string>
#include "coordinate.h"

class Block {
  std::vector<std::unique_ptr<Cell>> cells;
  std::unique_ptr<Grid> g; // points to the grid
  int counter = 0;
  int level;
  std::string type;
public:
  // pure virtual functions to be overridden by derived classes
  virtual void init() = 0;
  virtual bool isValidRotate() = 0;
  virtual void rotateCW() = 0;
  virtual void rotateCCW() = 0;

  // default methods for all blocks
  virtual ~Block();
  virtual void setGrid(std::unique_ptr<Grid>);
  virtual int getLevel();
  virtual std::vector<std::unique_ptr<Cell>> getCells();
  virtual bool isEmpty();
  virtual std::vector<Coordinate> createCoords();
  virtual bool inBlock(int, int);
  virtual bool isValidShift(std::string dir);  
  virtual void moveLeft();
  virtual void moveRight();
  virtual void moveDown(std::string cmd = "down");
  virtual void drop();
  virtual void draw();
  virtual void set(std::string);
  virtual void unset();
  virtual void updateCounter();
  virtual std::string getType();
};

#endif
