/*
 * File: Rainbow.cpp
 * --------------------
 * Use the graphics library to draw rainbows.
 */

// Stanford C++ Libraries
#include "graphics.h"

using namespace std;

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    // init the graphics library
    initGraphics(400,300);
    setWindowTitle("Rainbow");

    // draw the blue sky
    setColor("Cyan");
    fillRect(0, 0, 400, 300);
    
    // draw the arcs
    setColor("Red");
    fillArc(-100, 50, 600, 600 , 0, 180);
    setColor("Orange");
    fillArc(-80, 70, 560, 560 , 0, 180);
    setColor("Yellow");
    fillArc(-60, 90, 520, 520 , 0, 180);
    setColor("Green");
    fillArc(-40, 110, 480, 480, 0, 180);
    setColor("Blue");
    fillArc(-20, 130, 440, 440, 0, 180);
    setColor("#ff000ff");
    fillArc(0, 150, 400, 400, 0, 180);
    setColor("Cyan");
    fillArc(20, 170, 360, 360, 0, 180);
            
    repaint();
    
    return 0;
}