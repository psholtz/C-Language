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
bool is_vowel(char);
bool is_vowel_minus_e(char);
int next_consonant(const string&,int);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string value;
    cin >> value;
    return value;
}

bool is_vowel(char c)
{
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
}
bool is_vowel_minus_e(char c)
{
    return ( c == 'a' || c == 'i' || c == 'o' || c == 'u' );
}

string obenglobish(const string &s)
{
    // Let's work w/ strings strictly in lower case.
    string work = s;
    transform(s.begin(), s.end(), work.begin(), ::tolower);
    
    // Handle one character strings specially
    if ( s.length() == 1 )
    {
        if ( is_vowel(s[0]) )
        {
            return "ob" + s;
        }
        else 
        {
            return s;
        }
    }
    
    // Handle strings that start with vowels specially
    else 
    {
        /*if ( is_vowel(s[0]) ) 
        {
            int next = next_consonant(s.substr(0), 0);
            return "ob" + obenglobish_recur(s, next);
        }
        else 
        {
            return obenglobish_recur(s, 1);
        }*/
    }
}

string obenglobish_recur(const string& s, int index)
{
    for ( int i=index; i < s.length(); ++i ) 
    {   
        // Not the last character in string.
        if ( i < s.length() - 1 )
        {
            if ( is_vowel(s[i]) ) 
            {
                string front = s.substr(0,i);
                string back = s.substr(i);
                int next = next_consonant(back, i);
                return front + "ob" + obenglobish_recur(back, next);
            }
        }
        
        // This is the last character in the string.
        else 
        {
            if ( is_vowel_minus_e(s[i]) )
            {
                string front = s.substr(0,i);
                return front + "ob" + s[i];
            }
        }
    }
    return s;
}

int next_consonant(const string& s,int index) 
{
    if ( s.length() > 1 ) 
    {
        for ( int i=0; i < s.length(); ++i ) 
        {
            if ( !is_vowel(s[i]) ) { break; }
        }
        return index + 1;
    }
    return index;
}

#pragma mark -
#pragma mark Main Driver
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

