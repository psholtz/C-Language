/*
 * File: Publisher.cpp
 * ---------------------- 
 * "Randomize" words as per publisher requirements.
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "filelib.h"
#include "random.h"

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
vector<string> processFile(vector<string> lines); 
char randomUpper();
char randomLower();

#pragma mark -
#pragma mark Function Definitions
vector<string> processFile(vector<string> lines)
{
    vector<string> modified;
    vector<string>::iterator it;
    string line; 
    stringstream buffer;
    
    for ( it = lines.begin(); it != lines.end(); ++it )
    {
        // construct the buffer 
        line = *it; char c; int d;
        for ( int i=0; i < line.length(); ++i )
        {
            c = (char)line[i];
            if ( isalpha(c) ) 
            {
                d = (int)c;
                if ( d >= 97 && d <= 122 ) 
                {
                    buffer << randomLower();
                }
                else if ( d >= 65 && d <= 90 )
                {
                    buffer << randomUpper();
                }
            }
            else 
            {
                buffer << c; 
            }
        }
        modified.push_back(buffer.str());
        
        // reset the buffer
        buffer.str(std::string());
    }
    
    return modified;
}

char randomUpper()
{
    return (char)randomInteger(65, 90);
}

char randomLower() 
{
    return (char)randomInteger(97, 122);
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    // get the input data from the user (i.e., filename)
    vector<string> lines;
    ifstream infile;
    promptUserForFile(infile, "Enter a filename: ");
    readEntireFile(infile, lines);
    infile.close();
    
    // process the file
    lines = processFile(lines);
    
    // output the results
    vector<string>::iterator it;
    for ( it = lines.begin(); it != lines.end(); ++it )
    {
        cout << (*it) << endl;
    }
    
    return 0;
}