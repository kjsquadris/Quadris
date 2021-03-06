#include <vector>
#include <memory>
#include <string>
#include "board.h"

using namespace std;

// FOR CREATION OF BOARD
// construct when no seed
Board::Board(string scriptfile, int level) :
g{make_unique<Grid>()}, s{make_unique<Score>()},
level{level}, scriptfile{scriptfile} {
  isSeedAvailable = false;
  init(); // create the board's level and blocks
}

// constructor for when there's a seed
Board::Board(unsigned int seed, string scriptfile, int level) :
g{make_unique<Grid>()}, s{make_unique<Score>()},
seed{seed}, level{level}, scriptfile{scriptfile} {
  isSeedAvailable = true;
  init(); // create the board's level and blocks
}

// create the level and create the current and next blocks
void Board::init() {
  if (level == 0) { // create level 0
    l = make_unique<L0>();
  } else if (level == 1) { // create level 1
    if (isSeedAvailable()) {
      l = make_unique<L1>(seed);
    } else {
      l = make_unique<L1>();
    }
  } else if (level == 2) { // create level 2
    if (isSeedAvailable()) {
      l = make_unique<L2>(seed);
    } else {
      l = make_unique<L2>();
    }
  } else if (level == 3) { // create level 3
    if (isSeedAvailable()) {
      l = make_unique<L3>(seed, false);
    } else {
      l = make_unique<L3>(false);
    }
  } else { // create level 4
    lvlfourBlocks = 0;
    if (isSeedAvailable()) {
      l = make_unique<L3>(seed, true);
    } else {
      l = make_unique<L3>(true);
    }
  }

  bmap[numBlocks] = move(l->createBlocks(g.get(), numBlocks)); // add the current block into the map of numBlocks
  numBlocks++;
  nextBlock = move(l->createBlocks(g.get(), numBlocks)); // make the next block
}

// GETTERS
// retrieve the current level
int Board::getLevel() {
  return level;
}

// retrieve the Grid*
Grid* Board::getGrid() {
  return g->get();
}

// retrieve the type of the next block
string Board::getNextBlock() {
  return nextBlock->getType();
}

// FOR GAME OVER PURPOSES
// check if it's possible to place a new piece at the starting pos
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

// check if the game is over
bool Board::gameOver() {
  // two cases: place the block down it'll go into the rotate area
  // the area for the starting block is filled
  vector<vector<Cell>> gridcells = g->getCells();
  if (g->getGameOver()) {
    return true;
  }
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

// FOR SCORING PURPOSES
// update the score based on how many rows were cleared
void Board::rowClearScore(int rowsCleared) {
  s->rowClear(rowsCleared, level);
}

// update the score based on the block that was cleared
void Board::blockClearScore(Block b) {
  s->blockClear(b);
}

// retrieve the high score
int Board::getHiScore() {
  return s->getHiScore();
}

// retrieve the current score
int Board::getCurrentScore() {
  return s->getCurrentScore();
}

// MOVES
// shift block to the left (if possible)
void moveLeft() {
  bmap[numBlocks]->shift("left", false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

// shift block to the right (if possible)
void moveRight() {
  bmap[numBlocks]->shift("right", false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

// shift block down (if possible)
void moveDown() {
  bmap[numBlocks]->shift("down", false);
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

// rotate block clockwise (if possible)
void rotateCW() {
  bmap[numBlocks]->rotate("cw");
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

// rotate block counter clockwise (if possible)
void rotateCCW() {
  bmap[numBlocks]->rotate("ccw");
  if (bmap[numBlocks]->getHeaviness() == 1) {
    bmap[numBlocks]->shift["down", false];
  }
}

// move block as far down as possible
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
      return;
    } else {
      g->setGameOver(false);
    }
  }

  if (level == 4) {
    lvlfourBlocks++;
    lvlfourRows += numCleared; //update the #rows cleared in lvl 4
    if ((lvlfourBlocks % 5) == 0) { // if 5 or 10 or 15 ... blocks have been placed
      if (lvlfourRows == 0) {
        // if no rows have been cleared then create a CenterBlock and drop it
        bmap[numBlocks] = move(l->createBlocks(g.get(), numBlocks, "*"));
        numBlocks++; // increase the counter for total number of blocks created
        bmap[numBlocks]->drop();
      } else {
        lvlfourRows = 0;
      }
    }
  }

  // add the old next block to the map and create a new nextBlock
  bmap[numBlocks] = move(nextBlock);
  numBlocks++;
  if (checkStartPos()) {
    g->setGameOver(false);
    nextBlock = move(l->createBlocks(g.get(), numBlocks)); // make the next block
  } else {
    g->setGameOver(true);
  }
}

// replace the current undropped block
void replaceBlock(string s) {
  // replace the block at bmap[numBlocks - 1]
  bmap[numBlocks - 1] = move(l->createBlocks(g.get(), numBlocks, s));
}

void hint() {

}

// CHANGE LEVEL
// increases the level
void levelUp() {
  level += 1;
  init(); // create the new level
}

// decreases the level
void levelDown() {
  level -= 1;
  init(); // create the new level
}
