/*
 * File: combinatorics.cpp
 * -----------------------
 * Implementation of C(n,k) and P(n,k) functions.
 */

#include <iostream>
#include <string>
#include <sstream>

#include "combinatorics.h"

// Stanford C++ Libraries
#include "error.h"

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
int fact(int);
int permutations_iter(int, int, int);

#pragma mark -
#pragma mark Function Definitions
/*
 * Function: combinations(int n, int k);
 * -------------------------------------
 * Return the number of combinations of n choose k.
 */
int combinations(int n, int k)
{
    if ( k > n || k < 0 || n < 0 ) 
    { 
        stringstream msg;
        msg << "COMBINATIONS --> Bad Argument Size: n=" << n << ", k=" << k;
        error(msg.str());
    }
    
    return permutations(n,k) / fact(k);
}

/*
 * Function: fact(int n);
 * ----------------------
 * Calculate the factorial of n. Used as helper 
 * function to calculate combinations.
 */
int fact(int n)
{
    int result = 1;
    for ( int i=1; i <= n; ++i ) {
        result *= i;
    }
    return result;
}

/*
 * Function: permutations(int n, int k);
 * ------------------------------------- 
 * Return permutations of n choose k (i.e., P(n,k)).
 */
int permutations(int n, int k)
{
    if ( k > n || k < 0 || n < 0 ) 
    { 
        stringstream msg;
        msg << "PERMUTATIONS: Bad Argument Size: n=" << n << ", k=" << k;
        error(msg.str());
    }
    
    return permutations_iter(n,n-k,1);
}

/*
 * Function: permutations_iter(int n, int k, int total);
 * ----------------------------------------------------- 
 * Iterative procedure for calculating permutations.
 */
int permutations_iter(int n, int k, int total)
{
    if ( n == k ) return total;
    return permutations_iter(n-1, k, n*total);
}
