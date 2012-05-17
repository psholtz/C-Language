//
//  main.cpp
//  Assignment2
//
//  Created by Engineer on 5/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#pragma mark -
#pragma mark Declarations
string getLine(const string&);
string obenglobish(const string&);
string obenglobish_recur(const string&,int);
bool isVowel(char);
bool isVowelNoE(char);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string value;
    cin >> value;
    return value;
}

bool isVowel(char c)
{
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
}
bool isVowelNoE(char c)
{
    return ( c == 'a' || c == 'i' || c == 'o' || c == 'u' );
}

// let's work w/ strings strictly in lower case
string obenglobish(const string &s)
{
    string work = s;
    transform(s.begin(), s.end(), work.begin(), ::tolower);
    return obenglobish_recur(work,0);
    return work;
}

string obenglobish_recur(const string& s, int index)
{
    for ( int i=index; i < s.length(); ++i ) 
    {   
        // not the last character in the string
        // NEED CHECK FOR VOWELS THAT FOLLOW OTHER VOWELS!
        // check for the very first vowel
        if ( i == 0 ) {
            // check to make sure it's not the last also
            if ( i < s.length() - 1) 
            {
                if ( isVowel(s[i]) ) 
                {
                    string back = s.substr(i);
                    return "ob" + obenglobish_recur(back, i);
                }
            } 
            else 
            {

            }
        }
        else if ( i < s.length()-1 ) 
        {
            if ( isVowel(s[i]) ) 
            {
                string front = s.substr(0,i);
                string back = s.substr(i);
                return front + "ob" + obenglobish_recur(back, i);
            }
        } 

        else 
        {
    
        }
    }
    return s;
}

int main (int argc, const char * argv[])
{    
    // main run loop
    while ( true ) 
    {
        string word = getLine("Enter a word: ");
        if ( word == "" ) break;
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }
    
    return 0;
}

