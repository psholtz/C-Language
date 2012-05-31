/*
 * File: Caesar.cpp
 * --------------------------
 * Program for performing Caesar ciphers.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define STRING_SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
string encodeCaesarCipher(string, int);
char shiftLower(char, int);
char shiftUpper(char, int);

#pragma mark -
#pragma mark Definitions
/*
 * Function: encodeCaesarCipher(string message, int shift);
 * -------------------------------------------------------- 
 * Shift the "message" over by "shift" positions.
 */ 
string encodeCaesarCipher(string message, int shift)
{
    stringstream buffer; char ch, tmp;
    for ( int i=0; i < message.length(); ++i ) 
    {
        ch = message[i];
        if ( isalpha(ch) )
        {
            if ( islower(ch) ) 
            {
                tmp = shiftLower(ch, shift);
            }
            else if ( isupper(ch) )
            {
                tmp = shiftUpper(ch, shift);
            }
            buffer << tmp;
        }
        else 
        {
            buffer << ch;
        }
    }
    return buffer.str();
}

/*
 * Function: shiftLower(char, int);
 * -------------------------------- 
 * Lowercase letters have different ASCII boundaries.
 * This function performs shift on the lower case letters.
 */ 
char shiftLower(char ch, int shift)
{
    if ( shift == 0 ) return ch;
    
    int value = (int)ch;
    value += shift;
    if ( value < 97 )
    {
        while ( value < 97 )
        {
            value += 26;
        }
    }
    else if ( value > 122 )
    {
        while ( value > 122 ) 
        {
            value -= 26;
        }
    }
    
    return (char)value;
}

/*
 * Function: shiftUpper(char, int);
 * --------------------------------
 * Uppercase letters have different ASCII boundaries.
 * This function performs shift on the upper case letters.
 */
char shiftUpper(char ch, int shift)
{
    if ( shift == 0 ) return ch;
    
    int value = (int)ch;
    value += shift;
    if ( value < 65 )
    {
        while ( value < 65 )
        {
            value += 26;
        }
    } 
    else if ( value > 90 )
    {
        while ( value > 90 )
        {
            value -= 26;
        }
    }
    return (char)value;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    string message, encoding;
    int shift;
    while ( true ) {
        shift = getInteger("Enter shift size: "); 
        message = getLine("Enter a message: ");
        if ( message == STRING_SENTINEL ) break;
        encoding = encodeCaesarCipher(message, shift);
        cout << "Encoded message: " << encoding << endl;
        cout << endl;
    }
    
    return 0;
}
