#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <map>
#include <memory>
#include <string>
#include "coordinate.h"

class Block {
  // std::vector<std::unique_ptr<Cell>> cells;
  Grid* g;
  Coordinate leftRef = {4, 0};
  std::map<int, vector<Coordinate>> states; // hold the different states a block can have
  std::vector<Cell*> cells;
  int counter = 0;
  int level;
  int currState = 0;
  int numStates;
  int width;
  int height;
  int heavy;
  std::string type;
public:
  // pure virtual functions to be overridden by derived classes
  virtual void init() = 0;
  virtual void updateStates() = 0;
  // virtual void rotateCW() = 0;
  // virtual void rotateCCW() = 0;

  // default methods for all blocks
  virtual ~Block();
  virtual void removeCell(Coordinate c);
  virtual void setHeaviness();
  virtual int getHeaviness();
  virtual int getLevel();
  // virtual std::vector<std::unique_ptr<Cell>> getCells();
  virtual std::vector<Cell*> getBlockCells();
  virtual bool isEmpty();
  virtual std::vector<Coordinate> createCoords();
  virtual bool inBlock(int, int);
  virtual bool isValidShift(std::string dir);  
  virtual bool shift(std::string dir, bool isDrop);
  virtual bool isValidRotate(std::string dir);
  virtual void rotate(std::string dir);
  // virtual void moveLeft();
  // virtual void moveRight();
  // virtual void moveDown(std::string cmd = "down");
  virtual void drop();
  virtual void draw();
  virtual void set(std::string);
  virtual void unset();
  virtual void updateCounter();
  virtual std::string getType();
};

#endif
