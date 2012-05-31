/*
 * File: DNA.cpp
 * -------------
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "strlib.h"

#define STRING_SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
vector<int> findAllDNAMatches(string s1, string s2);
int findDNAMatch(string s1, string s2, int start=0);
void displayInts(vector<int> collection);
string sanitize(string s);
bool matches(char ch1, char ch2);

#pragma mark -
#pragma mark Definitions
/*
 * Function: findAllDNAMatches(string s1, string s2)
 * -------------------------------------------------
 * Return all indexes in string s2, where we have a 
 * DNA match for base pairs against string s1.
 */
vector<int> findAllDNAMatches(string s1, string s2)
{
    vector<int> answers;
    int index = 0;
    while ( index != -1 )
    {
        // find the index if it is there
        index = findDNAMatch(s1, s2, index); 
        if ( index != -1 ) 
        {
            answers.push_back(index);
        }
        
        // advance one further
        if ( index != -1 ) index++;
    }
    
    return answers;
}

/*
 * Function: findDNAMatch(string s1, string s2, int start);
 * --------------------------------------------
 * Search string s2, beginning at index start, 
 * searching for base pair matches with string s1.
 */ 
int findDNAMatch(string s1, string s2, int start)
{
    // size error
    if ( s1.length() > s2.length() ) return -1;
    
    bool found = true;
    for ( int i=start; i < s2.length() - s1.length() + 1; ++i ) 
    {
        found = true;
        for ( int j=0; j < s1.length(); ++j ) 
        {
            if ( !matches(s1[j],s2[i+j]) )
            {
                found = false;
                break;
            }
        }
        if ( found ) return i; 
    }
    
    return -1;
}

/*
 * Function: displayInts(vector<int>);
 * -----------------------------------
 * Display a collection of integers to standard output.
 */ 
void displayInts(vector<int> collection)
{
    int count = 0;
    vector<int>::iterator it;
    for ( it = collection.begin(); it != collection.end(); ++it )
    {
        cout << (*it);
        if ( count < collection.size() - 1 )
        {
            cout << ", ";
        }
        count++;
    }
    cout << endl;
}

/*
 * Function: sanitize(string s);
 * ----------------------------- 
 * Sanitize the argument string by trimming whitespace
 * and converting everything to uppercase.
 */
string sanitize(string s)
{
    stringstream buffer;
    for ( int i=0; i < s.length(); ++i ) {
        buffer << (char)toupper(s[i]);
    }
    return buffer.str();
}

/*
 * Function: matches(char ch1, char ch2);
 * -------------------------------------- 
 * Return true if the base pairs match, that is, if:
 * 
 * ch1 == 'T' and ch2 == 'A'
 * ch1 == 'A' and ch2 == 'T'
 * ch1 == 'C' and ch2 == 'G'
 * ch1 == 'G' and ch2 == 'C'
 *
 * Otherwise, the function returns false.
 */
bool matches(char ch1, char ch2)
{
    if ( ch1 == 'T' && ch2 == 'A' ) return true;
    if ( ch1 == 'A' && ch2 == 'T' ) return true;
    if ( ch1 == 'C' && ch2 == 'G' ) return true;
    if ( ch1 == 'G' && ch2 == 'C' ) return true;
    return false;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    string shortStrand, longStrand;
    while ( true ) {
        //
        // Get the DNA strands from the user.
        // 
        shortStrand = getLine("Enter the short strand: ");
        if ( shortStrand == STRING_SENTINEL ) break;
        longStrand = getLine("Enter the long strand: ");
        if ( longStrand == STRING_SENTINEL ) break;
        
        //
        // Sanitize the user input
        //
        shortStrand = sanitize(trim(shortStrand));
        longStrand = sanitize(trim(longStrand));
        
        //
        // Calculate matching positions 
        vector<int> matches = findAllDNAMatches(shortStrand, longStrand);
        if ( matches.size() > 0 )
        {
            cout << "Matches: "; displayInts(matches); cout << endl;;
        }
        else 
        {
            cout << "No matches!" << endl; 
            cout << endl;
        }
    }
    
    
    return 0;
}