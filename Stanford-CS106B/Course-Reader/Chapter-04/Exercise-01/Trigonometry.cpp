/*
 * File: Trigonometry.cpp
 * ---------------------- 
 * Write program that displays sine/cosine tables.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define PI 3.14159265358979323846

using namespace std;

#pragma mark -
#pragma mark Declarations
void display();
double radians(double angle); 

#pragma mark -
#pragma mark Definitions
/*
 * Function: display();
 * --------------------
 * Render display using I/O manipulators, as per requirements.
 */
void display()
{
    cout << "+-------+------------+------------+" << endl;
    cout << "| theta | sin(theta) | cos(theta) |" << endl;
    cout << "+-------+------------+------------+" << endl;
    for ( double angle = -90; angle <= +90; angle += 15 )
    {
        cout.unsetf(ios::floatfield);
        cout << "|  " << setw(3) << right << angle << "  |";
        cout.setf(ios::fixed, ios::floatfield);
        cout << " " << setw(10) << right << setprecision(7) << sin(radians(angle)) << " |";
        cout << " " << setw(10) << right << setprecision(7) << cos(radians(angle)) << " |";
        cout << endl;
    }
    cout << "+-------+------------+------------+" << endl;
}

/*
 * Function: radians(double degrees);
 * ---------------------------------- 
 * Function given in degrees, return the answer in radians.
 *
 * Return: "double" representing the angle in radians.
 */
double radians(double degrees)
{
    return degrees * PI / 180.0;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    display(); 
    
    return 0;
}