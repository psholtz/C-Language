/*
 * File: Prime.cpp
 * ---------------------
 * Determines whether integers are prime.
 */

#include <iostream>
#include <string>
#include <math.h>
#include <vector>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
bool isPrime(int);

void loop(); 
void search(int);
void display(vector<int>);

#pragma mark -
#pragma mark Function Definitions
bool isPrime(int n)
{
    if ( n == 1 ) return false;
    if ( n == 2 ) return true;
    for ( int i=2; i < sqrt(n)+1; ++i ) 
    {
        if ( n % i == 0 ) return false;
    }
    return true; 
}

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

void search(int n)
{
    vector<int> integers; 
    for ( int i=1; i <= n; ++i )
    {
        if ( isPrime(i) ) integers.push_back(i);
    }
    display(integers);
}

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

    // driver loop
    //loop();
    
    search(100);
    
   return 0;
}
