/*
 * File: DefaultExtension.cpp
 * ---------------------- 
 * Implement a function that adds a default extension to filenames.
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "filelib.h"

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
// use a namespace so we don't collide with the Stanford libraries
namespace Custom {
    std::string defaultExtension(std::string filename, std::string ext);
}

#pragma mark -
#pragma mark Function Definitions
std::string Custom::defaultExtension(std::string filename, std::string ext)
{
    std::string root = getRoot(filename);
    std::string extension = getExtension(filename);
    
    if ( extension.length() == 0 )
    {
        return filename+ext;
    }
    else
    {
        if ( ext.length() > 0 ) 
        {
            bool usesStar = false; int index = -1;
            for ( int i=0; i < ext.length()-1; ++i ) 
            {
                if ( ext[i] == '*' && ext[i+1] == '.' )
                {
                    index = i;
                    usesStar = true;
                    break; 
                }
            }
            if ( usesStar ) {
                return root + ext.substr(index+1);
            }
        }
        return filename;
    }
 
    // Error condition
    return "";
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    cout << Custom::defaultExtension("Shakaespeare", ".txt") << endl;
    cout << Custom::defaultExtension("library.h", ".cpp") << endl;
    cout << Custom::defaultExtension("library.h", "*.cpp") << endl;
    
    return 0;
}