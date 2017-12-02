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
  Coordinate getCoord(); //return coord struct
  void set(string b); //sets the blockType field from Block b
  void unset(); //unsets the blockType field to None
  bool isOccupied(); //checks if the cell belongs to any Block
  void moveDown(); //increases row field by 1

};

#endif
