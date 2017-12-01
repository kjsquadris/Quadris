#include <vector>
#include <map>
#include <string>
#include "s.h"

using namespace std;

S::S(Grid *gameGrid, int lvl) : g{gameGrid}, level{lvl} {
  // create orginal cells vector
  Cell* c1 = &(g->getCell(3,1));
  Cell* c2 = &(g->getCell(4,0));
  Cell* c3 = &(g->getCell(4,1));
  Cell* c4 = &(g->getCell(3,2));
  cells.emplace_back(c1);
  cells.emplace_back(c2);
  cells.emplace_back(c3);
  cells.emplace_back(c4);

  updateStates(); // create the vector of states

  set();
  draw();
}

void S::updateStates() {
  // create the vector of 2 different states
  // State 0 (original state)
  vector<Coordinate> vec1;
  vec1.emplace_back(Coordinate{leftRef.x, leftRef.y});
  vec1.emplace_back(Coordinate{leftRef.x - 1, leftRef.y + 1});
  vec1.emplace_back(Coordinate{leftRef.x, leftRef.y + 1});
  vec1.emplace_back(Coordinate{leftRef.x - 1, leftRef.y + 2});
  states[0] = vec1;

  // State 1 (CW once from State 0)
  vector<Coordinate> vec2;
  vec2.emplace_back(Coordinate{leftRef.x - 1, leftRef.y});
  vec2.emplace_back(Coordinate{leftRef.x - 2, leftRef.y});
  vec2.emplace_back(Coordinate{leftRef.x - 1, leftRef.y + 1});
  vec2.emplace_back(Coordinate{leftRef.x, leftRef.y + 1});
  states[1] = vec2;
}
