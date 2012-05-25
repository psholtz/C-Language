/*
 * File: Rosencrantz.cpp
 * --------------------
 * Coin-flipping algorithm. 
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "random.h"

using namespace std;

enum { kHeads, kTails };

#pragma mark -
#pragma mark Function Prototypes
int flip();

#pragma mark -
#pragma mark Function Definitions
int flip()
{
    return randomInteger(0, 1) == 0 ? kHeads : kTails;
}

string label(int value)
{
    return value == kHeads ? "Heads.." : "Tails..";
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    int headCount = 0, tossCount = 0, flipValue;
    
    // main run loop
    while ( headCount < 3 )
    {
        flipValue = flip();
        
        headCount = (flipValue == kHeads) ? (headCount+1) : 0;
        ++tossCount;
        
        cout << label(flipValue) << endl;
    }
    
    // print answers
    cout << "It took " << tossCount << " tosses to get " << headCount << " consective heads." << endl;
    
    return 0;
}