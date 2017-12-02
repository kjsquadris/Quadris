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
}

void setObTxt(TextDisplay *td, Observer *ob) {
  this->ob = ob;
  this->td = td;
}

void Grid::init(TextDisplay *t, Observer *o){
  td = t;
  ob = o;

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

std::vector<std::vector<Cells>> getCells() {return theGrid;}


void clearRow(int r) { //row start at 0 or 1?
  //unattach txtdisplay and graphicdisplay observer at r
  for (int i = 0; i < 11; ++i) {
    theGrid[r][i].unattach();
  }

  theGrid[r].clear(); //clears all the cells in vector position r
  theGrid.erase(theGrid.begin() + r); //erase the vector at r and all elements

  //call movedown method in cells on the vector<vector <Cells>> above r
  for (int i = r - 1; i >= 0; --i) {
    for (int j = 0; j < 11; ++j) {
      theGrid[i][j].moveDown();
    }
  }
  //insert in very top row
  vector<Cells> topRow;
  for (int i = 0; i < 11; ++i) {
    Cell c{0, i};
    topRow.emplace_back(c);
  }
  theGrid.insert(theGrid.begin(), topRow); //insert it at the beginning of vector

  //attach txtdisplay and graphicdisplay observers to very top row
  for (int i = 0; i < 11; ++i) {
    theGrid[0][i].attach(td);
    theGrid[0][i].attach(ob);
  }

}

void setGameOver(bool over) {GameOver = over;}

bool getGameOver() {return GameOver;}

bool Grid::isrowFull(int r) {
  for (int i = 0; i < 11; ++i) {
    if (theGrid[r][i].getBlockType() == "None") {
      return false;
    }
  }
  return true;
}

/*void Grid::setBlockType(int r, int c, Block b){
  Grid[r][c].setBlockType(b.getType());
}

void Grid::unsetBlockType(int r, int c){
  Grid[r][c].unsetBlockType();
}*/
