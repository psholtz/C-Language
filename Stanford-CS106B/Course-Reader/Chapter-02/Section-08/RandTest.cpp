/*
 * File: RandTest.cpp
 * ------------------
 * This program tests the random number generator in C++ and produces
 * the values used in the examples in the text.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int N_TRIALS = 10;

int main()
{
  cout << "On this computer, RAND_MAX is " << RAND_MAX << endl;
  cout << "The first " << N_TRIALS << " calls to rand: " << endl;
  for ( int i=0; i < N_TRIALS; ++i ) {
    cout << setw(10) << rand() << endl;
  }
  return 0;
}
