//
//  main.cpp
//  Exercise 1.3
//

#include <iostream>

using namespace std;

#pragma mark -
#pragma mark Declarations
int total(int, int);

#pragma mark -
#pragma mark Definitions
int total(int start, int stop)
{
    int total = 0;
    for ( int i=start; i <= stop; ++i )
    {
        total += i;
    }
    return total;
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    cout << total(1,100) << endl;  // ==> 5050
    
    return 0;
}
