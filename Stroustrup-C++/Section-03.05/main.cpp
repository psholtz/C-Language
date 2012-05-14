//
//  main.cpp
//  Project3
//

#include <iostream>
#include <string>

using namespace std; 

void f() 
{
    // string concatenation
    string s1 = "Hello";
    string s2 = "World!";
    string s3 = s1 + " " + s2;
    cout << s3 << endl;
    
    // substrings
    cout << s3.substr(3,5) << endl;
    cout << s3 << endl;
    
    // string replacement
    s3.replace(0,5,"Nicholas");
    cout << s3 << endl;
    
    // c-style strings
    printf("Name: %s\n",s3.c_str());
}

int main (int argc, const char * argv[])
{
    f();
    
    return 0;
}

