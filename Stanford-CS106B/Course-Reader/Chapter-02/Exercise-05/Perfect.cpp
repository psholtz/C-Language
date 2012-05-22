/*
 * File: Perfect.cpp
 * --------------------------
 * Demonstrates how to use the Stanford C++ graphics library 
 * to draw a simple checkerboard.
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

bool isPerfect(int number)
{
    return number == sum(factors(number)); 
}

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
