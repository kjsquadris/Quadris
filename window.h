#ifndef WINDOW_H
#define WINDOW_H
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {

public:
  Xwindow(int width=500, int height=500);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.
  Xwindow(const Xwindow&) = delete;
  Xwindow &operator=(const Xwindow&) = delete;

  enum {White=0, DimGray, Plum, Salmon, Khaki, PaleGreen, MediumAquamarine, LightSkyBlue, SandyBrown,
    MediumPurple}; // Available colours.

  // Draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=DimGray);

  // Draws a string
  void drawString(int x, int y, std::string msg, int colour=DimGray);
};


#endif
