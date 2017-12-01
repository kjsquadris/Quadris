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
    c.x = cells[i]->x;
    c.y = cells[i]->y;
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
      int x = coords[i].row;
      int y = coords[i].col;
      if (dir == "left") {
        x -= 1;
      } else if (dir == "right") {
        x += 1;
      } else if (dir == "down") {
        y += 1;
      }

      if ((x < 0) || (x > 10) || (y > 17)) { // check if cell is not on board
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

// move the block to the left
void Block::moveLeft() {
  if (isValidShift("left")) {
    unset(); // unset the current cells of the block

    // reassign the cells of the block
    // vector<vector<Cell>> gridcells = g->getCells(); // holds the grid's cells

    // move to the left
    for (int i = 0; i < 4; ++i) {
      int x = cells[i]->x - 1;
      int y = cells[i]->y;
      // cells[i].reset(new Cell(gridcells[x][y]));
      cells[i] = &(g->getCells()[x][y]);
    }
    leftRef.x -= 1; //move the coords of the left reference one to the left
    set(type);

    draw();
  }
}

// move the block to the right
void Block::moveRight() {
  if (isValidShift("right")) {
    unset();

    // reassign the cells of the block
    // vector<vector<Cell>> gridcells = g->getCells(); // holds the grid's cells

    // move to the right
    for (int i = 0; i < 4; ++i) {
      int x = cells[i]->x + 1;
      int y = cells[i]->y;
      // cells[i].reset(new Cell(gridcells[x][y]));
      cells[i] = &(g->getCells()[x][y]);
    }
    leftRef.x += 1; //move the coords of the left reference one to the right
    set(type);

    draw();
  }
}

// move the block down
bool Block::moveDown(string cmd) {
  if (isValidShift("down")) {
    unset();

    // reassign the cells of the block
    // vector<vector<Cell>> gridcells = g->getCells(); // holds the grid's cells

    // move down
    for (int i = 0; i < 4; ++i) {
      int x = cells[i]->x;
      int y = cells[i]->y + 1;
      // cells[i].reset(new Cell(gridcells[x][y]));
      cells[i] = &(g->getCells()[x][y]);
    }
    leftRef.y += 1; //move the coords of the left reference down by one
    set(type);

    // draw right away if it's just a down move
    if (cmd == "down") {
      draw();
    } // otherwise don't draw until drop calls draw

    return true;
  } else {
    return false;
  }
}

// move the block as far down as it can go without overtaking another cell
void Block::drop() {
  while (moveDown("drop")) {
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
