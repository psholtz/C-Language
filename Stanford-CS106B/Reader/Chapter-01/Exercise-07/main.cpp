//
//  main.cpp
//  Exercise 1.6
//

#include <iostream>
#include <string>
#include <vector>

#define SENTINEL "-1"

using namespace std;

#pragma mark -
#pragma mrk Declarations
string getLine(const string&);
int getTotal(vector<int>);
float getAverage(int,int);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string line;
    cin >> line;
    return line; 
}

float getAverage(int total, int n)
{
    return ((float)total) / ((float)n);
}

int getTotal(vector<int> elements)
{
    int total = 0;
    vector<int>::iterator it;
    for ( it = elements.begin(); it != elements.end(); ++it )
    {
        total += (*it);
    }
    return total; 
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    vector<int> integers;
    
    // capture integers
    int count = 0;
    cout << "This program finds the average of a list of integers." << endl;
    cout << "Enter -1 to signal the end of the list." << endl;
    while ( true ) {
        string number = getLine(" ? ");
        if ( number == SENTINEL ) break;
        integers.push_back(atoi(number.c_str()));
        count++;
    }
    
    int total = getTotal(integers);
    float average = getAverage(total,count); 

    cout << "The average value is: " << average << "." << endl;
    
    return 0;
}