#ifndef SCORE_H
#define SCORE_H

class Score {
  int currentScore = 0;
  int highScore = 0;
public:
  int blockClear(Block);
  int rowClear(int, int);
  void updateScore(int);
  void restart();
  void reset();
  int getCurrentScore();
  int getHiScore();
};

#endif
