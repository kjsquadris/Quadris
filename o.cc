#include <vector>
#include "o.h"

using namespace std;

O::O(Grid *gameGrid, int blockid, int lvl) : g{gameGrid}, level{lvl} {
  Cell* c1 = &(g->getCell(3,0));
  Cell* c2 = &(g->getCell(3,1));
  Cell* c3 = &(g->getCell(4,0));
  Cell* c4 = &(g->getCell(4,1));
  c1->setID(blockid);
  c2->setID(blockid);
  c3->setID(blockid);
  c4->setID(blockid);
  cells.emplace_back(c1);
  cells.emplace_back(c2);
  cells.emplace_back(c3);
  cells.emplace_back(c4);

  setHeaviness(); // set the heaviness of the block
  set();
}

// bool O::isValidRotate(string dir) { return true; }
void updateStates() {}
// void O::rotate(string dir) {}
// void O::rotateCW() {}
//
// void O::rotateCCW() {}
