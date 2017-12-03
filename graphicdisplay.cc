#include <string>
#include "cell.h"
#include "grid.h"
#include "graphicsdisplay.h"

using namespace std;

//GraphicDisplay::~GraphicDisplay(){delete xw;}

GraphicDisplay::GraphicDisplay(Board *b) b{b}, xw{gridWidth, gridHeight} {
  xw.fillRectangle(0, 0, gridWidth, gridHeight, Xwindow::White);
}

GraphicDisplay::showDisplay() {
  string temp;

  xw.drawString(1*cellSize, 13*cellSize, "Q U A D R I S", Xwindow::DimGray);

  xw.drawString(4*cellSize, 12*cellSize, "Level:", Xwindow::DimGray);
  temp = to_string(b->getLevel());
  xw.drawString(4*cellSize, 15*cellSize, temp, Xwindow::DimGray);

  xw.drawString(6*cellSize, 12*cellSize, "Score:", Xwindow::DimGray);
  temp = to_string(b->getCurrentScore());
  xw.drawString(6*cellSize, 15*cellSize, temp, Xwindow::DimGray);

  xw.drawString(8*cellSize, 12*cellSize, "HiScore:", Xwindow::DimGray);
  temp = to_string(b->getHiScore());
  xw.drawString(8*cellSize, 15*cellSize, temp, Xwindow::DimGray);


  for (int i = 0; i < 18; ++i) {
    for (int j = 0; j < 11; ++j) {
      string bType = b->getGrid()->getCells()[i][j].getBlockType();
      if (bType == "J") {
        xw.fillRectangle(i*cellSize, j*cellSize, cellSize, cellSize, Xwindow::Plum);
      } else if (bType == "O") {
        xw.fillRectangle(i*cellSize, j*cellSize, cellSize, cellSize, Xwindow::Salmon);
      } else if (bType == "S") {
        xw.fillRectangle(i*cellSize, j*cellSize, cellSize, cellSize, Xwindow::Khaki);
      } else if (bType == "Z") {
        xw.fillRectangle(i*cellSize, j*cellSize, cellSize, cellSize, Xwindow::PaleGreen);
      } else if (bType == "I") {
        xw.fillRectangle(i*cellSize, j*cellSize, cellSize, cellSize, Xwindow::MediumAquamarine);
      } else if (bType == "L") {
        xw.fillRectangle(i*cellSize, j*cellSize, cellSize, cellSize, Xwindow::LightSkyBlue);
      } else if (bType == "T") {
        xw.fillRectangle(i*cellSize, j*cellSize, cellSize, cellSize, Xwindow::MediumPurple);
      } else { //None
        xw.fillRectangle(i*cellSize, j*cellSize, cellSize, cellSize, Xwindow::White);
      }
    }
  }

  xw.drawString(20*cellSize, 3*cellSize, "Next:", Xwindow::DimGray);


}

/*void GraphicDisplay::notify(Subject &fromCell) {
  string bType = fromCell.getBlockType();
  int r = fromCell.getCoord().row;
  int c = fromCell.getCoord().col;
  if (bType == "J") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::Plum);
    );
  } else if (bType == "O") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::Salmon);
  } else if (bType == "S") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::Khaki);
  } else if (bType == "Z") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::PaleGreen);
  } else if (bType == "I") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::MediumAquamarine);
  } else if (bType == "L") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::LightSkyBlue);
  } else if (bType == "T") {
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::MediumPurple);
  } else { //None
    xw.fillRectangle(r*cellSize, c*cellSize, cellSize, cellSize, Xwindow::White);
  }
}*/

//setters
/*void GraphicDisplay::setNext(string s) {next = s;}

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

}*/
