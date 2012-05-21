/*
 * File: Distance.cpp
 * ---------------------
 * Performs meter-to-English conversion.
 */

#include <iostream>
#include <string>
#include <math.h>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
void meterToEnglish(double meters, double &feet, double &inches);

#pragma mark -
#pragma mark Function Definitions
void meterToEnglish(double meters, double &feet, double &inches) 
{
    double temp1 = meters / 0.0254;
    feet = (int)(temp1 / 12);
    inches = ceilf((temp1 - feet * 12) * 100) / 100;    // round to 2 decimal places 
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    while ( true ) {
        double meters = getReal("Enter length in meters: ");
        double feet, inches;
        meterToEnglish(meters, feet, inches);
        cout << meters << " meters -> " << feet << " feet, " << inches << " inches." << endl;
    }
    
   return 0;
}
