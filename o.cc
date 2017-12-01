#include <vector>
#include "o.h"

using namespace std;

O::O(Grid *gameGrid, int lvl) : g{gameGrid}, level{lvl} {
  Cell* c1 = &(g->getCell(3,0));
  cells.emplace_back(c1);
  Cell* c2 = &(g->getCell(3,1));
  cells.emplace_back(c2);
  Cell* c3 = &(g->getCell(4,0));
  cells.emplace_back(c3);
  Cell* c4 = &(g->getCell(4,1));
  cells.emplace_back(c4);
  
  type = "oBlock";
  set();
  draw();
}

bool isValidRotate() { return true; }

void O::rotateCW() {}

void O::rotateCCW() {}
