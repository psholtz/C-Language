/*
 * File: Input.cpp
 * ---------------
 * Demonstrates techniques for getting user input. 
 */

#include <iostream>
#include <string>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"

#define SENTINEL -1

//
// Constants 
// 

using namespace std;

#pragma mark -
#pragma mark Declarations
int getInteger(string prompt);

#pragma mark -
#pragma mark Definitions
int getInteger(string prompt)
{
    int value;
    string line;
    while ( true ) {
        cout << prompt;
        getline(cin, line);
        istringstream stream(line); 
        stream >> value >> ws;
        if ( !stream.fail() && stream.eof() ) break;
        cout << "Illegal integer format. Try again." << endl;
    }
    return value; 
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
        
    int number;
    while ( true ) {
        number = getInteger("Enter an integer: "); 
        if ( number == SENTINEL ) break;
        cout << "This was the number: " << number << endl;
    }
    
    return 0;
}