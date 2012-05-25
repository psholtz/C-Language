//
//  main.cpp
//  BlankProject
//

#include <iostream>

#include "combinatorics.h"

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL 0

using namespace std;

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    int n, k;
    while ( true ) {
        n = getInteger("Enter n: ");
        k = getInteger("Enter k: ");
        if ( n == SENTINEL && k == SENTINEL ) break;
        cout << "There are C(n,k) = " << combinations(n,k) << " combinations." << endl;
        cout << "There are P(n,k) = " << permutations(n,k) << " permutations." << endl;
        cout << endl;
    }
    
    return 0;
}