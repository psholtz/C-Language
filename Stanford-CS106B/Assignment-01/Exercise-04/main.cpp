//
//  main.cpp
//  Assignment 1.4
//

#include <iostream>
#include <string>

using namespace std; 

#pragma mark -
#pragma mark Declarations
string intToString(int);
int stringToInt(string);
char _intHelper(int);
int _stringHelper(char);

#pragma mark -
#pragma mark Definitions
string intToString(int n) 
{
    // handle special cases
    if ( n == 0 ) return "0";
    if ( n < 0 ) return "-" + intToString(abs(n));
    
    // recursive implementation
    return n < 10 ? string() + _intHelper(n) : intToString(n/10) + (string() + _intHelper(n%10));
}

int stringToInt(string s) 
{
    // handle special cases
    size_t len = s.length(); 
    if ( len == 1 && s[0] == '0' ) { return 0; }
    if ( len == 2 && s[0] == '-' ) { return (-1) * stringToInt(s.substr(1)); }
    
    // if the string is < 10
    if ( len == 1 ) { return _stringHelper(s[0]); }
    
    // handle the general case recursively
    return 10 * stringToInt(s.substr(0,len-1)) + _stringHelper(s[len-1]);
}

char _intHelper(int n) 
{
    return (char)(48+n);
}

int _stringHelper(char c) 
{
    return (int)c - 48;
}

#pragma mark -
#pragma mark Driver Loop
int main (int argc, const char * argv[])
{    
    string s1 = intToString(100);
    string s2 = intToString(99);
    string s3 = intToString(101);
    string s4 = intToString(1000999);
    string s5 = intToString(25);
    string s6 = intToString(0);
    string s7 = intToString(-5);
    
    cout << "-----------" << endl;
    cout << "intToString" << endl;
    cout << "-----------" << endl;
    
    cout << s1 << endl;  // ==> 100
    cout << s2 << endl;  // ==> 99
    cout << s3 << endl;  // ==> 101
    cout << s4 << endl;  // ==> 1000999
    cout << s5 << endl;  // ==> 25
    cout << s6 << endl;  // ==> 0
    cout << s7 << endl;  // ==> -5
    
    cout << endl;
    
    int i1 = stringToInt("100");
    int i2 = stringToInt("99");
    int i3 = stringToInt("101");
    int i4 = stringToInt("1000999");
    int i5 = stringToInt("25");
    int i6 = stringToInt("0");
    int i7 = stringToInt("-5");

    cout << "-----------" << endl;
    cout << "stringToInt" << endl;
    cout << "-----------" << endl;
    
    cout << i1 << endl;  // ==> 100
    cout << i2 << endl;  // ==> 99
    cout << i3 << endl;  // ==> 101
    cout << i4 << endl;  // ==> 1000999
    cout << i5 << endl;  // ==> 25
    cout << i6 << endl;  // ==> 0
    cout << i7 << endl;  // ==> -5

    return 0;
}
