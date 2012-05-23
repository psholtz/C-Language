/*
 * File: Perfect.cpp
 * --------------------------
 * Calculates perfect numbers.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Declarations
vector<int> factor(int);
void display(vector<int>);  // used for testing
int sum(vector<int>); 
bool isPerfect(int);

void loop();
void search(int);

#pragma mark -
#pragma mark Definitions
/*
 * Function: factors(int n);
 * -------------------------
 * Return a container containing all the 
 * factors of n (less than n), including 1.
 */
vector<int> factors(int n)
{
    vector<int> factors;
    
    for ( int i=1; i < n; ++i ) 
    {
        if ( n % i == 0 ) 
        {
            factors.push_back(i);
        }
    }
    
    return factors;
}

/*
 * Function: display(vector<int> elements);
 * ----------------------------------------
 * Display a list of elements, separating 
 * them by commas.
 */
void display(vector<int> elements)
{
    int count = 0;
    size_t len = elements.size();
    vector<int>::iterator it;
    for ( it = elements.begin(); it != elements.end(); ++it )
    {
        cout << (*it);
        count++;
        if ( count < len ) { cout << ", "; }
    }
    cout << endl;
}

/*
 * Function: sum(vector<int> elements);
 * ------------------------------------
 * Return the sum of a collection of integers.
 */
int sum(vector<int> elements)
{
    int count = 0;
    vector<int>::iterator it;
    for ( it = elements.begin(); it != elements.end(); ++it )
    {
        count += (*it);
    }
    return count;
}

/*
 * Function: isPerfect(int number);
 * -------------------------------- 
 * Return true if the number is perfect, otherwise false.
 */
bool isPerfect(int number)
{
    return number == sum(factors(number)); 
}

/*
 * Function: loop();
 * ----------------- 
 * Driver loop that obtains numbers from
 * user, and determines if they are perfect.
 * If perfect, it lists the proper divisors.
 */
void loop()
{
    while ( true ) 
    {
        int number = getInteger("Enter Integer: ");
        if ( number == SENTINEL ) break;
        if ( isPerfect(number) ) 
        {
            cout << "Yes, " << number << " is perfect! --> ";
            display(factors(number));
        }
        else 
        {
            cout << "No, " << number << " is not perfect." << endl; 
        }
    }
}

/*
 * Function: search(int n);
 * ------------------------
 * Search all positive integers, less than 
 * n, to determine which of them are perfect.
 */
void search(int n)
{
    for ( int i=1; i < n; ++i ) 
    {
        if ( isPerfect(i) ) 
        {
            stringstream s;
            s << i << " is perfect!";
            cout << s.str() << endl;
        }
    }
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    // main loop
    loop();
    
    // search for perfect numbers
    //search(10000);
    
    return 0;
}
