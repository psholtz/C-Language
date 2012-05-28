/*
 * File: Plural.cpp
 * --------------------------
 * Program for creating word plurals.  
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
string makePlural(string str); 

#pragma mark -
#pragma mark Definitions
string makePlural(string str)
{
    // handle special case
    if ( str.length() == 0 ) { return ""; }
    
    char last = str[str.length()-1];
    switch (last) {
            case 's':
            case 'x':
            case 'z':
                return str + "es";
            case 'y':
                return str.substr(0,str.length()-1) + "ies";
    }
    if ( str.length() > 1 ) 
    {
        char second = str[str.length()-2];
        if ( (last == 'h' && second == 'c') ||
             (last == 'h' && second == 's') )
            return str + "es";
    }
    
    return str + "s";
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    // enter the loop
    string word;
    while ( true ) 
    {
        // get the data
        word = getLine("Enter word to pluralize: ");
        if ( word == SENTINEL ) break;
        
        // pluralize the word
        cout << "The plural of '" << word << "' is '" << makePlural(word) << "'" << endl;
        cout << endl;
    }
    
    return 0;
}
