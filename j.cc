#include <vector>
#include <map>
#include <string>
#include "j.h"

using namespace std;

J::J(Grid *gameGrid, int blockid, int lvl) : g{gameGrid}, level{lvl} {
  // create orginal cells vector
  Cell* c1 = &(g->getCell(3,0));
  Cell* c2 = &(g->getCell(4,0));
  Cell* c3 = &(g->getCell(4,1));
  Cell* c4 = &(g->getCell(4,2));
  c1->setID(blockid);
  c2->setID(blockid);
  c3->setID(blockid);
  c4->setID(blockid);
  cells.emplace_back(c1);
  cells.emplace_back(c2);
  cells.emplace_back(c3);
  cells.emplace_back(c4);

  updateStates(); // create the vector of states
  setHeaviness(); // set the heaviness of the block
  set();
}

void J::updateStates() {
  // create the vector of 4 different states
  // State 0 (original state)
  vector<Coordinate> vec1;
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec1.emplace_back(Coordinate{leftRef.row - 1, leftRef.col});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 1});
  vec1.emplace_back(Coordinate{leftRef.row, leftRef.col + 2});
  states[0] = vec1;

  // State 1 (CW once from State 0)
  vector<Coordinate> vec2;
  vec2.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 1, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 2, leftRef.col});
  vec2.emplace_back(Coordinate{leftRef.row - 2, leftRef.col + 1});
  states[1] = vec2;

  // State 2 (CW once from State 1)
  vector<Coordinate> vec3;
  vec3.emplace_back(Coordinate{leftRef.row - 1, leftRef.col});
  vec3.emplace_back(Coordinate{leftRef.row - 1, leftRef.col + 1});
  vec3.emplace_back(Coordinate{leftRef.row - 1, leftRef.col + 2});
  vec3.emplace_back(Coordinate{leftRef.row, leftRef.col + 2});
  states[2] = vec3;

  // State 3 (CW once from State 2)
  vector<Coordinate> vec4;
  vec4.emplace_back(Coordinate{leftRef.row, leftRef.col});
  vec4.emplace_back(Coordinate{leftRef.row, leftRef.col + 1});
  vec4.emplace_back(Coordinate{leftRef.row - 1, leftRef.col + 1});
  vec4.emplace_back(Coordinate{leftRef.row - 2, leftRef.col + 1});
  states[3] = vec4;
}
