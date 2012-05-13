//
//  tester.h
//  Chapter2.7
//
//  Created by Paul Sholtz on 5/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef tester_h
#define tester_h

#include "Complex.h"
#include "Rational.h"

using namespace std;

void testRational()
{
    cout << " " << endl;
    
    Rational r1(1,2);
    Rational r2(2,3);
    Rational r3(-1,2);
    Rational r4(1,-2);
    Rational r5(-1,-2);
    Rational r6(2,4);
    Rational r7(10,15);
    Rational r8(1,3);
    
    cout << r1 << endl; // ==> 1/2
    cout << r2 << endl; // ==> 2/3
    cout << r3 << endl; // ==> -1/2
    cout << r4 << endl; // ==> -1/2
    cout << r5 << endl; // ==> 1/2
    cout << r6 << endl; // ==> 1/2
    cout << r7 << endl; // ==> 2/3
    cout << r8 << endl; // ==> 1/3
    
    cout << " " << endl;
    
    cout << r1 + r8 << endl; // ==> 5/6
    cout << r1 - r8 << endl; // ==> 1/6
    cout << r1 * r8 << endl; // ==> 1/6
    cout << r1 / r8 << endl; // ==> 3/2
    
    cout << " " << endl;
    
    cout << r1.numeric() << endl; // ==> 0.5
    cout << r8.numeric() << endl; // ==> 0.3333333
    
    cout << " " << endl;
    
    Rational r9(1,2);
    cout << r9 << endl; // ==> 1/2
    cout << r8 << endl; // ==> 1/3
    r9 += r8;
    cout << r9 << endl; // ==> 5/6
    
    cout << " " << endl;
    
    Rational r10(1,2);
    cout << r10 << endl; // ==> 1/2
    cout << r8 << endl;  // ==> 1/3
    r10 -= r8;
    cout << r10 << endl; // ==> 1/6
    
    cout << " " << endl;
    
    Rational r11(1,2);
    cout << r11 << endl; // ==> 1/2
    cout << r8 << endl;  // ==> 1/3
    r11 *= r8;
    cout << r11 << endl; // ==> 1/6
    
    cout << " " << endl;
    
    Rational r12(1,2);
    cout << r12 << endl; // ==> 1/2
    cout << r8 << endl;  // ==> 1/3
    r12 /= r8;
    cout << r12 << endl; // ==> 3/2
    
    cout << " " << endl;
    
    Rational r13(1,2);
    Rational r14(5,6);
    cout << r13 << endl; // ==> 1/2
    cout << r14 << endl; // ==> 5/6
    r13 = r14;
    cout << r13 << endl; // ==> 5/6
    
    cout << " " << endl;
    
    Rational r15(3,1);
    cout << r15 << endl;
    cout << r15.numeric() << endl;
    cout << "Numerator: " << r15.numerator() << endl;
    cout << "Denominator: " << r15.denominator() << endl;
    
    cout << " " << endl;
    
    Rational r16(1,2);
    Rational r17(3,6);
    Rational r18(2,3);
    cout << (r16 == r17) << endl;
    cout << (r16 != r17) << endl;
    
    cout << " " << endl;
    
    cout << (r16 == r18) << endl;
    cout << (r16 != r18) << endl;
}

void testComplexStatistics(Complex c) 
{
    cout << " " << endl;
    cout << "real: " << c.real() << endl;
    cout << "imag: " << c.imag() << endl;
    cout << "mag: " << c.magnitude() << endl;
    cout << "radians: " << c.radians() << endl;
    cout << "degrees: " << c.degrees() << endl;
    cout << " " << endl;
}

void testComplex()
{
    Complex c1(1,0);
    Complex c2(0,1);
    Complex c3(-1,0);
    Complex c4(0,-1);
    Complex c5(1,1);
    Complex c6(-1,1);
    Complex c7(-1,-1);
    Complex c8(1,-1);
    
    testComplexStatistics(c1);
    testComplexStatistics(c2);
    testComplexStatistics(c3);
    testComplexStatistics(c4);
    testComplexStatistics(c5);
    testComplexStatistics(c6);
    testComplexStatistics(c7);
    testComplexStatistics(c8);
}

#endif  // tester_h
