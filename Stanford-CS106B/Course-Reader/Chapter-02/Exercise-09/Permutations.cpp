/*
 * File: Permutations.cpp
 * ---------------------
 * Algorithm for calculating the permutations of P(n,k).
 */

#include <iostream>
#include <string>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "error.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
int permutations(int, int);
int permutations_iter(int, int, int);

#pragma mark -
#pragma mark Function Definitions
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
        msg << "Bad argument size: n=" << n << ", k=" << k;
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

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    int n, k;
    while ( true ) {
        n = getInteger("Enter n: ");
        k = getInteger("Enter k: ");
        if ( n == SENTINEL && k == SENTINEL ) break;
        cout << "There are P(n,k) = " << permutations(n,k) << " permutations." << endl;
        cout << endl;
    }
    
    return 0;
}
