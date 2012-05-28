/*
 * File: Substring.cpp
 * --------------------------
 * Provides an implementation of the "substr()" procedure.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "error.h"

#pragma mark -
#pragma mark Declarations
// put it in its own namespace, to prevent naming conflicts
namespace Custom {
    std::string substr(std::string str, int pos);
    std::string substr(std::string str, int pos, int n);
};

#pragma mark -
#pragma mark Definitions
std::string Custom::substr(std::string str, int pos)
{
    return Custom::substr(str, pos, str.length()-pos);
}

std::string Custom::substr(std::string str, int pos, int n)
{
    // do the error checking
    if ( pos > str.length()-1 )
    {
        std::stringstream s;
        s << "Position is beyond string length! pos=" << pos << ", length=" << str.length();
        error(s.str());
    }
    
    // build the buffer
    std::stringstream buffer;
    for ( int i=0; i < n; ++i ) 
    {
        if ( pos + i < str.length() )
        {
            buffer << str[pos+i];
        }
    }
    
    return buffer.str();
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    std::vector<std::string> test;
    test.push_back("test");
    
    //std::cout << Custom::substr(test[0], 4, 1) << std::endl; // triggers error, which is what we want
    std::cout << "Test 1: " << Custom::substr(test[0], 0, 0) << std::endl;
    std::cout << "Test 2: " << Custom::substr(test[0], 0, 1) << std::endl;
    std::cout << "Test 3: " << Custom::substr(test[0], 0, 2) << std::endl;
    std::cout << "Test 4: " << Custom::substr(test[0], 0, 3) << std::endl;
    std::cout << "Test 5: " << Custom::substr(test[0], 0, 4) << std::endl;
    std::cout << "Test 6: " << Custom::substr(test[0], 0, 5) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test 7: " << Custom::substr(test[0], 1, 0) << std::endl;
    std::cout << "Test 8: " << Custom::substr(test[0], 1, 1) << std::endl;
    std::cout << "Test 9: " << Custom::substr(test[0], 1, 2) << std::endl;
    std::cout << "Test 10: " << Custom::substr(test[0], 1, 3) << std::endl;
    std::cout << "Test 11: " << Custom::substr(test[0], 1, 4) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test 12: " << Custom::substr(test[0], 2, 0) << std::endl;
    std::cout << "Test 13: " << Custom::substr(test[0], 2, 1) << std::endl;
    std::cout << "Test 14: " << Custom::substr(test[0], 2, 2) << std::endl;
    std::cout << "Test 15: " << Custom::substr(test[0], 2, 3) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test 16: " << Custom::substr(test[0], 3, 0) << std::endl;
    std::cout << "Test 17: " << Custom::substr(test[0], 3, 1) << std::endl;
    std::cout << "Test 18: " << Custom::substr(test[0], 3, 2) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Test 19: " << Custom::substr(test[0], 0) << std::endl;
    std::cout << "Test 20: " << Custom::substr(test[0], 1) << std::endl;
    std::cout << "Test 21: " << Custom::substr(test[0], 2) << std::endl;
    std::cout << "Test 22: " << Custom::substr(test[0], 3) << std::endl;
    
    return 0;
}
