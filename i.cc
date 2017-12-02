#include <vector>
#include <map>
#include <string>
#include "i.h"

using namespace std;

I::I(Grid *gameGrid, int blockid, int lvl) : g{gameGrid}, level{lvl} {
  // create orginal cells vector
  Cell* c1 = &(g->getCell(3,0));
  Cell* c2 = &(g->getCell(3,1));
  Cell* c3 = &(g->getCell(3,2));
  Cell* c4 = &(g->getCell(3,3));
  c1->setID(blockid);
  c2->setID(blockid);
  c3->setID(blockid);
  c4->setID(blockid);
  cells.emplace_back(c1);
  cells.emplace_back(c2);
  cells.emplace_back(c3);
  cells.emplace_back(c4);

  updateStates(); // create the vector of states
  setHeaviness(); // set the heaviness of this block
  set();
}

void I::updateStates() {
  // create the vector of 2 different states
  // State 0 (original state)
  vector<Coordinate> vec1;
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 1});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 2});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 3});
  states[0] = vec1;

  // State 1 (CW once from State 0)
  vector<Coordinate> vec2;
  vec2.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 1, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 2, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 3, leftRef.col});
  states[1] = vec2;
}
