/*
 * File: Round.cpp
 * ---------------------
 * Performs meter-to-English conversion.
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
int round_number(float);

#pragma mark -
#pragma mark Function Definitions
int round_number(float f) 
{
    return (int)(f+0.5);
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {

    while ( true ) {
        double number1 = getReal("Enter number: ");
        int number2 = round_number(number1);
        cout << number1 << " rounded is " << number2 << endl;
    }
    
   return 0;
}
