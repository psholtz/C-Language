/*
 * File: Obenglobish.cpp
 * ---------------------
 * Code for performing Obenglobish translations.
 */

#include <iostream>
#include <string>
#include <algorithm>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
string obenglobish(const string& word);
string obenglobishRecur(const string& word, int index);
bool isVowel(char ch);
int nextConsonant(const string& s);

#pragma mark -
#pragma mark Definitions
/*
 * Function: obenglobish(const string& word);
 * ------------------------------------------
 * Sets up function call to recursive procedure
 * used to calculate the answer.
 */
string obenglobish(const string& word)
{
    // let's move everything into lowercase, for simplicity
    string work = word;
    transform(word.begin(), word.end(), work.begin(), ::tolower);
    
    // perform recursive calculation
    return obenglobishRecur(word,0);
    
}

/*
 * Function: obenglobishRecur(const string& word, int index);
 * ----------------------------------------------------------
 * Recursive function call to determine the obenglobish answer.
 */
string obenglobishRecur(const string& word, int index)
{
    for ( int i=index; i < word.length(); ++i ) 
    {
        if ( isVowel(word[i]) )
        {
            string prev = word.substr(0,i);
            string next = word.substr(i+1);
            int marker = nextConsonant(next);
            
            if ( i < word.length() - 1 || word[i] != 'e' )
            {
                return prev + "ob" + word[i] + obenglobishRecur(next, marker);
            }
        }
    }
        
    return word;
}

/*
 * Function: isVowel(char ch);
 * ---------------------------
 * Return true if ch is a vowel. 
 * Check for uppercase even though we won't use that in the main loop.
 */
bool isVowel(char ch)
{
    switch ( ch ) {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return true;
    }
    return false;
}

/*
 * Function: int nextConsonant(const string& s);
 * --------------------------------------------- 
 * Return index of the first consonant (counting
 * from the left) in the argument string.
 */
int nextConsonant(const string& s)
{   
    int i=0;
    for ( int i=0; i < s.length(); ++i )
    {
        if ( !isVowel(s[i]) ) { return i; }
    }
    return i;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    string word, translation;
    while ( true ) {
        word = getLine("Enter a word: ");
        if ( word == SENTINEL ) break;
        translation = obenglobish(word);
        cout << word << " -> " << translation << endl;
    }
    
    return 0;
}
