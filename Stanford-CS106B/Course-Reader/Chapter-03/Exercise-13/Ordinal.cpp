/*
 * File: Ordinal.cpp
 * --------------------
 * Return the ordinal of a number.
 */

#include <iostream>
#include <string>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL 0

using namespace std; 

#pragma mark -
#pragma mark Function Prototypes
string createOrdinalForm(int n);

#pragma mark -
#pragma mark Function Definitions
string createOrdinalForm(int n)
{
    stringstream buffer; 
    switch ( n % 10 )
    {
        case 1:
            buffer << n << "st";
            break;
        case 2:
            buffer << n << "nd";
            break;
        case 3:
            buffer << n << "rd";
            break;
        default:
            buffer << n << "th";
            break; 
    }
    return buffer.str();
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    int number;
    while ( true ) {
        number = getInteger("Enter a number: ");
        if ( number == SENTINEL ) break;
        cout << createOrdinalForm(number) << endl;
    }
    
    return 0;
}