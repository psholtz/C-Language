//
//  main.cpp
//  Exercise 1.6
//

#include <iostream>
#include <string>
#include <vector>

#define SENTINEL "0"

using namespace std;

struct Numbers {
    int largest;
    int next_largest;
};

#pragma mark -
#pragma mrk Declarations
string getLine(const string&);
Numbers getMaximumNumbers(vector<int>);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string line;
    cin >> line;
    return line; 
}

Numbers getMaximumNumbers(vector<int> elements)
{
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    vector<int>::iterator it;
    for ( it = elements.begin(); it != elements.end(); ++it )
    {
        if ( (*it) > max1 ) 
        {
            max2 = max1 > max2 ? max1 : max2;
            max1 = (*it);
        }
    }
    
    // return the structure
    Numbers numbers;
    numbers.largest = max1;
    numbers.next_largest = max2;
    return numbers;
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
        if ( number == SENTINEL ) break;
        integers.push_back(atoi(number.c_str()));
    }
    
    // calculate the two largest integers
    Numbers numbers = getMaximumNumbers(integers);
    cout << "The largest value was " << numbers.largest << "." << endl;
    cout << "The second largest value was " << numbers.next_largest << "." << endl;
    
    return 0;
}