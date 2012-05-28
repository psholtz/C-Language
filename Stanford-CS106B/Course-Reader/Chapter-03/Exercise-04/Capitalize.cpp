/*
 * File: Capitalize.cpp
 * --------------------------
 * Provides an implementation of the "capitalize()" procedure.
 */

#include <iostream>
#include <string>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#pragma mark -
#pragma mark Declarations
// put it in its own namespace, to prevent naming conflicts
namespace Custom {
    std::string capitalize(std::string str);
}

#pragma mark -
#pragma mark Definitions
std::string Custom::capitalize(std::string str)
{
    // handle the special case
    if ( str.length() == 0 ) { return ""; }
    
    // make the buffer of the first character
    std::stringstream buffer;
    int t = int(str[0]);
    if ( t >= 97 && t <= 122 ) 
    {
        t -= 32;
    }
    buffer << char(t);
    
    // make the buffer of the remaining characters
    for ( int i=1; i < str.length(); ++i ) 
    {
        int t = int(str[i]);
        if ( t >= 65 && t <= 90 ) 
        {
            t += 32; 
        }
        buffer << char(t); 
    }
    
    return buffer.str();
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    std::cout << Custom::capitalize("TEST") << std::endl;
    std::cout << Custom::capitalize("Test") << std::endl;
    std::cout << Custom::capitalize("test") << std::endl;
    std::cout << Custom::capitalize("tEsT") << std::endl;
    std::cout << Custom::capitalize("TeSt") << std::endl;
    
    std::cout << std::endl;
    
    std::cout << Custom::capitalize("BOOLEAN") << std::endl;
    std::cout << Custom::capitalize("boolean") << std::endl;
    
    return 0;
}
