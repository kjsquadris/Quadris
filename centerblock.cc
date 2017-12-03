#include <vector>
#include <string>
#include "centerblock.h"

CenterBlock::CenterBlock(Grid* gameGrid, int blockid, int lvl) :
g{gameGrid}, level{lvl} {
  Cell* c = &(g->getCell(3,5));
  c->setID(blockid);
  cells.emplace_back(c);
}

void CenterBlock::updateStates() {}
