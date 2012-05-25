/*
 * File: Random.cpp
 * --------------------
 * Calculate the average of a series of random numbers. 
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
double average_of_trials(int n);

#pragma mark -
#pragma mark Function Definitions
double average_of_trials(int n)
{
    int count = 0;
    double total = 0.0f;
    
    for ( int i=0; i < n; ++i )
    {
        total += randomReal(0.0, 1.0);
        count++;
    }
    return total / count;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    int trials;
    while ( true ) 
    {
        trials = getInteger("Enter number of trials: ");
        if ( trials == 0 ) break;
        cout << "Average number after " << trials << " trials: " << average_of_trials(trials) << endl;
        cout << endl;
    }
    
    return 0;
}