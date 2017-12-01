#include <vector>
#include <string>
#include <map>
#include "l.h"

using namespace std;

L::L(Grid *gameGrid, int lvl) : g{gameGrid}, level{lvl} {

  // create orginal cells vector
  Cell* c1 = &(g->getCell(3,2));
  Cell* c2 = &(g->getCell(4,0));
  Cell* c3 = &(g->getCell(4,1));
  Cell* c4 = &(g->getCell(4,2));
  cells.emplace_back(c1);
  cells.emplace_back(c2);
  cells.emplace_back(c3);
  cells.emplace_back(c4);

  updateStates(); // create the vector of states

  set();
  draw();
}

void L::updateStates() {
  // create the vector of 4 different states
  // State 0 (original state)
  vector<Coordinate> vec1;
  vec1.emplace_back(Coordinate{leftRef.x, leftRef.y});
  vec1.emplace_back(Coordinate{leftRef.x, leftRef.y + 1});
  vec1.emplace_back(Coordinate{leftRef.x, leftRef.y + 2});
  vec1.emplace_back(Coordinate{leftRef.x - 1, leftRef.y + 2});
  states[0] = vec1;

  // State 1 (CW once from State 0)
  vector<Coordinate> vec2;
  vec2.emplace_back(Coordinate{leftRef.x, leftRef.y});
  vec2.emplace_back(Coordinate{leftRef.x - 1, leftRef.y});
  vec2.emplace_back(Coordinate{leftRef.x - 2, leftRef.y});
  vec2.emplace_back(Coordinate{leftRef.x, leftRef.y + 1});
  states[1] = vec2;

  // State 2 (CW once from State 1)
  vector<Coordinate> vec3;
  vec3.emplace_back(Coordinate{leftRef.x, leftRef.y});
  vec3.emplace_back(Coordinate{leftRef.x - 1, leftRef.y});
  vec3.emplace_back(Coordinate{leftRef.x - 1, leftRef.y + 1});
  vec3.emplace_back(Coordinate{leftRef.x - 1, leftRef.y + 2});
  states[2] = vec3;

  // State 3 (CW once from State 2)
  vector<Coordinate> vec4;
  vec4.emplace_back(Coordinate{leftRef.x, leftRef.y + 1});
  vec4.emplace_back(Coordinate{leftRef.x - 1, leftRef.y + 1});
  vec4.emplace_back(Coordinate{leftRef.x - 2, leftRef.y + 1});
  vec4.emplace_back(Coordinate{leftRef.x - 2, leftRef.y});
  states[3] = vec4;
}

// bool L::isValidRotate(string dir) {
//   int x, y;
//   bool valid = true;
//   int newState;
//   vector<vector<Cell>> gridcells = g->getCells();
//   if ((dir != "cw") && (dir != "ccw")) {
//     return false;
//   } else if (dir == "cw") { // rotate clockwise
//
//     // decide which state to go to
//     if (currState == 3) { // go back to state 0
//       newState = 0;
//     } else { // go forward with states 0->1, 1->2, etc.
//       newState = currState + 1;
//     }
//   } else { // rotate counter clockwise
//
//     // decide which state to go to
//     if (currState == 0) { // go to state 3
//       newState = 3;
//     } else { // go backward with states 1->0, 2->1, etc.
//       newState = currState - 1;
//     }
//   }
//
//   // check if each cell in the next rotation is valid for rot to happen
//   for (int i = 0; i < 4; ++i) {
//     x = states[newState][i].x;
//     y = states[newState][i].y;
//     if ((x < 0) || (x > 10) || (y > 17)) { // check if cell is not on board
//       valid = false;
//       break;
//     } else if (gridCells[x][y].isOccupied()) { // check if cell is occupied
//       if (inBlock(x, y)) { // see if the cell is part of this block
//         continue;
//       } else { // if not part of this block, rotate is invalid
//         valid = false;
//         break;
//       }
//     } else {
//       continue;
//     }
//   }
//   return valid;
// }
//
// void L::rotate(string dir) {
//   int x,y;
//   if (isValidRotate(dir)) {
//     unset(); // unset current blocks
//
//     // decide the state to rotate to
//     if (dir == "cw") { // rotate
//       if (currState == 3) {
//         currState = 0;
//       } else {
//         currState += 1;
//       }
//     } else {
//       if (currState == 0) {
//         currState = 3;
//       } else {
//         currState -= 1;
//       }
//     }
//
//     // new coordinates for block
//     vector<Coordinate> newCoords = states[currState];
//
//     // update the new cells of the
//     for (int i = 0; i < 4; ++i) {
//       x = newCoords[i].x;
//       y = newCoords[i].y;
//       cells[i] = &(g->getCells()[x][y]);
//     }
//
//     set();
//     draw();
//   }
// }
//
// void L::rotateCW() {
//   if (isValidRotate("cw")) {
//     int x,y;
//     // change the state of the block
//     if (currState == 3) {
//       currState = 0;
//     } else {
//       currState += 1;
//     }
//     unset();
//
//     // new coordinates for block
//     vector<Coordinate> newCoords = states[currState];
//     for (int i = 0; i < 4; ++i) {
//       x = newCoords[i].x;
//       y = newCoords[i].y;
//       cells[i] = &(g->getCells()[x][y]);
//     }
//     set();
//     draw();
//   }
// }
//
// void L::rotateCCW() {
//   if (isValidRotate("ccw")) {
//     int x,y;
//     // change the state of the block
//     if (currState == 0) {
//       currState = 3;
//     } else {
//       currState -= 1;
//     }
//     unset();
//
//     // new coordinates for block
//     vector<Coordinate> newCoords = states[currState];
//     for (int i = 0; i < 4; ++i) {
//       x = newCoords[i].x;
//       y = newCoords[i].y;
//       cells[i] = &(g->getCells()[x][y]);
//     }
//     set();
//     draw();
//   }
// }
