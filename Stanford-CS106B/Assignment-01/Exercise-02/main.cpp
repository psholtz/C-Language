//
//  main.cpp
//  Assignment 1.2
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
int next_consonant(const string&);
bool is_vowel(char);

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

string obenglobish(const string &s)
{
    // Let's work w/ strings strictly in lower case.
    string work = s;
    transform(s.begin(), s.end(), work.begin(), ::tolower);
    
    return obenglobish_recur(s,0);
}

string obenglobish_recur(const string &s,int index)
{
    for ( int i=index; i < s.length(); ++i ) 
    {
        if ( is_vowel(s[i]) )
        {
            string prev = s.substr(0,i);
            string next = s.substr(i+1);
            int marker = next_consonant(next);
            
            if ( i < s.length() - 1 || s[i] != 'e' )
            {
                return prev + "ob" + s[i] + obenglobish_recur(next,marker);
            }
        }
    }
    return s;
}

int next_consonant(const string &s)
{
    int i;
    for ( int i=0; i < s.length(); ++i ) 
    {
      if ( !is_vowel(s[i]) ) { return i; }
    }
    return i;
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

