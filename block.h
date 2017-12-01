#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <memory>
#include <string>
#include "coordinate.h"

class Block {
  // std::vector<std::unique_ptr<Cell>> cells;
  Grid* g;
  std::vector<Cell*> cells;
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
  virtual int getLevel();
  // virtual std::vector<std::unique_ptr<Cell>> getCells();
  virtual std::vector<Cell*> getCells();
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
