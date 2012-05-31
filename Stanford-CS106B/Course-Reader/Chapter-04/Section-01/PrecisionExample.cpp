/*
 * File: PrecisionExample.cpp
 * -------------
 */

#include <iostream>
#include <iomanip>
#include <cmath>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

//
// Constants 
// 
const double PI = 3.14159265358979323846;
const double SPEED_OF_LIGHT = 2.99792458E+8;
const double FINE_STRUCTURE = 7.2573525E-3;

using namespace std;

#pragma mark -
#pragma mark Declarations
void printPrecisionTable();

#pragma mark -
#pragma mark Definitions
void printPrecisionTable()
{
    cout << "+------+--------------+------------------+----------------+" << endl;
    cout << "| prec |      pi      |  speed of light  | fine-structure |" << endl;
    cout << "+------+--------------+------------------+----------------+" << endl;
    for ( int prec = 0; prec <= 6; prec += 2 )
    {
        cout << "|" << setw(4) << prec << "  |";
        cout << " " << setw(12) << setprecision(prec) << PI << " |";
        cout << " " << setw(16) << setprecision(prec) << SPEED_OF_LIGHT << " |";
        cout << " " << setw(14) << setprecision(prec) << FINE_STRUCTURE << " |";
        cout << endl;
    }
    cout << "+------+--------------+------------------+----------------+" << endl;    
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
        
    cout << uppercase << right;
    cout << "Default Format: " << endl << endl;
    printPrecisionTable();
    cout << endl << "Fixed Format: " << fixed << endl << endl;
    printPrecisionTable();
    cout << endl << "Scientific Format: " << scientific << endl << endl;
    printPrecisionTable();
    
    return 0;
}