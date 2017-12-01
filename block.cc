#include <string>
#include <vector>
#include <memory>
#include "block.h"
#include "cell.h"

using namespace std;

// destructor
Block::~Block() {}

// returns the level the block was created in
int Block::getLevel() {
  return level;
}

// returns the cells of the block
vector<Cell*> Block::getCells() {
  return cells;
}

// checks if the block's cells are all cleared
bool Block::isEmpty() {
  if (cells.empty()) return true;
  return false;
}

// create a vector with all the coordinates of the current cells of the block
vector<Coordinate> Block::createCoords() {
  vector<Coordinate> coords;

  for (int i = 0; i < 4; ++i) {
    Coordinate c;
    c.x = cells[i]->row;
    c.y = cells[i]->col;
    coords.emplace_back(c);
  }
  return coords;
}

// check whether a cell is inside the block
bool Block::inBlock(int x, int y) {
  vector<Coordinate> coords = createCoords(); // hold the coordinates of curr cells
  bool in = false;

  for (int i = 0; i < 4; ++i) {
    if ((coords[i].x == x) && (coords[i].y == y)) {
      in = true;
      break;
    }
  }
  return in;
}

// check if the cell the block is trying to shift into is occupied or not
// (only checks for left, right, down shift)
bool Block::isValidShift(string dir) {
  vector<Coordinate> coords = createCoords(); // hold the coordinates of curr cells
  vector<vector<Cell>> gridcells = g->getCells(); // hold the cells of the grid

  bool valid = true;
  if ((dir != "left") && (dir != "right") && (dir != "down")) {
    return false;
  } else {
    for (int i = 0; i < 4; ++i) {
      // find coordinates of the new potential cell of the block
      int x = coords[i].x;
      int y = coords[i].y;
      if (dir == "left") {
        y -= 1;
      } else if (dir == "right") {
        y += 1;
      } else if (dir == "down") {
        x += 1;
      }

      if ((y < 0) || (y > 10) || (x > 17)) { // check if cell is not on board
        valid = false;
        break;
      } else if (gridcells[x][y].isOccupied()) { // check if cell is occupied
        if (inBlock(x,y)) { // check if occupied cell is part of the same block
          continue;
        } else { // if not then invalid move
          valid = false;
          break;
        }
      } else { // unoccupied
        continue;
      }
    }
  }
  return valid;
}

// shift the block (returns true/false for drop)
bool Block::shift(string dir) {
  int x,y;
  if (isValidShift(dir)) {
    for (int i = 0; i < 4; ++i) {
      if (dir == "left") {
        x = cells[i]->row;
        y = cells[i]->col - 1;
      } else if (dir == "right") {
        x = cells[i]->row;
        y = cells[i]->col + 1;
      } else {
        x = cells[i]->row + 1;
        y = cells[i]->col;
      }
    }
    cells[i] = &(g->getCells()[x][y]);

    // update bottom left reference point
    // left shift - move the coords of the left reference one to the left
    if (dir == "left") leftRef.y -= 1;
    // right shift - move the coords of the left reference one to the right
    if (dir == "right") leftRef.y += 1;
    // down shift - move the coords of the left reference down by one
    if (dir == "down") leftRef.x += 1;

    set(); // set the new cells
    if (dir != "drop") draw(); // draw the new cells
    updateStates();
    return true;
  } else {
    return false;
  }
}

// check if it's possible to rotate
bool Block::isValidRotate(string dir) {
  int x, y;
  bool valid = true;
  int newState;
  vector<vector<Cell>> gridcells = g->getCells();

  if ((dir != "cw") && (dir != "ccw")) { //invalid direction
    return false;
  } else {
    if (dir == "cw") { // rotate clockwise

      // decide which state to go to
      if (currState == numStates - 1) { // go back to first state
        newState = 0;
      } else { // go forward with states 0->1, 1->2, etc.
        newState = currState + 1;
      }
    } else { // rotate counter clockwise

      // decide which state to go to
      if (currState == 0) { // go to final state
        newState = numStates - 1;
      } else { // go backward with states 1->0, 2->1, etc.
        newState = currState - 1;
      }
    }
  }

  // check if each cell in the next rotation is valid for rot to happen
  for (int i = 0; i < 4; ++i) {
    x = states[newState][i].x;
    y = states[newState][i].y;
    if ((y < 0) || (y > 10) || (x > 17)) { // check if cell is not on board
      valid = false;
      break;
    } else if (gridCells[x][y].isOccupied()) { // check if cell is occupied
      if (inBlock(x, y)) { // see if the cell is part of this block
        continue;
      } else { // if not part of this block, rotate is invalid
        valid = false;
        break;
      }
    } else {
      continue;
    }
  }
  return valid;
}

