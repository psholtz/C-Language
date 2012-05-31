/*
 * File: ShowFileContents.cpp
 * --------------------------
 * This program displays the contents of a file chosen by the user.
 */

#include <iostream>
#include <fstream>
#include <string>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

//
// Constants 
// 

using namespace std;

#pragma mark -
#pragma mark Declarations
string promptUserForFile(ifstream &infile, string prompt="");

#pragma mark -
#pragma mark Definitions
string promptUserForFile(ifstream &infile, string prompt)
{
    while ( true ) {
        cout << prompt;
        string filename;
        getline(cin, filename); 
        infile.open(filename.c_str());
        if ( !infile.fail() ) return filename;
        infile.clear();
        cout << "Unable to open that file. Try again." << endl;
        if ( prompt == "" ) prompt = "Input file: ";
    }
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
        
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    while ( true ) {
        int ch = infile.get();
        if ( ch == EOF ) break;
        cout.put(ch);
    }
    infile.close();
    
    return 0;
}