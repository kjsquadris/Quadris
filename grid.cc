#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include "block.h"
#include "level.h"

using namespace std;

Grid::~Grid(){
  theGrid.clear();
}


void Grid::init(TextDisplay *td, Observer *ob){

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

void setGameOver(bool over) {GameOver = over;}

bool getGameOver() {return GameOver;}

int Grid::rowScore(){//updates score based on rows cleared
  int track = 0;
  for (auto row : theGrid) {  //goes through each row of the grid
    bool empCell = false;
    for (auto cell : row) { //goes through all cells in a row
      if (cell.getBlockType() == "None"){ //checks for cell not occupied by block
        empCell = true;
        break;
      }
    }
    if (empCell == false) ++track; //after going through all cells in a row, if none is None, increase track by 1
  }
  return track;
}

bool Grid::rowFull(int r) {
  for (int i = 0; i < 11; ++i) {
    if (theGrid[r][i].getBlockType() == "None") {
      return false;
    }
  }
  return true;
}

void Grid::blockScore(Score *sc, Block *b) {
  if(b->isEmpty() == true) {
    sc->blockClear(b);
  }
}

/*void Grid::setBlockType(int r, int c, Block b){
  Grid[r][c].setBlockType(b.getType());
}

void Grid::unsetBlockType(int r, int c){
  Grid[r][c].unsetBlockType();
}*/
