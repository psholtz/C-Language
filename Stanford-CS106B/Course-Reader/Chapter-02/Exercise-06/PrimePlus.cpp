/*
 * File: Prime.cpp
 * ---------------------
 * Determines whether integers are prime.
 * Uses a (fast) stochastic algorithm based 
 * on the Miller-Rabin test, and Fermat's 
 * Little theorem, as described in SICP.
 */

#include <iostream>
#include <string>
#include <vector>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "random.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
int square(int);
int expmod(int, int, int);
int getRandom(int);
bool testRandom(int,int);
bool isPrime(int);

void loop(); 
void search(int);
void display(vector<int>);

#pragma mark -
#pragma mark Function Definitions
/*
 * Function: square(int n);
 * ------------------------
 * Return the square of n.
 */
int square(int n) { return n*n; }

/*
 * Function: expmod(int base, int exp, int m);
 * -------------------------------------------
 * Fast algorithm for calculating the expmod of 
 * base, exp and m: Take a number "base", raise 
 * it to exponent "exp", and determine what the 
 * modulus of the resulting number is modolo "m".
 */
int expmod(int base, int exp, int m)
{
    if ( exp == 0 ) return 1;
    else if ( exp % 2 == 0 ) return square( expmod(base, exp/2, m) ) % m;
    else return (expmod(base, exp-1, m) * base) % m;
}

/*
 * Function: getRandom(int n);
 * --------------------------- 
 * Return a random integer between 2 and (n-3) inclusive.
 */
int getRandom(int n)
{
    return randomInteger(2, n-3);
}

/*
 * Function: testRandom(int a, int n);
 * -----------------------------------
 * The stochastic test for primality is based on the 
 * Miller-Rabin test, and is based on an alternate 
 * form of Fermat's Little theorem as described in SICP.
 * This method implements the primality test as described
 * in these algorithms.
 */
bool testRandom(int a, int n)
{
    return expmod(a, n-1, n) == 1;
}

/*
 * Function: isPrime(int n);
 * -------------------------
 * Uses a stochastic algorithm, as described in 
 * SICP, to calculate primality of an integer n.
 * In principle, this is (far) better suited for 
 * testing the primality of large integers than the 
 * naive approach of testing up to sqrt(n), although 
 * in C++ we need to handle large integers in the 
 * register in some clever way. This implementation 
 * does not do this, and so is not necessarily well 
 * suited (as written) for large primes. Nevertheless, 
 * it should still calculate primality for small integers
 * in faster time than the naive approach
 */
bool isPrime(int n)
{
    // get the simple cases out of the way
    switch (n)
    {
        case 1:
        case 4:
            return false;
        case 2:
        case 3:
        case 5:
            return true;
    }
    
    // run the stochastic tests for the larger numbers
    int a1 = getRandom(n);
    int a2 = getRandom(n);
    int a3 = getRandom(n);
    
    return  testRandom(n-1, n) &&
            testRandom(n-2, n) &&
            testRandom(a1, n) &&
            testRandom(a2, n) &&
            testRandom(a3, n);
    return true; 
}

/*
 * Function: loop();
 * -----------------
 * Driver loop that prompts user to enter
 * integers to test for primality.
 */
void loop()
{
    while ( true ) 
    {
        int number = getInteger("Enter an integer: ");
        if ( number == SENTINEL ) break;
        if ( isPrime(number) ) 
        {
            cout << "Yes, " << number << " is prime!" << endl;
        }
        else 
        {
            cout << "No, " << number << " is not prime." << endl;
        }
    }
}

/*
 * Function: search(int n);
 * ------------------------ 
 * Search for all primes between 1 and n, inclusive.
 */
void search(int n)
{
    vector<int> integers; 
    for ( int i=1; i <= n; ++i )
    {
        if ( isPrime(i) ) integers.push_back(i);
    }
    display(integers);
}

/*
 * Function: display(vector<int>);
 * -------------------------------
 * Dump a collection of integers to cout.
 */
void display(vector<int> container)
{
    int count = 0;
    vector<int>::iterator it;
    for ( it = container.begin(); it != container.end(); ++it )
    {
        cout << (*it);
        if ( count < container.size() - 1 ) cout << ", ";
        count++;
    }
    cout << endl;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    // seed the PRNG
    srand(time(NULL));
    
    // driver loop
    //loop();
    
    search(100);
    
   return 0;
}
