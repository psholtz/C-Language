/*
 * File: Temperature.cpp
 * ---------------------
 * Performs Celcius-to-Fahrenheit conversions.
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
double CToF(double celsius);

#pragma mark -
#pragma mark Function Definitions
double CToF(double celsius)
{
    return (9.0/5.0) * celsius + 32.0f;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    while ( true ) {
        double value1 = getReal("Enter Temperature: ");
        double value2 = CToF(value1);
        cout << value1 << "C -> " << value2 << "F" << endl;
    }
    
   return 0;
}
