/*
 * File: Letter.cpp
 * --------------------------
 * Implement a letter substitution cipher.
 * 
 * In this exercise we simply implement a "decode" routine, 
 * to complement the "encode" routine developed in the previous
 * problem.
 * 
 * Basis: ABCDEFGHIJKLMNOPQRSTUVWXYZ
 * Good sample key: QWERTYUIOPASDFGHJKLZXCVBNM
 */

#include <iostream>
#include <string>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define STRING_SENTINEL ""

#define STRING_BASIS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

using namespace std;

#pragma mark -
#pragma mark Declarations
string encode(const string& plaintext, const string& key);
string decode(const string& ciphertext, const string& key);
void generateKeys(const string& key, string& upper, string& lower);

#pragma mark -
#pragma mark Definitions
/*
 * Function: encode(const string& plaintext, const string& key);
 * -------------------------------------------------------------
 * Generate the letter-substitution cipher text from the plaintext and key.
 */
string encode(const string& plaintext, const string& key)
{
    static string kBasis = STRING_BASIS;
    
    // generate the keys we need
    if ( key.length() != 26) return "";
    
    string upperKey = "";
    string lowerKey = "";
    generateKeys(key, upperKey, lowerKey);
    
    if ( upperKey.length() != 26 || lowerKey.length() != 26 ) return "";

    char ch; size_t index;
    stringstream buffer; 
    for ( int i=0; i < plaintext.length(); ++i ) 
    {
        ch = plaintext[i];
        if ( isalpha(ch) )
        {
            if ( isupper(ch) )
            {
                index = kBasis.find_first_of(ch);
                buffer << (char)upperKey[index];
            }
            else if ( islower(ch) )
            {
                index = kBasis.find_first_of(ch);
                buffer << (char)lowerKey[index];
            }
        }
        else 
        {
            buffer << ch;
        }
    }
    
    return buffer.str();
}

/*
 * Function: decode(const string& ciphertext, const string& key);
 * -------------------------------------------------------------- 
 * Generate the letter-substitution plain text from the ciphertext and key.
 */
string decode(const string& ciphertext, const string& key)
{
    static string kBasis = STRING_BASIS;   
    
    // generate the keys we need
    if ( key.length() != 26) return "";
    
    string upperKey = "";
    string lowerKey = "";
    generateKeys(key, upperKey, lowerKey);
    
    if ( upperKey.length() != 26 || lowerKey.length() != 26 ) return "";
    
    char ch; size_t index;
    stringstream buffer;
    for ( int i=0; i < ciphertext.length(); ++i )
    {
        ch = ciphertext[i];
        if ( isalpha(ch) )
        {
            if ( isupper(ch) )
            {
                index = upperKey.find_first_of(ch);
                buffer << (char)kBasis[index];
            }
            else if ( islower(ch) )
            {
                index = lowerKey.find_first_of(ch);
                buffer << (char)kBasis[index];
            }
        }
        else
        {
            buffer << ch;
        }
    }
    
    return buffer.str(); 
}

/*
 * Function: generateKeys(const string& key, string& upper, string& lower);
 * ------------------------------------------------------------------------ 
 * To support both upper and lower case, translate the user-supplied key 
 * to both upper and lower case.
 */
void generateKeys(const string& key, string& upper, string& lower)
{
    char ch;
    stringstream upperBuffer, lowerBuffer;
    for ( int i=0; i < key.length(); ++i )
    {
        ch = key[i];
        upperBuffer << (char)toupper(ch);
        lowerBuffer << (char)tolower(ch);
    }
    
    upper = upperBuffer.str();
    lower = lowerBuffer.str();
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    string key, plaintext, ciphertext; 
    while ( true ) {
        //
        // Get the key from the user
        //
        key = "";
        while ( key.length() != 26 )
        {
            key = getLine("Enter a 26-letter key: ");
            if ( key == STRING_SENTINEL ) break;
        }
        if ( key.length() != 26 ) break; 

        //
        // Get the plaintext from the user
        //
        plaintext = getLine("Enter ciphertext: ");
        if ( plaintext == STRING_SENTINEL ) break;
        
        ciphertext = decode(plaintext, key);
        cout << "Encoded message: " << ciphertext << endl;
        cout << endl;
    }
    
    return 0;
}
