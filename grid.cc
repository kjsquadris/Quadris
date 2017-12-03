#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include "block.h"
#include "level.h"

using namespace std;

Grid::~Grid(){
  theGrid.clear();
}

/*void setObTxt(TextDisplay *td, Observer *ob) {
  this->ob = ob;
  this->td = td;
}*/
 Grid::Grid() GameOver{false} {

  //set up empty grid
  for (int i = 0; i < 18; ++i) {
    vector <Cell> row;
    for (int j = 0; j < 11; ++j) {
      Cell c{i, j};
      row.emplace_back(c);
    }
    theGrid.emplace_back(row);
  }
}

std::vector<std::vector<Cells>> getCells() {return theGrid;}


void Grid::clearRow(int r) { //row start at 0 or 1?
  //unattach txtdisplay and graphicdisplay observer at r
  /*for (int i = 0; i < 11; ++i) {
    theGrid[r][i].unattach();
  }*/

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
  /*for (int i = 0; i < 11; ++i) {
    theGrid[0][i].attach(td);
    theGrid[0][i].attach(ob);
  }*/

}

void Grid::setGameOver(bool over) {GameOver = over;}

bool Grid::getGameOver() {return GameOver;}

bool Grid::isrowFull(int r) {
  for (int i = 0; i < 11; ++i) {
    if (theGrid[r][i].getBlockType() == "None") {
      return false;
    }
  }
  return true;
}

ostream &operator<<(std::ostream &out, const Grid &g) {

  for (int i = 0; i < 18; ++i) {
    for (int j = 0; j < 11; ++j) {
      out << *(g[i][j]);
    }
    out << endl;
  }
  return out;
}
