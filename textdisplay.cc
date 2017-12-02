#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Board b) { //constructor

  string next = b.getNext();
  int currScore = b.s->getCurrentScore();
  int HiScore = b.s->getHiScore();
  int lvl = b.getLevel();

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
int Textdisplay::getHiScore(){return HiScore;}
int Textdisplay::getCurrScore(){return currScore;}
int Textdisplay::getLevel(){return lvl;}

void Textdisplay::setNextBlock(string s) {next = s;}
void Textdisplay::setHiScore(int hs) {HiScore = hs;}
void Textdisplay::setCurrScore(int sc) {currScore = sc;}
void Textdisplay::setLevel(int l) {lvl = l;}


void Textdisplay::notify(Subject &FromCell) {
  int r = FromCell.getCoord().row;
  int c = FromCell.getCoord().col;

  if (FromCell.getBlockType() == "jBlock") { //J
    theDisplay[r][c] = 'J';
  } else if (FromCell.getBlockType() == "oBlock") { //O
    theDisplay[r][c] = 'O';
  } else if (FromCell.getBlockType() == "tBlock") { //T
    theDisplay[r][c] = 'T';
  } else if (FromCell.getBlockType() == "sBlock") { //S
    theDisplay[r][c] = 'S';
  } else if (FromCell.getBlockType() == "zBlock") { //Z
    theDisplay[r][c] = 'Z';
  } else if (FromCell.getBlockType() == "lBlock") { //L
    theDisplay[r][c] = 'L';
  } else if (FromCell.getBlockType() == "iBlock") { //I
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

  if (td.getNextBlock() == "jBlock") { //prints out next block
    out << 'J' << endl;
    out << 'JJJ' << endl;
  } else if (td.getNextBlock() == "oBlock") {
    out << 'OO' << endl;
    out << 'OO' << endl;
  } else if (td.getNextBlock() == "tBlock") {
    out << 'TTT' << endl;
    out << ' T ' << endl;
  } else if (td.getNextBlock() == "lBlock") {
    out << '  L' << endl;
    out << 'LLL' << endl;
  } else if (td.getNextBlock() == "iBlock") {
    out << 'IIII' << endl;
  } else if (td.getNextBlock() == "sBlock") {
    out << ' SS' << endl;
    out << 'SS' << endl;
  } else if (td.getNextBlock() == "zBlock") {
    out << 'ZZ' << endl;
    out << ' ZZ' << endl;
  }
  return out;
}
