#include <string>
#include "cell.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

using namespace std;

//constructor
Cell::Cell(int r, int c) : row{r}, col{c}, blockType{"None"} {}

// retrieve the type of block cell belongs to
string Cell::getBlockType() {
  return blockType;
}

// retrieve the coordinate (x,y)
Coordinate Cell::getCoord() {
  Coordinate cd = {row, col};
  return cd;
}

void Cell::setBlockType(string b) {
  blockType = b;
  notifyObservers();
}

void Cell::unsetBlockType() {
  blockType = "None";
  notifyObservers();
}

bool Cell::empty() {
  if (blockType == "None") {
    return false;
  } else {
    return true;
  }
}
