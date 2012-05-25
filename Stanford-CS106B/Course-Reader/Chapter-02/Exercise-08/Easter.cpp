/*
 * File: SquareRoot.cpp
 * ---------------------
 * Uses an iterative technique to calculate square 
 * roots, based on Problem 1.7 in SICP.
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
void findEaster(int year, string &month, int &day);
void findEasterGregorian(int year, string &month, int &day);

#pragma mark -
#pragma mark Function Definitions
/*
 * Function: findEaster(int year, string &month, int &day);
 * --------------------------------------------------------
 * Original Gauss algorithm for finding Easter in years
 * between 1700 and 1899.
 *
 * Comparing this algorithm with samples given on the page: 
 * http://tlarsen2.tripod.com/thomaslarsen/easterdates.html
 * it appears that the algorithm is correct.
 */
void findEaster(int year, string &month, int &day)
{
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (19*a + 23) % 30;
    int e = 0;
    if ( year >= 1700 && year <= 1799 )
    {
        e = (2*b + 4*c + 6*d + 3) % 7;
    }
    else if ( year >= 1800 && year <= 1899 )
    {
        e = (2*b + 4*c + 6*d + 4) % 7;
    }
    
    if ( d + e <= 9 )
    {
        month = "March";
        day = 22 + d + e;
    }
    else 
    {
        month = "April";
        day = d + e - 9;
    }
}

/*
 * Function: findEasterGregorian(int year, string &month, int &day);
 * ---------------------------------------------------------------- 
 * This algorithm is able to calculate Easter correctly for all dates
 * in the Gregorian calendar, which means, from the year 1583 onward 
 * (inclusive). 
 * 
 * It was first described anonymously from a correspondent in New York to 
 * the journal Nature in 1876. The algorithm appears in "Practical Astronomy
 * with your Calculator" by Peter Duffett-Smith, and he obtained the algorithm
 * from "Butcher's Ecclesiastical Calendar" published in 1876. The algorithm is 
 * described further here:
 * http://www.smart.net/~mmontes/nature1876.html
 * 
 * Comparing this algorithm with samples given on the page: 
 * http://tlarsen2.tripod.com/thomaslarsen/easterdates.html
 * it appears that the algorithm is correct.
 */
void findEasterGregorian(int year, string &month, int &day)
{
    int a = year % 19;
    int b = year / 100;
    int c = year % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b+8) / 25;
    int g = (b-f+1) / 3;
    int h = (19*a + b - d - g + 15) % 30;
    int i = c / 4;
    int k = c % 4;
    int l = (32 + 2*e + 2*i - h - k) % 7;
    int m = (a + 11*h + 22*l) / 451;
    month = ((h + l - 7*m + 114) / 31) == 3 ? "March" : "April";
    int p = (h + l - 7*m + 114) % 31;
    day = p + 1;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    int year, day; string month; 
    while ( true ) {
        year = getInteger("Enter the year: ");
        if ( year == SENTINEL ) break;
        findEasterGregorian(year, month, day);
        cout << "In the year " << year << ", Easter happened on " << month << " " << day << "." << endl;
    }
    
    return 0;
}
