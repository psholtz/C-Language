//
//  main.cpp
//  Assignment1.1
//

#include <iostream>
#include <string>

using namespace std;

enum { kHeads, kTails };

#pragma mark- 
#pragma mark Declarations
int flip();
string label(int);

#pragma mark -
#pragma mark Definitions
int flip()
{
    return rand()%2 == 0 ? kHeads : kTails;
}

string label(int value)
{
    return value == kHeads ? "Heads.." : "Tails..";
}

#pragma mark -
#pragma mark Main Driver
int main (int argc, const char * argv[])
{
    // seed PRNG 
    srand( (unsigned int)time(NULL) );
    
    // declare variables
    int headCount = 0, tossCount = 0; 
    int flipValue = -1; 

    // run loop
    while ( headCount < 3 ) 
    {
        flipValue = flip();
        
        headCount = (flipValue == kHeads) ? (headCount + 1) : 0;
        ++tossCount;
        
        cout << label(flipValue) << endl;
    }

    // print answers
    cout << "It took " << tossCount << " to get " << headCount << " consecutive heads." << endl;
    
    return 0;
}

