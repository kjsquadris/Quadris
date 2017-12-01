#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include "block.h"
#include "level.h"

using namespace std;

Grid::~Grid(){
  theGrid.clear();
  delete td;
  delete ob;
  delete sc; //not sure if i need this or delete lvl
  delete lvl;
}

void Grid::setObserver(Observer *ob) {this->ob = ob;}

void Grid::init(){
  int l = lvl->getLevel();
  int s = sc->getCurrentScore();
  int hs = sc->getHiscore();

  td = new TextDisplay(l, s, hs, nullptr); //initialize textdisplay obj

  //set up empty grid
  for (int i = 0; i < 18; ++i) {
    vector <Cell> row;
    for (int j = 0; j < 11; ++j) {
      Cell c{i, j};
      row.emplace_back(c);
    }
    theGrid.emplace_back(row);
  }

  //attach td and ob observers
  for (int r = 0; r < 18; ++r) {
    for (int c = 0; c < 11; ++c) {
      theGrid[r][c].attach(td);
      theGrid[r][c].attach(ob);
    }
  }
}

void Grid::rowScore(){//updates score based on rows cleared
  int track = 0;
  for (auto row : theGrid) {  //goes through each row of the grid
    bool empCell = false;
    for (auto cell : row) { //goes through all cells in a row
      if (cell.getBlockType == "None"){ //checks for cell not occupied by block
        empCell = true;
        break;
      }
    }
    if (empCell = false) ++track; //after going through all cells in a row, if none is None, increase track by 1
  }
  if (track > 0) {
    int l = lvl->getLevel();
    sc->rowClear(track, l);
  }
}

void Grid::blockScore(Block b) {
  if(b.isEmpty() == true) {
    sc->blockClear(b)
  }
}

void Grid::setBlockType(int r, int c, Block b){
  Grid[r][c].setBlockType(b.getType());
}

void Grid::unsetBlockType(int r, int c){
  Grid[r][c].unsetBlockType();
}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
  out << *(g.td) << endl;
  return out;
}
