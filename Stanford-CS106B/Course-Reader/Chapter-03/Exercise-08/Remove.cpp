/*
 * File: Remove.cpp
 * --------------------------
 * Program for generating acronyms. 
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "strlib.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
void remove_characters(string &target, string remove);
bool contains(string str, char c);

#pragma mark -
#pragma mark Definitions
/*
 * Function: remove_characters(string &target, string remove);
 * ----------------------------------------------------------- 
 * Remove all the characters in "remove" from "target", and 
 * perform the removal in-place.
 */
void remove_characters(string &target, string remove)
{
    int endpoint = target.length();
    for ( int i=0; i < target.length(); ++i )
    {
        while ( contains(remove, target[i]) && endpoint > i )
        {
            for ( int j=i+1; j < target.length(); ++j ) 
            {
                target[j-1] = target[j];
            }
            endpoint--;
        }
    }
    target.erase(endpoint);
}

/*
 * Function: bool contains(string str, char c);
 * -------------------------------------------- 
 * Return true if char 'c' is in the string 'str'.
 */
bool contains(string str, char c)
{
    for ( int i=0; i < str.length(); ++i ) 
    {
        if ( str[i] == c ) return true;
    }
    return false;
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
        remove_characters(word, remove);
        cout << "Removed characters: " << word << endl;
        cout << endl;
    }
    
    return 0;
}