void Block::rotate(string dir) {
  int x,y;
  if (isValidRotate(dir)) {
    unset(); // unset current blocks

    // decide the state to rotate to
    if (dir == "cw") { // rotate clockwise
      if (currState == numStates - 1) {
        currState = 0;
      } else {
        currState += 1;
      }
    } else { // rotate counter clockwise
      if (currState == 0) {
        currState = numStates - 1;
      } else {
        currState -= 1;
      }
    }

    // new coordinates for block
    vector<Coordinate> newCoords = states[currState];

    // update the new cells of the block
    for (int i = 0; i < 4; ++i) {
      x = newCoords[i].x;
      y = newCoords[i].y;
      cells[i] = &(g->getCells()[x][y]);
    }

    set(); // set the new blocks
    draw();
  }
}

// // move the block to the left
// void Block::moveLeft() {
//   if (isValidShift("left")) {
//     unset(); // unset the current cells of the block
//
//     // reassign the cells of the block
//     // vector<vector<Cell>> gridcells = g->getCells(); // holds the grid's cells
//
//     // move to the left
//     for (int i = 0; i < 4; ++i) {
//       int x = cells[i]->x - 1;
//       int y = cells[i]->y;
//       // cells[i].reset(new Cell(gridcells[x][y]));
//       cells[i] = &(g->getCells()[x][y]);
//     }
//     leftRef.x -= 1; //move the coords of the left reference one to the left
//     set();
//
//     draw();
//   }
// }
//
// // move the block to the right
// void Block::moveRight() {
//   if (isValidShift("right")) {
//     unset();
//
//     // reassign the cells of the block
//     // vector<vector<Cell>> gridcells = g->getCells(); // holds the grid's cells
//
//     // move to the right
//     for (int i = 0; i < 4; ++i) {
//       int x = cells[i]->x + 1;
//       int y = cells[i]->y;
//       // cells[i].reset(new Cell(gridcells[x][y]));
//       cells[i] = &(g->getCells()[x][y]);
//     }
//     leftRef.x += 1; //move the coords of the left reference one to the right
//     set();
//
//     draw();
//   }
// }
//
// // move the block down
// bool Block::moveDown(string cmd) {
//   if (isValidShift("down")) {
//     unset();
//
//     // reassign the cells of the block
//     // vector<vector<Cell>> gridcells = g->getCells(); // holds the grid's cells
//
//     // move down
//     for (int i = 0; i < 4; ++i) {
//       int x = cells[i]->x;
//       int y = cells[i]->y + 1;
//       // cells[i].reset(new Cell(gridcells[x][y]));
//       cells[i] = &(g->getCells()[x][y]);
//     }
//
//     set();
//
//     // draw right away if it's just a down move
//     if (cmd == "down") {
//       draw();
//     } // otherwise don't draw until drop calls draw
//
//     return true;
//   } else {
//     return false;
//   }
// }

// move the block as far down as it can go without overtaking another cell
void Block::drop() {
  while (shift("drop")) { // continue shifting down until it's not possible
    continue;
  }
  draw();
}

// notify the cells that they've moved
void Block::draw() {
  for (int i = 0; i < 4; ++i) {
    cells[i]->draw();
  }
}

// set the cells of block
void Block::set() {
  for (int i = 0; i < 4; ++i) {
    cells[i]->setBlockType(type);
  }
}

// unset the current cells of the block
void Block::unset() {
  for (int i = 0; i < 4; ++i) {
    cells[i]->unsetBlockType();
  }
}

void Block::updateCounter() {
  counter++;
}

string Block::getString() {
  return type;
}
