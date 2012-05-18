//
//  main.cpp
//  Exercise 1.10
//

#include <iostream>
#include <string>

#define SENTINEL "0"

using namespace std;

#pragma mark -
#pragma mrk Declarations
string getLine(const string&);
void hailstone(int);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string line;
    cin >> line;
    return line;
}

void hailstone(int n)
{
    // terminate recursion at n=1
    if ( n == 1 ) return;
    
    // handle even case
    if ( n%2 == 0 )
    {
        int k = n/2;
        cout << n << " is even, so I divide it by 2 to get " << k << endl;
        hailstone(k);
    }
    
    // handle odd case
    else 
    {
        int k = 3 * n + 1;
        cout << n << " is odd, so I multiply by 3 and add 1 to get " << k << endl;
        hailstone(k);
    }
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    cout << "The Hailstone Sequence!" << endl;
    while ( true ) {
        string number = getLine("Enter a number: ");
        if ( number == SENTINEL ) break;
        int value1 = atoi(number.c_str());
        hailstone(value1);
    }
    
    return 0;
}
