/*
 * File: Checkerboard.cpp
 * --------------------------
 * Demonstrates how to use the Stanford C++ graphics library 
 * to draw a simple checkerboard.
 */

#include <iostream>
#include <string>

#include "graphics.h"

static const int kWidth = 30;
static const int kHeight = 30;
static const int kRadius = 20;

using namespace std;

int main() {
    // initialization
    initGraphics(8 * kWidth, 8 * kHeight);
    setWindowTitle("Checkerboard");
    
    // draw chessboard
    setColor("GRAY");    
    for ( int i=0; i < kWidth; ++i ) {
        for ( int j=0; j < kHeight; ++j ) {
            if ( (j % 2 == 0 && i % 2 == 1) || (j % 2 == 1 && i % 2 == 0) ) {
                fillRect(i*kWidth, j*kHeight, kWidth, kHeight);
            }
        }
    }
    
    // draw checker pieces

    for ( int i=0; i < kWidth; ++i ) {
        // draw "red" checkers
        for ( int j=0; j < 3; ++j ) {
            if ( (j % 2 == 0 && i % 2 == 1) || (j % 2 == 1 && i % 2 == 0) ) {
                setColor("RED");
                fillOval( i*kWidth + (kWidth-kRadius)/2.0, j*kHeight + (kHeight-kRadius)/2.0, kRadius, kRadius);
                setColor("BLACK");
                drawOval( i*kWidth + (kWidth-kRadius)/2.0, j*kHeight + (kHeight-kRadius)/2.0, kRadius, kRadius);
            }
        }
        
        // draw "black" checkers
        setColor("BLACK");        
        for ( int j=5; j < 8; ++j ) {
            if ( (j % 2 == 0 && i % 2 == 1) || (j % 2 == 1 && i % 2 == 0) ) {
                fillOval( i*kWidth + (kWidth-kRadius)/2.0, j*kHeight + (kHeight-kRadius)/2.0, kRadius, kRadius);
            }
        }
    }
    
   return 0;
}
