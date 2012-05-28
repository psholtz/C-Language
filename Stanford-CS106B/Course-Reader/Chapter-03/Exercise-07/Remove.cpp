/*
 * File: Remove.cpp
 * --------------------------
 * Program for removing characters.
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
string remove_characters(string target, string remove);

#pragma mark -
#pragma mark Definitions
/*
 * Function: remove_characters(string &target, string remove);
 * ----------------------------------------------------------- 
 * Remove all the characters in "remove" from "target".
 * Return a new string.
 */
string remove_characters(string target, string remove)
{
    bool found = false;
    stringstream buffer;
    
    for ( int i=0; i < target.length(); ++i )
    {
        found = false;
        for ( int j=0; j < remove.length(); ++j ) {
            if ( target[i] == remove[j] ) 
            {
                found = true;
            }
        }
        if ( !found ) {
            buffer << target[i];
        }
    }
    return buffer.str(); 
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
        remove = getLine("Enter the characters to remove: ");
        if ( remove == SENTINEL ) break;
        
        // output the answer
        word = trim(word);
        remove = trim(remove);
        word = remove_characters(word, remove);
        cout << "Removed characters: " << word << endl;
        cout << endl;
    }
    
    return 0;
}
