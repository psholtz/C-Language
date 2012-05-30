/*
 * File: Commas.cpp
 * --------------------
 * Add commas to a number.
 */

#include <iostream>
#include <string>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL ""

using namespace std; 

#pragma mark -
#pragma mark Function Prototypes
string addCommas(string digits); 

#pragma mark -
#pragma mark Function Definitions
string addCommas(string digits)
{
    // build the buffer with the commas
    stringstream buffer;
    int count = 0;
    for ( int i=digits.length()-1; i >= 0; --i ) 
    {
        if ( count > 0 && count %3 == 0 ) 
        {
            buffer << ",";
        }
        buffer << digits[i];
        count++;
    }

    // reverse the string for final answer 
    string answer = buffer.str();
    answer = string( answer.rbegin(), answer.rend() );
    return answer;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    string number;
    while ( true ) {
        number = getLine("Enter a number: ");
        if ( number == SENTINEL ) break;
        cout << addCommas(number) << endl;
    }
    
    return 0;
}