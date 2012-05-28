/*
 * File: Palindrome.cpp
 * --------------------------
 * Program for calculating sentence-wide palindrome. 
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
bool isSentencePalindrome(string str);

#pragma mark -
#pragma mark Definitions
bool isSentencePalindrome(string str)
{
    // first strip off anything that is not an alpha
    stringstream buffer; int t;
    for ( int i=0; i < str.length(); ++i )
    {
        if ( isalpha(str[i]) )
        {
            t = ( str[i] >= 65 && str[i] <= 90 ) ? str[i] + 32 : str[i]; 
            buffer << char(t);
        }
    }
    
    string test = buffer.str(); bool palindrome = true; 
    for ( int i=0; i < test.length()/2; ++i ) 
    {
        if ( test[i] != test[test.length()-i-1] ) palindrome = false;
    }
    
    return palindrome;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    // enter the loop
    string sentence;
    while ( true ) 
    {
        // get the data
        sentence = getLine("Enter the target word: ");
        if ( sentence == SENTINEL ) break;
        
        // calculate the result
        if ( isSentencePalindrome(sentence) )
        {
            cout << "That sentence is a palindrome." << endl;
        }
        else
        {
            cout << "That sentence is NOT a palindrome." << endl;
        }
        cout << endl;
    }
    
    return 0;
}
