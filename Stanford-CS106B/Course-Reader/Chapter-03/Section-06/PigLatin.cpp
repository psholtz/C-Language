/*
 * File: PigLatin.cpp
 * --------------------
 * This program converts lines from English into Pig Latin.
 * This dialect of Pig Latin applies the following rules:
 * 
 *  1. If the word contains no vowels, return the original 
 *     word unchanged.
 *
 *  2. If the word begins with a consonant, extract the set of 
 *     consonants up to the first vowel, move that set
 *     of consonants to the end of the word, and add "ay".
 *
 *  3. If the word begins with a vowel, add "way" to the end
 *     of the word.
 */

#include <iostream>
#include <string>
#include <cctype>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
string lineToPigLatin(string line);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

#pragma mark -
#pragma mark Function Definitions
/*
 * Function: lineToPigLatin
 * Usage: string translation = lineToPigLatin(line);
 * ------------------------------------------------- 
 * Translates each word in the line to Pig Latin, leaving all other
 * characters unchanged. The variable "start" keeps track of the index
 * position at which the current word begins. As a special case, 
 * the code sets start to -1 to indicate that the beginning of the 
 * current word has not yet been encountered.
 */
string lineToPigLatin(string line)
{
    string result;
    int start = -1;
    for ( int i=0; i < line.length(); ++i ) 
    {
        char ch = line[i];
        if ( isalpha(ch) ) 
        {
            if ( start == -1 ) start = i;
        }
        else 
        {
            if ( start >= 0 ) 
            {
                result += wordToPigLatin(line.substr(start, i-start));
                start = -1;
            }
            result += ch;
        }
    }
    if ( start >= 0 ) result += wordToPigLatin(line.substr(start));
    return result; 
}

/*
 * Function: wordToPigLatin
 * Usage: string translation = wordToPigLatin(word);
 * -------------------------------------------------
 * This function translates a word from English to Pig Latin using
 * the rules specified in the text. The translated word is
 * returned as the value of the function.
 */
string wordToPigLatin(string word)
{
    int vp = findFirstVowel(word);
    if ( vp == -1 ) 
    {
        return word;
    }
    else if ( vp == 0 )
    {
        return word + "way";
    }
    else
    {
        string head = word.substr(0,vp);
        string tail = word.substr(vp);
        return tail + head + "ay";
    }
}

/*
 * Function: findFirstVowel
 * Usage: int k = findFirstVowel(word);
 * ------------------------------------
 * Returns the index position of the first vowel in word. If
 * word does not contain a vowel, findFirstVowel returns -1.
 */
int findFirstVowel(string word)
{
    for ( int i=0; i < word.length(); ++i )
    {
        if ( isVowel(word[i]) ) return i;
    }
    return -1; 
}

/*
 * Function: isVowel
 * Usage: if ( isVowel(ch) ) { }
 * ------------------------------
 * Returns true if the character "ch" is a vowel.
 */
bool isVowel(char ch)
{
    switch ( ch ) 
    {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case'u':
            return true;
        default:
            return false;
    }
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    string line, translation;
    while ( true ) {
        line = getLine("Enter English text: ");
        if ( line == "" ) break;
        translation = lineToPigLatin(line);
        cout << "Pig Latin output: " << translation << endl;
        cout << endl;
    }

    return 0;
}