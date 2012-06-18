/*
 * File: Comments.cpp
 * ---------------------- 
 * Remove comments between an input stream and an output stream. 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
void copyStreams(string inputFilename, string outputFilename);      // random comment (for testing)
void removeComments(istream &is, ostream &os);                      // random comment (for testing)

#pragma mark -
#pragma mark Function Definitions
/*
 * Function: copyStreams(string inputFilename, string outputFilename);
 * -------------------------------------------------------------------
 * Open the files indicated by the argument, and copy the input
 * file stream to the output file stream, removing all comments
 * in the process. Signal error if we cannot open the input file.
 */
void copyStreams(string inputFilename, string outputFilename)
{
    // Open the input stream 
    ifstream infile(inputFilename.c_str());     /* This is one type of comment */
    if ( infile.fail() ) 
    {
        cout << "Could not open file: " + inputFilename << endl;
        return;
    }
    
    // Open the output stream
    ofstream outfile(outputFilename.c_str());
    
    // Remove the comments, stream-to-stream
    removeComments(infile, outfile);
    
    // Close the streams
    infile.close();
    outfile.close();
}

/*
 * Function: removeComments(istream &is, ostream &os);
 * --------------------------------------------------- 
 * Copy one stream to another, removing the comments in the process.
 * 
 * Define Comment1 to be the C-style comments.
 * Define Comment2 to be the C++-style comments.
 * 
 * There are various cases possible:
 * 
 *  (1)
 */
void removeComments(istream &is, ostream &os)
{
    string line, tmp;
    stringstream buffer, total;
    bool foundComment1 = false;     // comment 1 are "/*" style comments (<-- good test for parsing)
    bool foundComment2 = false;     // comment 2 are "//" style comments (<-- good test for parsing)
    bool emergencyHalt = false; 
    
    while ( !is.eof() )
    {
        // Read in another line
        getline(is,line);
        buffer.str(std::string());
        
        // Scan the string
        for ( int i=0; i < line.length(); ++i )
        {
            if ( i < line.length()-1 )  { if (line[i] == '/' && line[i+1] == '*') foundComment1 = true; }
            if ( i == line.length()-1 ) { if (line[i-1] == '*' && line[i] == '/') foundComment1 = false; }
            if ( !foundComment1 ) buffer << line[i];
        }
        if ( !foundComment1 ) buffer << '\n';
                
        // Copy to running buffer
        total << buffer.str();
    }
    
    // Remove final null char if there is one
    int len = total.str().length();
    if ( total.str()[len-1] == '\n' ) 
    {
        std::string tmp = total.str();
        total.str(std::string());
        total << tmp.substr(0,len-1);
    }
    
    // Write to output buffer
    os << total.str();
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    string inputFilename, outputFilename;
    while ( true ) {
        // get the input filename
        inputFilename = getLine("Enter input file: ");
        if ( inputFilename == SENTINEL ) break; 
        
        // get the output filename
        outputFilename = getLine("Enter output file: ");
        if ( outputFilename == SENTINEL ) break;
        
        // copy the streams
        copyStreams(inputFilename, outputFilename);
        
        cout << endl;
    }
    
    return 0;
}