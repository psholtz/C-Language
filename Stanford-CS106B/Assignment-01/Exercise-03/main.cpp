//
//  main.cpp
//  Assignment3
//

#include <iostream>

using namespace std;

#pragma mark -
#pragma mark Declarations
int c(int,int);
void pyramid();

#pragma mark -
#pragma mark Definitions
int c(int n, int k)
{
    if ( n == 0 ) return 1;
    if ( k == n || k == 0 ) return 1;
    return c(n-1,k-1) + c(n-1,k);
}

void pyramid()
{
    // closure for adding spaces (for visual effect)
    void (^add_spaces)(int) = ^(int n) {
        for ( int i=0; i < (10-n); ++i ) { cout << " "; }
    }; 
    
    // main loop for printing out the pyramid
    for ( int n=0; n < 10; ++n ) 
    {
        add_spaces(n);
        for ( int k=0; k <= n; ++k ) 
        {
            cout << c(n,k) << " ";
        }
        cout << endl; 
    }
}

#pragma mark -
#pragma mark Main Driver Loop
int main (int argc, const char * argv[])
{
    // first row
    cout << c(0,0) << endl;
    cout << endl;
    
    // second row
    cout << c(1,0) << endl;
    cout << c(1,1) << endl;
    cout << endl;
    
    // third row
    cout << c(2,0) << endl;
    cout << c(2,1) << endl;
    cout << c(2,2) << endl;
    cout << endl;
    
    // fourth row
    cout << c(3,0) << endl;
    cout << c(3,1) << endl;
    cout << c(3,2) << endl;
    cout << c(3,3) << endl;
    cout << endl;
    
    // fifth row
    cout << c(4,0) << endl;
    cout << c(4,1) << endl;
    cout << c(4,2) << endl;
    cout << c(4,3) << endl;
    cout << c(4,4) << endl;
    
    // sixth row
    cout << c(5,0) << endl;
    cout << c(5,1) << endl;
    cout << c(5,2) << endl;
    cout << c(5,3) << endl;
    cout << c(5,4) << endl;
    cout << c(5,5) << endl;
    
    cout << endl;
    pyramid();
    cout << endl;
    
    return 0;
}

