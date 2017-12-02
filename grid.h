#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <map>
#include "graphicsdisplay.h"
#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include "block.h"
#include "level.h"

class Grid {
  std::vector<std::vector<Cell>> theGrid; //actual Grid
  TextDisplay *td;
  Observer *ob; //for graphics
  bool GameOver;

public:
  ~Grid(); //destructor

  void setObTxt(TextDisplay *td, Observer *ob);
  void init(); //initialize grid
  std::vector<std::vector<Cells>> getCells(); // return theGrid
  void clearRow(int r); //clears row at r
  void setGameOver(bool over); //set GameOver
  bool getGameOver(); //reutnr GameOver
  bool isrowFull(int r); //checks if a row is full. r is the row number you wanna check

};

#endif
