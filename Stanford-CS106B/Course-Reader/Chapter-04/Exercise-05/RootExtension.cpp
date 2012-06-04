/*
 * File: RootExtension.cpp
 * ---------------------- 
 * Parse a filename into its root and extension.
 */

#include <iostream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
std::string getRoot(std::string filename);
std::string getExtension(std::string filename);

#pragma mark -
#pragma mark Function Definitions
std::string getRoot(std::string filename)
{
    // see if we can find the file extension
    int index = -1;
    for ( int i=0; i < filename.length(); ++i ) 
    {
        if ( filename[i] == '.' ) 
        {
            index = i;
            break;
        }
    }
    
    // return up to the file extension
    if ( index != -1 )
    {
        return filename.substr(0,index);
    }
    return filename;
}

std::string getExtension(std::string filename)
{
    // see if we can find the file extension
    int index = -1;
    for ( int i=0; i < filename.length(); ++i ) 
    {
        if ( filename[i] == '.' ) 
        {
            index = i;
            break;
        }
    }
    
    // return up to the file extens
    if ( index != -1 ) 
    {
        return filename.substr(index);
    }
    
    return filename;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    string filename, root, extension;
    while ( true ) {
        /// get the filename
        filename = getLine("Enter a filename: ");
        if ( filename == SENTINEL ) break;
        
        // perform the root/extension calculation
        root = getRoot(filename);
        extension = getExtension(filename);
        cout << "Root: " << root << endl;
        cout << "Extension: " << extension << endl;
        cout << endl;
    }
    
    return 0;
}