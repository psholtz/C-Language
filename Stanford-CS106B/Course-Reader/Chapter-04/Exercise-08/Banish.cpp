/*
 * File: Banish.cpp
 * ---------------- 
 * "Banish" offending or censored words from a text.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// Stanford C++ Libraries
#include "console.h"
#include "simpio.h"
#include "filelib.h"

#define SENTINEL ""

using namespace std;

#pragma mark -
#pragma mark Function Prototypes
void readFile(string inputFilename);
vector<string> banishLetters(vector<string> lines, string letters);
string removeLetters(string target, string letters);
string removeLettersIter(string target, string letters, int index); 
void writeFile(string outputFilename,vector<string> lines);

#pragma mark -
#pragma mark Function Definitions
/*
 * function: readFile(string inputFilename, vector<string>& lines);
 * ---------------------------------------------------------------- 
 * Open the file and read the contents into the vector<string> collection.
 * 
 * intputFilename: name of file to open; signal error if cannot open
 * lines: collection of string into which to read the file.
 */
void readFile(string inputFilename, vector<string>& lines)
{
    // read the input file
    ifstream infile(inputFilename.c_str());
    if ( infile.fail() ) 
    {
        cout << "Could not open file: " << inputFilename << endl;
    }
    else 
    {
        readEntireFile(infile, lines);
    }
    infile.close();
}

/*
 * Function: vector<string> banishLetters(vector<string> lines, string letters)
 * ------------------------------------------------------------- 
 * Iterate through the strings in the collection "lines". If, in any of 
 * these strings, any of the characters in "letters" appears, remove
 * these banished characters. Return a new collection (vector<string>)
 * of the modified (i.e., banished) strings.
 * 
 * lines: collection of strings to scan for banishment.
 * letters: collection of letters we are going to banish.
 * Return: vector<string> collection of strings which have been modified 
 *         to reflect the banishment.
 */
vector<string> banishLetters(vector<string> lines, string letters)
{
    vector<string> answer; string tmp;
    for ( int i=0; i < lines.size(); ++i ) 
    {
        tmp = lines[i];
        tmp = removeLetters(tmp, letters);
        answer.push_back(tmp);
    }
    return answer; 
}

/*
 * Function: string removeLetters(string target, string letters);
 * -------------------------------------------------------------- 
 * Remove any letter appearing in "letters" from the string "target".
 * This function is the "entry point" into the recursive procedure that removes the letters.
 * 
 * target: string from which to remove letters.
 * letters: collection of letters to remove from target.
 * Return: "string" representing the target string with the specified letters removed.
 */
string removeLetters(string target, string letters)
{
    return removeLettersIter(target, letters, 0);
}

/*
 * Function: string removeLettersIter(string target, string letters, int index); 
 * ----------------------------------------------------------------------------- 
 * Remove any letter appearing in "letters" from the string "target".
 * This function provides the recursive implementation of the procedure that removes the letters.
 * 
 * target: string from which to remove letters.
 * letters: collection of letters to remove from target.
 * Return: "string" representing the target string with the specified letters removed.
 */
string removeLettersIter(string target, string letters, int index)
{
    for ( int i=0; i < target.length(); ++i ) 
    {
        for ( int j=0; j < letters.length(); ++j ) 
        {
            if ( target[i] == letters[j] )
            {
                return removeLettersIter(target.substr(0,i) + target.substr(i+1), letters, index);
            }
        }
    }
    return target;
}

/*
 * Function: writeFile(string outputFilename, vector<string> lines);
 * ----------------------------------------------------------------- 
 * Write the modified (i.e., banished) strings back to an output file.
 * 
 * outputFilename: name of which in which to write results.
 * lines: collection of strings to be written to disk.
 */
void writeFile(string outputFilename, vector<string> lines)
{
    ofstream outfile(outputFilename.c_str());
    vector<string>::iterator it;
    for ( it = lines.begin(); it != lines.end(); ++it )
    {
        outfile << (*it) << endl;
    }
    outfile.close();
}

#pragma mark -
#pragma mark Main Driver Loop
int main() {
    
    string inputFilename, outputFilename, lettersToBanish;
    while ( true ) {
        // get the input file
        inputFilename = getLine("Input file: ");
        if ( inputFilename == SENTINEL ) break;
        
        // get the output file
        outputFilename = getLine("Output file: ");
        if ( outputFilename == SENTINEL ) break;
        
        // get the letters to banish
        lettersToBanish = getLine("Letters to banish: ");
        if ( lettersToBanish == SENTINEL ) break;
        
        // do the processing
        vector<string> lines;
        readFile(inputFilename,lines);
        lines = banishLetters(lines, lettersToBanish);
        writeFile(outputFilename, lines); 
    
        cout << endl;
    }

    return 0;
}
