#include <string>
#include "cell.h"
#include "graphicsdisplay.h"

using namespace std;

//GraphicDisplay::~GraphicDisplay(){delete xw;}

GraphicDisplay::GraphicDisplay(Board *b) HiScore{"0"}, curScore{"0"}, lvl{to_string(b->getLevel())},
xw {gridWidth, gridHeight} {
  xw.fillRectangle(0, 0, gridWidth, gridHeight, Xwindow::White);
}

void GraphicDisplay::notify(Subject &fromCell) {
  string bType = fromCell.getBlockType();
  int r = fromCell.getCoord().row;
  int c = fromCell.getCoord().col;
  if (bType == "jBlock") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::Plum);
    );
  } else if (bType == "oBlock") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::Salmon);
  } else if (bType == "sBlock") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::Khaki);
  } else if (bType == "zBlock") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::PaleGreen);
  } else if (bType == "iBlock") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::MediumAquamarine);
  } else if (bType == "lBlock") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::LightSkyBlue);
  } else if (bType == "tBlock") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::MediumPurple);
  } else { //None
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::White);
  }
}

//setters
void GraphicDisplay::setNext(string s) {next = s;}

void GraphicDisplay::setHiScore(int hs) {
  HiScore = to_string(hs);
}
void GraphicDisplay::setcurScore(int sc){
  curScore = to_string(sc);
}
void GraphicDisplay::setlvl(int lv){
  lvl = to_string(lv);
}

//drawing the fields
void GraphicDisplay::drawNext(){

}

void GraphicDisplay::drawScore(){

}

void GraphicDisplay::drawlvl(){

}
