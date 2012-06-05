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
void copyStreams(string inputFilename, string outputFilename);
void removeComments(istream &is, ostream &os);

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
    string line;
    stringstream buffer;
    bool insideComment1 = false; 
    while ( !is.eof() )
    {
        insideComment1 = false;
        getline(is,line);
        for ( int i=0; i < line.length()-1; ++i ) 
        {
            if ( line[i] == '/' && line[i+1] == '/' )
            {
                insideComment1 = true;
            }
            if ( !insideComment1 )
            {
                buffer << line[i];
            }
        }
        
        os.write(buffer.str().c_str(), buffer.str().length());

        // reset the buffer
        buffer.str(std::string());
        
//        // test for whether we are done
//        int ch = is.get();
//        if ( ch == EOF ) break;
//        
//        // test for the C++ style comments
//        if ( foundSlash && ch == '/' )
//        {
//            insideComment1 = true; 
//        }
//        if ( foundSlash && ch == '\n' ) 
//        {
//            insideComment1 = false;
//        }
//        foundSlash = ch == '/' ? true : false;
//        
//        // write if we are not in a comment
//        if ( !insideComment1 ) 
//            os.put(ch);
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
        
        copyStreams(inputFilename, outputFilename);
        cout << endl;
    }

    return 0;
}