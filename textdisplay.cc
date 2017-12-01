#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(string next, Score sc, Level lv) next{nullptr} { //constructor
  this->sc = make_unique<Score>(sc);
  this->lv = make_unique<Level>(lv);
  int i, j;
  for (i = 0; i < 18; ++i) {
    vector <char> row;
    for (j = 0; j < 11; ++j) {
      char cell = ' ';
      row.emplace_back(cell);
    }
    theDisplay.emplace_back(row);
  }
}

string Textdisplay::getNextBlock(){return next;}
int Textdisplay::getHiScore(){return sc.getHiScore();}
int Textdisplay::getCurrScore(){return sc.getCurrentScore();}
int Textdisplay::getLevel(){return lv.getLevel();}


void Textdisplay::notify(Subject &FromCell) {
  int r = FromCell.getCoordinate().row;
  int c = FromCell.getCoordinate().col;

  if (FromCell.getBlockType() == "JBlock") { //J
    theDisplay[r][c] = 'J';
  } else if (FromCell.getBlockType() == "OBlock") { //O
    theDisplay[r][c] = 'O';
  } else if (FromCell.getBlockType() == "TBlock") { //T
    theDisplay[r][c] = 'T';
  } else if (FromCell.getBlockType() == "SBlock") { //S
    theDisplay[r][c] = 'S';
  } else if (FromCell.getBlockType() == "ZBlock") { //Z
    theDisplay[r][c] = 'Z';
  } else if (FromCell.getBlockType() == "LBlock") { //L
    theDisplay[r][c] = 'L';
  } else if (FromCell.getBlockType() == "IBlock") { //I
    theDisplay[r][c] = 'I';
  } else { //None
    theDisplay[r][c] = ' ';
  }
}


ostream &operator<<(std::ostream &out, const TextDisplay &td){
  out << "Level:" << "   " << td.getLevel() << endl; //current level
  out << "Score:" << "   " << td.getCurrScore() << endl; //current game's score
  out << "HiScore:" << "   " << td.getHiScore() << endl; //Hiscore

  for (int i = 0; i < 11; ++i) { //top border
    out << _ << endl;
  }

  for (int r = 0; r < 18; ++r) { //print out actual board
    if (r != 0) {
      out << endl;
    }
    for (int c = 0; c < 11; ++c) {
      out << td.theDisplay[r][c];
    }
  }

  for (int i = 0; i < 11; ++i) { //bottom border
    out << _ << endl;
  }

  out << "Next:" << endl;

  if (td.getNextBlock() == "JBlock") { //prints out next block
    out << 'J' << endl;
    out << 'JJJ' << endl;
  } else if (td.getNextBlock() == "OBlock") {
    out << 'OO' << endl;
    out << 'OO' << endl;
  } else if (td.getNextBlock() == "TBlock") {
    out << 'TTT' << endl;
    out << ' T ' << endl;
  } else if (td.getNextBlock() == "LBlock") {
    out << '  L' << endl;
    out << 'LLL' << endl;
  } else if (td.getNextBlock() == "IBlock") {
    out << 'IIII' << endl;
  } else if (td.getNextBlock() == "SBlock") {
    out << ' SS' << endl;
    out << 'SS' << endl;
  } else if (td.getNextBlock() == "ZBlock") {
    out << 'ZZ' << endl;
    out << ' ZZ' << endl;
  }
  return out;
}
