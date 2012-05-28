/*
 * File: Remove.cpp
 * --------------------------
 * Program for removing double characters.
 */

#include <iostream>
#include <string>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "strlib.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
string removeDoubledLetters(string);

#pragma mark -
#pragma mark Definitions
string removeDoubledLetters(string str)
{
    char one, two;
    int endpoint = str.length();
    string work = str;
    for ( int i=1; i < work.length(); ++i ) 
    {
        one = work[i-1];
        two = work[i];
        if ( one == two && endpoint > i ) 
        {
            for ( int j=i; j < work.length(); ++j ) 
            {
                work[j-1] = work[j];
            }
            endpoint--;
        }
    }
    work.erase(endpoint);
    return work;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    // enter the loop
    string word, remove;
    
    while ( true ) 
    {
        // get the data
        word = getLine("Enter the target word: ");
        if ( word == SENTINEL ) break;
        
        // output the answer
        word = trim(word);
        word = removeDoubledLetters(word);
        cout << "Double characters removed: " << word << endl;
        cout << endl;
    }
    
    return 0;
}
