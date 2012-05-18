//
//  main.cpp
//  Exercise 1.11
//

#include <iostream>

using namespace std;

#pragma mark -
#pragma mrk Declarations
double leibnitz(int);

#pragma mark -
#pragma mark Definitions
double leibnitz(int n)
{
    double total = 0;
    int sign = 1;
    for ( int i=0; i < n; ++i ) 
    {
        sign = i % 2 == 0 ? 1 : -1;
        total += sign * ((double)1.0) / ((double)(2*i+1));
    }
    return total;
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    cout << 4*leibnitz(10000) << endl;  // 3.14149
    
    return 0;
}