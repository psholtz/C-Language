/*
 * File: Atoms.cpp
 * --------------------
 * Model the random decay of atoms. 
 */

#include <iostream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "random.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
int surviving_atoms(int);

#pragma mark -
#pragma mark Function Definitions
int surviving_atoms(int atoms)
{
    int total = 0;
    for ( int i=0; i < atoms; ++i ) 
    {
        if ( randomChance(0.5) ) 
        {
            total++;
        }
    }
    return total;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    int n = 10000;  // initial number of atoms
    int years = 0;
    
    cout << "There are " << n << " atoms initially." << endl;
    while ( n > 0 ) 
    {
        n = surviving_atoms(n);
        years++;
        cout << "There are " << n << " atoms at the end of year " << years << "." << endl;
    }
    return 0;
}