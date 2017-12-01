#include <vector>
#include "o.h"

using namespace std;

void O::init(Grid *g, int lvl) {
  Cell* c1 = &(g->getCell(3,0));
  cells.emplace_back(c1);
  Cell* c2 = &(g->getCell(3,1));
  cells.emplace_back(c2);
  Cell* c3 = &(g->getCell(4,0));
  cells.emplace_back(c3);
  Cell* c4 = &(g->getCell(4,1));
  cells.emplace_back(c4);
  level = lvl;
  type = "oBlock";
  set();
  draw();
}

bool isValidRotate() { return true; }

void O::rotateCW() {}

void O::rotateCCW() {}
