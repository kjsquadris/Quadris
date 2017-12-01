#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>
#include "coordinate.h"

class Cell : public Subject {
  int row, col; //coordinates of cell in the graphicdisplay
  string blockType; //type of block the cell belongs to

public:
  Cell(int r, int c); //constructor. takes in 2 int to set the coord

  string getBlockType(); //returns the type of block the cell belongs to
  Coordinate getCoordinate(); //return coord struct
  void setBlockType(string b); //sets the blockType field from Block b
  void unsetBlockType(); //unsets the blockType field to None
  bool isOccupied(); //checks if the cell belongs to any Block
  Coordinate getCoord();

};

#endif
