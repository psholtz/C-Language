/*
 * File: Acronym.cpp
 * --------------------------
 * Program for generating acronyms. 
 */

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
string acronym(string);

#pragma mark -
#pragma mark Definitions
string acronym(string str)
{
    stringstream buffer;
    
    bool wordStart = false;
    for ( int i=0; i < str.length(); ++i )
    {
        if ( isalpha(str[i]) && !wordStart )
        {
            buffer << str[i];
            wordStart = true;
        }
        else if ( !isalpha(str[i]) ) 
        {
            wordStart = false;
        }
    }
    
    return buffer.str();
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    // enter the loop
    string word;
    while ( true ) 
    {
        word = getLine("Enter a phrase: ");
        if ( word == SENTINEL ) break;
        cout << acronym(word) << endl; 
    }
    
    return 0;
}
