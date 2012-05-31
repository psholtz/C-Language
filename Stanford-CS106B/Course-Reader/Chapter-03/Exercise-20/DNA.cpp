/*
 * File: Caesar.cpp
 * --------------------------
 */

#include <iostream>
#include <string>
#include <vector>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define STRING_SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Declarations
vector<int> findAllDNAMatches(string s1, string s2);
int findDNAMatch(string s1, string s2, int start=0);
void displayInts(vector<int> collection);

#pragma mark -
#pragma mark Definitions
vector<int> findAllDNAMatches(string s1, string s2)
{
    vector<int> answers;
    int index = 0;
    while ( index != -1 )
    {
        index = findDNAMatch(s1, s2, index);
        if ( index != -1 ) 
        {
            answers.push_back(index);
        }
    }
    
    return answers;
}

int findDNAMatch(string s1, string s2, int start)
{
    return -1;
}

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
        // Calculate matching positions
        //
    }

    
    return 0;
}
