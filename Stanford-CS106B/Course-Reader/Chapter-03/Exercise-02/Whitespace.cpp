/*
 * File: Whitespace.cpp
 * --------------------------
 * Provides an implementation of the "trim()" procedure.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
 
// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#pragma mark -
#pragma mark Declarations
namespace Custom {
    std::string trim(std::string str);  
};

#pragma mark -
#pragma mark Definitions
// Put it in its own namespace, to prevent conflicts w/ Stanford Libraries, etc.
std::string Custom::trim(std::string str)
{
    // handle special case
    if ( str.length() == 0 ) { return ""; }
    
    // go "forward" to first non-whitespace
    int index1 = 0;
    while ( index1 < str.length() && isspace(str[index1]) ) 
    {
        index1++;   
    }
    
    // go "backward" to first non-whitespace
    int index2 = str.length()-1;
    while ( index >= 0 && isspace(str[index2]) )
    {
        index2--;
    }      
    
    return str.substr(index1, index2-index1+1);
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    std::vector<std::string> test;
    test.push_back("  one  ");
    test.push_back("two");
    test.push_back("three  ");
    test.push_back("    four");
    test.push_back("  and this is a sentence.  ");
    test.push_back("");
    test.push_back("     ");
    
    for ( int i=0; i < test.size(); ++i )
    {
        std::cout << "Testing --> ::" << Custom::trim(test[i]) << "::" << std::endl;
    }
    
    return 0;
}
