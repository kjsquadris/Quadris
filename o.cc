#include <vector>
#include "o.h"

using namespace std;

O::O(Grid *gameGrid, int lvl) : g{gameGrid}, level{lvl} {
  Cell* c1 = &(g->getCell(3,0));
  Cell* c2 = &(g->getCell(3,1));
  Cell* c3 = &(g->getCell(4,0));
  Cell* c4 = &(g->getCell(4,1));
  cells.emplace_back(c1);
  cells.emplace_back(c2);
  cells.emplace_back(c3);
  cells.emplace_back(c4);

  set();
  draw();
}

// bool O::isValidRotate(string dir) { return true; }
void updateStates() {}
// void O::rotate(string dir) {}
// void O::rotateCW() {}
//
// void O::rotateCCW() {}
