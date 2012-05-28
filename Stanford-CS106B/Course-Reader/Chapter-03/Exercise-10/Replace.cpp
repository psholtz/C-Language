/*
 * File: Replace.cpp
 * --------------------------
 * Program for doing string and character replacements. 
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "error.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
string replaceAll(string str, char c1, char c2);
string replaceAll(string str, string s1, string s2);

#pragma mark -
#pragma mark Definitions
string replaceAll(string str, char c1, char c2) 
{
    string work = str;
    for ( int i=0; i < work.length(); ++i ) 
    {
        if ( work[i] == c1 ) work[i] = c2;
    }
    return work;
}

string replaceAll(string str, string s1, string s2)
{
    // perform error handling
    if ( s1.length() > str.length() ) 
    {
        error("replaceAll: strings are not correctly sized.");
    }
    
    string work = str; bool good = true; int z = 0;
    for ( int i=0; i < str.length()-s1.length()+1; ++i )
    {
        // look for matches
        good = true;
        for ( int j=0; j < s1.length(); ++j ) 
        {
            if ( str[i+j] != s1[j] ) 
            {
                good = false; 
            }
        }
        
        // found the match
        if ( good ) 
        {
            work = work.substr(0,z) + s2 + str.substr(i+s1.length());
        }
        else 
        {
            z++;
        }
    }

    return work; 
}


#pragma mark -
#pragma mark Main Driver Loop
int main() {

    // enter the loop
    string word, char1, char2;
    
    while ( true ) 
    {
        // get the data
        word = getLine("Enter the target word: ");
        if ( word == SENTINEL ) break;
        char1 = getLine("Enter character to replace: ");
        if ( char1 == SENTINEL ) break;
        char2 = getLine("Enter new character: ");
        if ( char2 == SENTINEL ) break;
                        
        // output the answer
        word = trim(word);
        char1 = trim(char1);
        char2 = trim(char2);
        if ( char1.length() == 1 && char2.length() == 1 )
        {
            word = replaceAll(word, char1[0], char2[0]);
        }
        else 
        {
            word = replaceAll(word, char1, char2);
        }
        cout << "String with replacements: " << word << endl;
        cout << endl;
    }
    
    return 0;
}
