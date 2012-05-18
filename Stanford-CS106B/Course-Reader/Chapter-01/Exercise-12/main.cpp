//
//  main.cpp
//  Exercise 1.12
//

#include <iostream>
#include <math.h>

using namespace std;

#pragma mark -
#pragma mrk Declarations
double integrator(int);

#pragma mark -
#pragma mark Definitions
double integrator(int n)
{
    double dx = 2.0 / ((double)n);
    double total = 0.0;
    double x1, x2, x, h;
    for ( int i=0; i < n; ++i ) 
    {
        x1 = 2.0 * ((double)i) / ((double)n);
        x2 = 2.0 * ((double)(i+1)) / ((double)n);
        x = (x1+x2)/2.0;
        h = sqrt(4 - x*x);
        total += h * dx;
    }
    return total;
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    cout << integrator(10000) << endl;  // 3.14159
    
    return 0;
}