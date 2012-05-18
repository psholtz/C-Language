//
//  main.cpp
//  Exercise 1.2
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std; 

struct English {
    int feet;
    float inches;
};

#pragma mark -
#pragma mark Declarations
string getLine(const string &);
float metersToInches(float);
English inchesToEnglish(float);

#pragma mark -
#pragma mark Definitions
string getLine(const string& prompt)
{
    cout << prompt;
    string line;
    cin >> line;
    return line;
}

float metersToInches(float m)
{
    return m/0.0254;
}

English inchesToEnglish(float inches)
{
    English e;
    e.feet = (int)(inches/12);
    e.inches = ceilf((inches - e.feet*12) * 100) / 100; // round to 2 decimal places
    return e;
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    while ( true ) 
    {
        string value = getLine("Enter length in meters: ");
        if ( value == "" ) break;
        float length1 = atof(value.c_str());
        float length2 = metersToInches(length1);
        English length3 = inchesToEnglish(length2);
        cout << length1 << " meters -> " << length3.feet << " feet, " << length3.inches << " inches" << endl;
    }
    
    return 0;
}

