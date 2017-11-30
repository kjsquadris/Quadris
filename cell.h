#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <string>
//#include "coordinate.h"

class Cell : public Subject {
  const int row, col; //coordinates of cell in the graphicdisplay
  string blockType = "None"; //type of block the cell belongs to


public:
  Cell(int r, int c); //constructor

  string getBlockType(); //returns the type of block the cell belongs to
  //Coordinate getCoordinate(int r, int c);
  void setBlockType(Block b); //sets the blockType field from Block b
  void unsetBlockType(); //unsets the blockType field to None
  bool isOccupied(); //checks if the cell belongs to any Block

};

#endif
