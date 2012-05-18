//
//  main.cpp
//  Exercise 1.1
//

#include <iostream>
#include <string>

using namespace std; 

#pragma mark -
#pragma mark Declarations
string getLine(const string &);
float stringToFloat(const string &s);
float CToF(float temp);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string value;
    cin >> value;
    return value; 
}

float stringToFloat(const string &t)
{
    return atof(t.c_str());
}

float CToF(float temp)
{
    return (9.0/5.0)*temp + 32.0;
}

#pragma mark -
#pragma mark Main Driver Loop
int main (int argc, const char * argv[])
{
    while ( true ) 
    {
        string value = getLine("Enter Temperature: ");
        if ( value == "" ) break;
        float temp1 = stringToFloat(value);
        float temp2 = CToF(temp1);
        cout << temp1 << "C -> " << temp2 << "F" << endl;
    }
    
    return 0;
}

