/*
 * File: MonteCarlo.cpp
 * --------------------
 * Code for running Monte Carlo simulations.
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
bool simulation();
double pi();

#pragma mark -
#pragma mark Function Definitions
/*
 * Function: bool simulation();
 * ---------------------------- 
 * Run one instance of the Monte Carlo simulation.
 */
bool simulation()
{
    double x = randomReal(-1.0f, +1.0f);
    double y = randomReal(-1.0f, +1.0f);
    
    return x*x + y*y < 1.0;
}

/*
 * Function: double pi();
 * ----------------------
 * Use Monte Carlo simulations to approximate a value for pi.
 */
double pi()
{
    int good = 0, total = 0;
    for ( int i=0; i < 10000; ++i ) 
    {
        if ( simulation() ) { good++; }
        total++;
    }
        
    return 4 * (double)good / (double)total; 
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    string response;
    while ( true ) {
        cout << "My approximation for PI is: " << pi() << endl; 
        response = getLine("Perform another simulation? ");
        if ( !(response == "y" || response == "Y" || response == "yes" || response == "YES") ) break;
        cout << endl;
    }
    
    return 0;
}