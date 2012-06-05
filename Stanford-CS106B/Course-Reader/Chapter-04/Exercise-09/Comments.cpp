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
    ifstream infile(inputFilename.c_str());
    if ( infile.fail() ) 
    {
        cout << "Could not open file: " + inputFilename << endl;
        return;
    }
    
    ofstream outfile(outputFilename.c_str());
    removeComments(infile, outfile);
}

/*
 * Function: removeComments(istream &is, ostream &os);
 * --------------------------------------------------- 
 * Copy one stream to another, removing the comments
 * in the process.
 */
void removeComments(istream &is, ostream &os)
{
    string line, tmp;
    stringstream buffer;
    bool c1 = false, c2 = false, w1 = true;
    while ( !is.eof() )
    {
        c2 = false; w1 = true;
        getline(is,line);
        for ( int i=0; i < line.length(); ++i )
        {
            if ( i < line.length()-1 )
            {
                if ( line[i] == '/' && line[i+1] == '/' ) c2 = true;
            }
            if ( !c2 ) buffer << (char)line[i]; 
        }
        if ( c2 ) 
        {
            bool foundChar = false; 
            tmp = buffer.str();
            for ( int i=0; i < tmp.length(); ++i ) 
            {
                if ( !isspace(tmp[i]) ) foundChar = true;
            }
            w1 = foundChar;
        }
            
        if ( w1 ) {
            cout << buffer.str() << endl;
        }
        buffer.str(std::string());
    }
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