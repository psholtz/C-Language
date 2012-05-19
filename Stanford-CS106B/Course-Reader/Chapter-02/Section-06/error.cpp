/*
 * File: error.cpp
 * --------------- 
 * This file implements the error.h interface.
 */

#include <iostream>
#include <cstdlib>
#include "error.h"

using namespace std;

/*
 * Implementation notes: error
 * --------------------------- 
 * This function writes out the error message to the cerr stream and
 * then exits the program. The EXIT_FAILURE constant is defined in
 * <cstdlib> to represent a standard failure code.
 */

void error(string msg)
{
  cerr << msg << endl;
  exit(EXIT_FAILURE);
}
