#ifndef SCORE_H
#define SCORE_H

class TextDisplay;

class Score {
  int currentScore = 0;
  int highScore = 0;
  TextDisplay *td;
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
