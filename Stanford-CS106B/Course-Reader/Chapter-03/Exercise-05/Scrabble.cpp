/*
 * File: Scrabble.cpp
 * --------------------------
 * Implement a Scrabble scoring algorithm
 */

#include <iostream>
#include <string>
#include <map>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

using namespace std;

static map<char,int> SCORES;

#pragma mark -
#pragma mark Declarations
static void initialize();
int score(char c);

#pragma mark -
#pragma mark Definitions
static void initialize()
{
    // worth 1 point
    SCORES['A'] = 1;
    SCORES['E'] = 1;
    SCORES['I'] = 1;
    SCORES['L'] = 1;
    SCORES['N'] = 1;
    SCORES['O'] = 1;
    SCORES['R'] = 1;
    SCORES['S'] = 1;
    SCORES['T'] = 1;
    SCORES['U'] = 1;
    
    // worth 2 points
    SCORES['D'] = 2;
    SCORES['G'] = 2;
    
    // worth 3 points
    SCORES['B'] = 3;
    SCORES['C'] = 3;
    SCORES['M'] = 3;
    SCORES['P'] = 3;
    
    // worth 4 points
    SCORES['F'] = 4;
    SCORES['H'] = 4;
    SCORES['V'] = 4;
    SCORES['W'] = 4;
    SCORES['Y'] = 4;
    
    // worth 5 points
    SCORES['K'] = 5;

    // worth 8 points
    SCORES['J'] = 8;
    SCORES['X'] = 8;
    
    // worth 10 points
    SCORES['Q'] = 10;
    SCORES['Z'] = 10;
}

int score(string str)
{
    int total = 0;
    for ( int i=0; i < str.length(); ++i ) 
    {
        total += SCORES[(char)str[i]];
    }
    return total;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    // initialize the scores
    initialize();
    
    cout << score("FARM") << endl;  // 9
    cout << score("test") << endl;  // 0
    cout << score("DOG") << endl;   // 5
    
    return 0;
}
