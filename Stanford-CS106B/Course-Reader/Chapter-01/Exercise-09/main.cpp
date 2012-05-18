//
//  main.cpp
//  Exercise 1.9
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#define SENTINEL "0"

using namespace std;

#pragma mark -
#pragma mrk Declarations
string getLine(const string&);
vector<int> factor(int);
void display(vector<int>);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string line;
    cin >> line;
    return line;
}

vector<int> factor(int n) 
{
    int k = n;
    vector<int> factors;
    
    // do bounds checking on n=2
    if ( n < 2 ) { return factors; }
    
    // first get the 2s out of the way
    while ( k % 2 == 0 ) {
        factors.push_back(2);
        k /= 2;
    }
    
    // then check the rest of the numbers, 
    // but skip 2 each step for efficiency
    for ( int i=3; i <= n; i += 2 )
    {
        while ( k % i == 0 ) {
            factors.push_back(i);
            k /= i;
        }
    }
    
    return factors;
}

void display(vector<int> numbers)
{
    int count = 0;
    size_t len = numbers.size();
    vector<int>::iterator it;
    for ( it = numbers.begin(); it != numbers.end(); ++it ) 
    {
        cout << (*it);
        count++;
        if ( count < len ) {
            cout << " x ";
        }
    }
    cout << endl;
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    cout << "This program factors a number." << endl;
    while ( true ) {
        string number = getLine("Enter a positive integer: ");
        if ( number == SENTINEL ) break;
        int value1 = atoi(number.c_str());
        vector<int> value2 = factor(value1);
        display(value2);
    }
    
    return 0;
}
