//
//  main.cpp
//  Exercise 1.4
//

#include <iostream>
#include <string>

using namespace std;

#pragma mark -
#pragma mrk Declarations
string getLine(const string&);
int sum(int);
int nth_odd(int);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string line;
    cin >> line;
    return line; 
}

int sum(int n)
{
    int sum = 0;
    for (int i=0; i < n; ++i ) 
    {
        sum += nth_odd(i);
    }
    return sum;
}

int nth_odd(int n)
{
    return 2*n + 1;
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    while ( true ) {
        string number = getLine("Enter positive integer: ");
        if ( number == "" ) break;
        int value1 = atoi(number.c_str());
        cout << sum(value1) << endl;
    }
    
    return 0;
}