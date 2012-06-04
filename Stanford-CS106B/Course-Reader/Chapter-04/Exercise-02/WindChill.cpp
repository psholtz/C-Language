/*
 * File: WindChill.cpp
 * ---------------------- 
 * Display a wind chill table like that provided by the National Weather Service.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

#pragma mark -
#pragma mark Declarations
double wind_chill(double t, double v);
void table(); 

#pragma mark -
#pragma mark Definitions
/* 
 * Function: double wind_chill(double t, double v)
 * ---------------------------------------- 
 * Perform the wind chill calculation.
 * 
 * t: air temperature, F 
 * v: wind speed, in mph
 *
 * Return: "double" representing the perceived air temperature, 
 *         factoring in the wind chill. 
 */
double wind_chill(double t, double v)
{
    // handle no wind case (we set the "zero" to 1.7, otherwise algorithm works wierd)
    if ( v <= 1.7 ) return t;
    
    // signal error if we are over 40F
    if ( t > 40 ) throw "Wind chill is undefined for temperatures over 40F!";
    
    return 35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16);
}

/*
 * Function: table();
 * ------------------ 
 * Draw a wind chill table, like that provided by the National Weather Service.
 */
void table()
{
    // Draw the header row
    cout << "+------+";
    for ( int temp = 40; temp >= -45; temp -= 5 )
    {
        cout << "-----+";
    }
    cout << endl;
    
    // Draw the body of the temps
    cout << "| Calm |";
    for ( int temp = 40; temp >= -45; temp -= 5 )
    {
        cout << " " << setw(3) << temp << " |";
    }
    cout << endl;
    for ( double wind = 5; wind <= 60; wind += 5 )
    {
        cout.setf(ios::fixed, ios::floatfield);
        cout << "| " << setprecision(0) << setw(3) << wind << "  |";
        for ( double temp = 40; temp >= -45; temp -= 5 )
        {
            cout << " " << right << setprecision(0) << setw(3) << wind_chill(temp,wind) << " |";
        }
        cout << endl;
    }
    
    // Draw the closing row
    cout << "+------+";
    for ( int temp = 40; temp >= -45; temp -= 5 )
    {
        cout << "-----+";
    }
    cout << endl;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    table();
    
    return 0;
}