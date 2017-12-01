#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer.h"



class Subject {
  std::vector<Observer*> observers; //vector of observer pointers (Textdisplay is Observer of 1 Cell)
 public:
  void attach(Observer *o);
  void notifyObservers();
  virtual string getBlockType() = 0;
  virtual Coordinate getCoord() = 0;
};



void Subject::attach(Observer *o) { //pushes an o to a Cell
  observers.emplace_back(o);
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}


#endif
