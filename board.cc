#include <vector>
#include <memory>
#include <string>
#include "board.h"

using namespace std;

// construct when no seed
Board::Board(string scriptfile, int level) :
g{make_unique<Grid>()}, s{make_unique<Score>()},
level{level}, scriptfile{scriptfile} {
  isSeedAvailable = false;
  init();
}

// constructor for when there's a seed
Board::Board(unsigned int seed, string scriptfile, int level) :
g{make_unique<Grid>()}, s{make_unique<Score>()},
seed{seed}, level{level}, scriptfile{scriptfile} {
  isSeedAvailable = true;
  init();
}

// create the level and create the current and next blocks
void Board::init() {
  if (level == 0) {
    l = make_unique<L0>();
  } else if (level == 1) {
    l = make_unique<L1>();
  } else if (level == 2) {
    l = make_unique<L2>();
  } else if (level == 3) {
    l = make_unique<L3>();
  } else {
    l = make_unique<L3>();
  }
  bmap[numBlocks] = std::move(l->createBlocks(numBlocks)); // add the current block into the map of numBlocks
  numBlocks++;
  if (checkStartPos()) {
    g->setGameOver(false);
    nextBlock = std::move(l->createBlocks()); // make the next block
  } else {
    g->setGameOver(true);
  }
}

bool Board::checkStartPos() {
  bool canStart = true;
  vector<vector<Cell>> gridcells = g->getCells();

  // check row 3
  for (int i = 0; i < 4; ++i) {
    if (gridcells[3][i].isOccupied()) {
      canStart = false;
      break;
    }
  }
  if (canStart) {
    // check row 4
    for (int i = 0; i < 3; ++i) {
      if (gridcells[4][i].isOccupied()) {
        canStart = false;
        break;
      }
    }
  }
  return canStart;
}

// update the score based on how many rows were cleared
void Board::rowClearScore(int rowsCleared) {
  s->rowClear(rowsCleared, level);
}

// update the score based on the block that was cleared
void Board::blockClearScore(Block b) {
  s->blockClear(b);
}

bool Board::gameOver() {
  // two cases: place the block down it'll go into the rotate area
  // the area for the starting block is filled
  vector<vector<Cell>> gridcells = g->getCells();
  if (g->getGameOver()) {
    return true;
  }
  // do this check in level before creating the blocks
  if (gridcells[3][0].isOccupied() || gridcells[4][0].isOccupied())
}

void moveLeft() {
  bmap[numBlocks]->shift("left", false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

void moveRight() {
  bmap[numBlocks]->shift("right", false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

void moveDown() {
  bmap[numBlocks]->shift("down", false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

void rotateCW() {
  bmap[numBlocks]->rotate("cw");
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

void rotateCCW() {
  bmap[numBlocks]->rotate("ccw");
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

void drop() {
  bmap[numBlocks]->drop(); // go as far as it can (doesn't set cells until check for any cleared rows)
  int numRows = bmap[numBlocks]->height; // number of potential full rows
  int botRow = bmap[numBlocks]->leftRef.row; // the bottom row of the block
  int blockID;
  int numCleared = 0;
  vector<vector<Cell>> gridcells = g->getCells();

  // use left reference point and height to determine which rows it got put in
  // then it deletes any full rows
  for (int i = 0; i < numRows; ++i) {
    if (g->isRowFull(botRow - i)) {
      // go through all cells in the row that's full
      // and detach them from the blocks
      for (int j = 0; j < 11; ++j) {
        blockID = gridcells[botRow - i][j].getID(); // get ID of the cell
        Coordinate c = gridcells[botRow - i][j].getCoord(); // get coordinates of the cell to be erased
        bmap[blockID]->removeCell(c); //remove the cell from the block
        if (bmap[blockID].isEmpty()) {
          blockClearScore(*bmap[blockID]);
        }
      }
      g->clearRow(botRow - i); // deletes the row
      numCleared++; // increase the count of rows that are cleared
      botRow++;
    }
  }

  rowClearScore(numCleared); // run function to update Score

  // check if any cells are over the top
  for (int i = 0; i < 11; ++i) {
    if (g->cells[2][i].isOccupied()) {
      g->setGameOver(true);
    } else {
      g->setGameOver(false);
    }
  }
}

void levelUp() {
  level += 1;
  l->setLevel(level);
}

void levelDown() {
  level -= 1;
  l->setLevel(level);
}

// clear the board and reset the current score
void restart() {
  s->restart();

  // go through all the blocks created and unset all cells
  for (int i = 0; i < numBlocks; ++i) {
    bmap[i]->unset();
  }
  bmap.clear(); // erase all blocks from the map
}

void replaceBlock(string s) {

}

void hint() {

}
