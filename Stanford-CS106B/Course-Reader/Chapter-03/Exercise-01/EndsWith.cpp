/*
 * File: EndsWith.cpp
 * --------------------
 * Return true if the string ends with a predefined suffix. 
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "strlib.h"

#define SENTINEL 0

//
// Note that we need to define a "custom" namespace, 
// to avoid conflicting with the identically named
// functions in the Stanford C++ Libraries.
//

#pragma mark -
#pragma mark Function Prototypes
namespace Custom {
    bool endsWith(std::string,std::string);
    bool endsWith(std::string,char);
}

#pragma mark -
#pragma mark Function Definitions
bool Custom::endsWith(std::string target,std::string suffix)
{
    int len = suffix.length();
    return target.substr(target.length() - len,suffix.length()) == suffix;
}

bool Custom::endsWith(std::string target,char suffix)
{    
    return target[target.length()-1] == suffix;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    std::string line1, line2;
    bool value;
    while ( true ) {
        //
        // Get information from the user
        //
        line1 = getLine("Enter target word: ");
        if ( line1 == "" ) break;
        line2 = getLine("Enter suffix: ");
        if ( line2 == "" ) break;
        
        //
        // Suffix cannot be longer than target string(!)
        //
        if ( line2.length() > line1.length() ) 
        {
            error("Suffix cannot be longer than target string: [" + line1 + "], [" + line2 + "]");
        }
        
        // 
        // Perform the string calculation
        //
        if ( line2.length() == 1 ) 
        {
            value = Custom::endsWith(trim(line1), line2[0]);
        }
        else
        {
            value = Custom::endsWith(trim(line1), line2);
        }
        
        // 
        // Output the answer
        //
        if (value) 
        {
            std::cout << "Yes" << std::endl;
        }
        else
        {
            std::cout << "No" << std::endl;
        }
 
        std::cout << std::endl;
    }

    return 0;
}