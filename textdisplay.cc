#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(Board *b) b{b} {} //constructor

/*string Textdisplay::getNextBlock(){return next;}
int Textdisplay::getHiScore(){return HiScore;}
int Textdisplay::getCurrScore(){return currScore;}
int Textdisplay::getLevel(){return lvl;}

void Textdisplay::setNextBlock(string s) {next = s;}
void Textdisplay::setHiScore(int hs) {HiScore = hs;}
void Textdisplay::setCurrScore(int sc) {currScore = sc;}
void Textdisplay::setLevel(int l) {lvl = l;}*/


/*void Textdisplay::notify(Subject &FromCell) {
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
}*/

void TextDisplay::drawBoard() {
  cout << "Level:" << "   " << b->getLevel() << endl; //current level
  cout << "Score:" << "   " << b->getCurrentScore() << endl; //current game's score
  cout << "HiScore:" << "   " << b->getHiScore() << endl; //HiScore

  for (int i = 0; i < 11; ++i) { //top border
    cout << _ << endl;
  }

  cout << b.getGrid() << endl;

  for (int i = 0; i < 11; ++i) { //bottom border
    out << _ << endl;
  }

  if (b->getNextBlock() == "J") { //prints out next block
    cout << "J" << endl;
    cout << "JJJ" << endl;
  } else if (b->getNextBlock() == "O") {
    cout << "OO" << endl;
    cout << "OO" << endl;
  } else if (b->getNextBlock() == "T") {
    cout << "TTT" << endl;
    cout << " T " << endl;
  } else if (b->getNextBlock() == "L") {
    cout << "  L" << endl;
    cout << "LLL" << endl;
  } else if (b->getNextBlock() == "I") {
    cout << "IIII" << endl;
  } else if (b->getNextBlock() == "S") {
    cout << " SS" << endl;
    cout << "SS" << endl;
  } else if (b->getNextBlock() == "Z") {
    cout << "ZZ" << endl;
    cout << " ZZ" << endl;
  }
}
