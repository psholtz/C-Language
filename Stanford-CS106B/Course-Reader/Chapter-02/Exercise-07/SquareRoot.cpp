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
/*
 * Function: abs(double x);
 * ------------------------
 * Return the absolute value of x.
 */
double abs(double x)
{ return x < 0 ? -x : x; }

/*
 * Function: square(double);
 * -------------------------
 * Return the double of the argument.
 */
double square(double x) 
{ return x*x; }

/*
 * Function: sqrt(double x);
 * -------------------------
 * Return the square root of x.
 * Initial guess is made at x/2.
 */
double sqrt(double x)
{ return sqrt_iter(x/2.0,x); }

/*
 * Function: squrt(double guess, double x);
 * ----------------------------------------
 * Recursive (iterative) procedure for calculating 
 * square roots. Start with a guess for what square 
 * root is. If the guess is within the tolerance
 * limits, then terminate. Otherwise, continue 
 * improving and checking the guess.
 */
double sqrt_iter(double guess, double x)
{
    if ( good_enough(guess,x) )
    {
        return guess;
    }
    return sqrt_iter(improve(guess,x), x);
}

/*
 * Function: improve(double guess, double x);
 * ------------------------------------------
 * Procedure for improving the guess of the 
 * square root. Returns the average of "guess"
 * and "x/guess", since guess * x / guess is
 * equal to x, and the average of these values
 * should (approach) x.
 */
double improve(double guess,double x)
{ return average(guess,x/guess); }

/*
 * Function: average(double x, double y);
 * --------------------------------------
 * Return the average of x and y.
 */
double average(double x,double y) 
{ return (x+y)/2.0; }


/*
 * Function: good_enough(double guess, double x);
 * ---------------------------------------------- 
 * Is the square rootof guess close enough to x?
 */
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
