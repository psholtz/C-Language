/*
 * File: Atoms.cpp
 * --------------------
 * Model the random decay of atoms. 
 */

#include <iostream>

#include "calendar.h"

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    int year; 
    while ( true ) {
        year = getInteger("Enter a year: ");
        if ( year == SENTINEL ) break;
        
        // iterate through the enumeration
        for ( int month=1; month <= 12; ++month ) 
        {
          cout << monthToString(month) << " has " << daysInMonth(month, year) << " days." << endl;
        }
        
        cout << endl;
    }
    return 0;
}