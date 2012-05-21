/*
 * File: Round.cpp
 * ---------------------
 * Performs meter-to-English conversion.
 */

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "error.h"

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
double wind_chill(double t, double v);
void format(double&,int);
int round_number(double); 
void loop();
void table();

#pragma mark -
#pragma mark Function Definitions
double wind_chill(double t, double v)
{
    // handle no wind case (we set the "zero" to 1.7, otherwise algorithm works wierd)
    if ( v <= 1.7 ) return t;
    
    // signal error if we are over 40F
    if ( t > 40 ) error("Wind chill is undefined for temperatures over 40F!");
    
    return 35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16);
}

/*
 * Function: format(t,n)
 * --------------------- 
 * Truncate the double value t at 2 decimal places.
 */
void format(double &t, int n)
{
    int factor = pow(10,n);
    
    t = ceilf( t * factor) / factor;
}

int round_number(double d)
{
    if ( d >= 0 ) 
        return (int)(d+0.5);
    return (int)(d-0.5);
}

void loop()
{
    while ( true ) {
        // get temperature and wind velocity
        double number1 = getReal("Enter temperature in F: ");
        double number2 = getReal("Enter velocity in mph: ");
        double windChill = wind_chill(number1, number2);
        format(windChill, 2);
        
        cout << "The wind chill at " << number1 << " F with wind velocity " << number2 << " mph is " << windChill << "." << endl;
        cout << endl;
    }
}

/*
 * Function: table()
 * -----------------
 * Generate the wind chill table as illustrated in the text.
 */
void table()
{
    //
    // HEADER
    //
    int width1 = 118, width2 = 10;
    cout << setw(65) << "Temperature" << endl;
    for ( int i=0; i < width1; ++i ) { cout << "-"; } cout << endl;
    for ( int i=0; i < width2; ++i ) { cout << " "; }
    for ( int t = 40; t >= -45; t -= 5 )
    {
        cout << setw(5) << t << " ";
    }
    cout << endl;
    for ( int i=0; i < width1; ++i ) { cout << "-"; } cout << endl;
    
    // 
    // BODY
    //
    double windChill;
    for ( int v = 5; v <= 60; v += 5 )
    {
        cout << setw(5) << v << "   | ";
        for ( int t = 40; t >= -45; t -= 5 ) 
        {
            windChill = wind_chill(t, v);
            cout << setw(5) << round_number(windChill) << " ";
        }
        cout << endl;
    }
    
    // 
    // FOOTER
    //
    for ( int i=0; i < width1; ++i ) { cout << "-"; } cout << endl;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    // enter i/o loop on console
    //loop();
    
    // generate the wind chill table
    table();
    
   return 0;
}
