
#include <iostream>
#include <string>

#include "error.h"
#include "direction.h"
#include "gmath.h"

using namespace std;

/* Main program */
int main()
{
  // test the direction library
  cout << "------------" << endl;
  cout << "leftFrom API" << endl;
  cout << "------------" << endl;

  cout << "Left from NORTH: " << directionToString(leftFrom(NORTH)) << endl;
  cout << "Left from WEST: " << directionToString(leftFrom(WEST)) << endl;
  cout << "Left from SOUTH: " << directionToString(leftFrom(SOUTH)) << endl;
  cout << "Left from EAST: " << directionToString(leftFrom(EAST)) << endl;

  cout << endl;

  cout << "-------------" << endl;
  cout << "rightFrom API" << endl;
  cout << "-------------" << endl;

  cout << "Right from NORTH: " << directionToString(rightFrom(NORTH)) << endl;
  cout << "Right from EAST: " << directionToString(rightFrom(EAST)) << endl;
  cout << "Right from SOUTH: " << directionToString(rightFrom(SOUTH)) << endl;
  cout << "Right from WEST: " << directionToString(rightFrom(WEST)) << endl;

  cout << endl;

  // test the math library
  cout << "------------" << endl;
  cout << "sin(degrees)" << endl;
  cout << "------------" << endl;

  cout << "sin(0) -> " << sinDegrees(0) << endl;
  cout << "sin(45) -> " << sinDegrees(45) << endl;
  cout << "sin(90) -> " << sinDegrees(90) << endl;
  cout << "sin(135) -> " << sinDegrees(135) << endl;
  cout << "sin(180) -> " << sinDegrees(180) << endl;
  cout << "sin(270) -> " << sinDegrees(270) << endl;
  cout << "sin(360) -> " << sinDegrees(360) << endl;

  cout << endl;

  cout << "------------" << endl;
  cout << "cos(degrees)" << endl;
  cout << "------------" << endl;

  cout << "cos(0) -> " << cosDegrees(0) << endl;
  cout << "cos(45) -> " << cosDegrees(45) << endl;
  cout << "cos(90) -> " << cosDegrees(90) << endl;
  cout << "cos(135) -> " << cosDegrees(135) << endl;
  cout << "cos(180) -> " << cosDegrees(180) << endl;
  cout << "cos(270) -> " << cosDegrees(270) << endl;
  cout << "cos(360) -> " << cosDegrees(360) << endl;

  cout << endl;

  cout << "------------" << endl;
  cout << "sin(radians)" << endl;
  cout << "------------" << endl;

  cout << "sin(0) -> " << sinDegrees(toDegrees(0)) << endl;
  cout << "sin(pi/4) -> " << sinDegrees(toDegrees(PI/4)) << endl;
  cout << "sin(pi/2) -> " << sinDegrees(toDegrees(PI/2)) << endl;
  cout << "sin(3pi/4) -> " << sinDegrees(toDegrees(3*PI/4)) << endl;
  cout << "sin(pi) -> " << sinDegrees(toDegrees(PI)) << endl;
  cout << "sin(3pi/2) -> " << sinDegrees(toDegrees(3*PI/2)) << endl;
  cout << "sin(2pi) -> " << sinDegrees(toDegrees(2*PI)) << endl;

  cout << endl;

  cout << "------------" << endl;
  cout << "cos(radians)" << endl;
  cout << "------------" << endl;

  cout << "cos(0) -> " << cosDegrees(toDegrees(0)) << endl;
  cout << "cos(pi/4) -> " << cosDegrees(toDegrees(PI/4)) << endl;
  cout << "cos(pi/2) -> " << cosDegrees(toDegrees(PI/2)) << endl;
  cout << "cos(3pi/4) -> " << cosDegrees(toDegrees(3*PI/4)) << endl;
  cout << "cos(pi) -> " << cosDegrees(PI) << endl;
  cout << "cos(3pi/2) -> " << cosDegrees(3*PI/2) << endl;
  cout << "cos(2pi) -> " << cosDegrees(2*PI) << endl;
  
  cout << endl;

  // test the error library
  if ( true ) error("Program is ending!");

  return 0;
}
