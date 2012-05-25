/*
 * File: SquareRoot.cpp
 * ---------------------
 * Uses an iterative technique to calculate square 
 * roots, based on Problem 1.7 in SICP.
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL 0.0

#define TOLERANCE 0.0001

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
double abs(double);
double square(double);
double sqrt(double);
double sqrt_iter(double,double);
double improve(double,double);
double average(double,double);
bool good_enough(double,double);

#pragma mark -
#pragma mark Function Definitions
double abs(double x)
{ return x < 0 ? -x : x; }

/*
 * Function: square(double);
 * -------------------------
 * Return the double of the argument.
 */
double square(double x) 
{ return x*x; }

double sqrt(double x)
{ return sqrt_iter(x/2.0,x); }

double sqrt_iter(double guess, double x)
{
    if ( good_enough(guess,x) )
    {
        return guess;
    }
    return sqrt_iter(improve(guess,x), x);
}

double improve(double guess,double x)
{ return average(guess,x/guess); }

double average(double x,double y) 
{ return (x+y)/2.0; }


bool good_enough(double guess,double x)
{
    return abs(square(guess)/x - 1.0) < TOLERANCE;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    while ( true ) {
        double number = getReal("Enter number: ");
        if ( number == SENTINEL ) break;
        double answer = sqrt(number);
        cout << "The square root of " << number << " is " << answer << endl;
    }
    
    return 0;
}
