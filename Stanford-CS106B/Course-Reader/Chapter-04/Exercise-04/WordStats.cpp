/*
 * File: WordStats.cpp
 * ---------------------- 
 * Read a file and display word count statistics.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iomanip>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
void readFile(string filename);
int decimalPlaces(int); 

#pragma mark -
#pragma mark Function Definitions
/*
 * Function: readFile(string filename);
 * ------------------------------------ 
 * Read the file and print out the file statistics.
 */
void readFile(string filename)
{
    
    ifstream infile;
    infile.open(filename.c_str());
    if ( infile.fail() ) 
    {
        cout << "Could not file file: " << filename << endl;
    }
    else 
    {
        // collect the statistics
        int wordCount = 0, charCount = 0, lineCount = 0; 
        bool inWord = false; 
        char ch;
        while ( (ch = infile.get()) != EOF )
        {
            if  ( isspace(ch) ) 
            {
                if ( inWord )
                {
                    wordCount++;
                }
                inWord = false; 
            }
            else 
            {
                inWord = true;
            }
            charCount++;
            
            if ( ch == '\n' ) lineCount++;
        }
        // charCount will be the largest so use that as a metric to size the fields
        int size = decimalPlaces(charCount);
        
        // display the information
        cout << "Char count: " << right << setw(size) << charCount << endl;
        cout << "Word count: " << right << setw(size) << wordCount << endl;
        cout << "Line count: " << right << setw(size) << lineCount << endl;
    }
    infile.close(); 
}

/*
 * Function: int decimalPlaces(int number);
 * ---------------------------------------- 
 * Return the "size" of the int, e.g., if number is 
 * "9" we return "1", if number is "415" we return "3", 
 * if number is "1000000" we return "7".
 */
int decimalPlaces(int number)
{
    int answer = 0;
    int tmp = number;
    while ( tmp > 0 ) 
    {
        tmp /= 10; 
        answer++;
    }
    return answer;
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    string filename;
    while ( true ) {
        filename = getLine("Enter a filename: ");
        if ( filename == SENTINEL ) break;
        readFile(filename);
        cout << endl;
    }
    
    return 0;
}