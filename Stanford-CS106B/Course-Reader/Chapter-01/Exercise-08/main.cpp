//
//  main.cpp
//  Exercise 1.8
//

#include <iostream>
#include <string>
#include <math.h>

#define SENTINEL "0"

using namespace std;

#pragma mark -
#pragma mrk Declarations
string getLine(const string&);
int reverse(int,size_t);
int reverse_recur(int,int,size_t);

#pragma mark -
#pragma mark Definitions
string getLine(const string &prompt)
{
    cout << prompt;
    string line;
    cin >> line;
    return line;
}

int reverse(int n,size_t len)
{
    return reverse_recur(n,0,len);
}

int reverse_recur(int n, int k, size_t len)
{
    return n < 10 ? n : pow(10,len-k-1) * (n%10) + reverse_recur(n/10,k+1,len);
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{
    cout << "This program reverses the digits in an integer." << endl;
    while ( true ) {
        string number = getLine("Enter a positive integer: ");
        if ( number == SENTINEL ) break;
        int value1 = atoi(number.c_str());
        int value2 = reverse(value1,number.length());
        cout << "The reversed integer is " << value2 << endl;
    }
    
    return 0;
}
