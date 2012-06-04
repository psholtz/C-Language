/*
 * File: LongestLine.cpp
 * --------------------- 
 * Find the longest line in a file entered by the user.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
void readFile(string filename);

#pragma mark -
#pragma mark Function Definitions
void readFile(string filename)
{
    string longestString = "", tmp = "";
    stringstream buffer;
    ifstream infile;
    infile.open(filename.c_str());
    if ( infile.fail() ) 
    {
        cout << "Could not find file: " << filename << endl;
    }
    else 
    {
        int ch;
        while ( (ch = infile.get()) != EOF ) 
        {
            if ( ch == '\n' ) 
            {
                tmp = buffer.str();
                if ( tmp.length() > longestString.length() ) 
                {
                    longestString = tmp;
                }
                buffer.str(std::string());
            }
            else 
            {
                buffer << (char)ch;
            }
        }
        cout << "The longest string was: " << longestString << endl;
    }
    infile.close();
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    string filename;
    while ( true ) {
        filename = getLine("Enter a filename: ");
        if ( filename == SENTINEL ) break;
        readFile(filename);
        cout << endl;
    }
    
    return 0;
}
