//
//  main.cpp
//  Exercise 1.5
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma mark -
#pragma mrk Declarations
string getLine(const string&);
int maxElement(vector<int>);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string line;
    cin >> line;
    return line; 
}

int maxElement(vector<int> elements)
{
    int max = INT_MIN;
    vector<int>::iterator it;
    for ( it = elements.begin(); it != elements.end(); ++it ) 
    {
        max = (*it) > max ? (*it) : max; 
    }
    return max;
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    vector<int> integers;
    
    // capture integers
    cout << "This program finds the largest integer in a list." << endl;
    cout << "Enter 0 to signal the end of the list." << endl;
    while ( true ) {
        string number = getLine(" ? ");
        if ( number == "0" ) break;
        integers.push_back(atoi(number.c_str()));
    }
    
    // calculate the largest one
    int maximum = maxElement(integers);
    cout << "The largest value was " << maximum << "." << endl;
    
    return 0;
}
