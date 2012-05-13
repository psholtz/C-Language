//
//  Complex.cpp
//  Chapter2.7
//
//  Created by Paul Sholtz on 5/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Complex.h"

#include <cmath>

#define PI 3.14159

#pragma mark -
#pragma mark (Static) Private Methods
float Complex::_makeRadians(float x, float y)
{
    if ( x >= 0 ) {
        if ( y >= 0 ){
            return atanf(y/x);
        } else {
            return atanf(y/x) + 2*PI;
        }
    } else {
        if ( y >= 0 ) {
            return atanf(y/x) + PI;
        } else {
            return atanf(y/x) + PI;
        }
    }
}

float Complex::_makeMagnitude(float x, float y)
{
    return sqrt( x*x + y*y );
}

float Complex::_makeReal(float r, float a)
{
    return r * cosf(a);
}

float Complex::_makeImag(float r, float a)
{
    return r * sinf(a);
}

#pragma mark -
#pragma mark Selectors (Rectangle)
float Complex::real()
{
    return _real;
}

float Complex::imag()
{
    return _imag;
}

#pragma mark -
#pragma mark Selectors (Polar)
float Complex::magnitude()
{
    return _makeMagnitude(_real, _imag);
}

float Complex::radians()
{
    return _makeRadians(_real, _imag);
}

float Complex::degrees()
{
    return radians() * 180 / PI;
}

#pragma mark -
#pragma mark Binary Operators
const Complex Complex::operator+(const Complex other) const 
{
    Complex me = *this;
    float real = me._real + other._real;
    float imag = me._imag + other._imag;
    return Complex(real,imag);
}

const Complex Complex::operator-(const Complex other) const 
{
    Complex me = *this;
    float real = me._real - other._real;
    float imag = me._imag - other._imag;
    return Complex(real,imag);
}

const Complex Complex::operator*(const Complex other) const
{
    Complex me = *this;
    float real = me.magnitude() * _makeMagnitude(other._real, other._imag);
    float imag = me.radians() + _makeRadians(other._real, other._imag);
    return Complex(real,imag);    
}

const Complex Complex::operator/(const Complex other) const 
{
    Complex me = *this;
    float real = me.magnitude() / _makeMagnitude(other._real, other._imag);
    float imag = me.radians() - _makeMagnitude(other._real, other._imag);
    return Complex(real,imag);
}

#pragma mark -
#pragma mark Comparison Operators
bool Complex::operator==(const Complex &other) const 
{
    Complex me = *this;
    return me._real == other._real && me._imag == other._imag;
}

bool Complex::operator!=(const Complex &other) const 
{
    Complex me = *this;
    return me._real != other._real || me._imag != other._imag;
}

#pragma mark
#pragma mark Self-Assignment Operator
Complex &Complex::operator=(const Complex &rhs)
{
    _real = rhs._real;
    _imag = rhs._imag;
    return *this;
}

#pragma mark
#pragma mark Compound Assigment Operators
Complex &Complex::operator+=(const Complex &rhs)
{
    Complex me = *this;
    float real = me._real + rhs._real;
    float imag = me._imag + rhs._imag;
    _real = real;
    _imag = imag;
    
    return *this;
}

Complex &Complex::operator-=(const Complex &rhs)
{
    Complex me = *this;
    float real = me._real - rhs._real;
    float imag = me._imag - rhs._imag;
    _real = real;
    _imag = imag;
    
    return *this;
}

Complex &Complex::operator*=(const Complex &rhs)
{
    Complex me = *this;
    float magnitude = me.magnitude() * _makeMagnitude(rhs._real, rhs._imag);
    float angle = me.radians() * _makeRadians(rhs._real, rhs._imag);
    _real = _makeReal(magnitude, angle);
    _imag = _makeImag(magnitude, angle);
    
    return *this;
}

Complex &Complex::operator/=(const Complex &rhs)
{
    Complex me = *this;
    float magnitude = me.magnitude() / _makeMagnitude(rhs._real, rhs._imag);
    float angle = me.radians() - _makeRadians(rhs._real, rhs._imag);
    _real = _makeReal(magnitude, angle);
    _imag = _makeImag(magnitude, angle);
    
    return *this;
}

#pragma mark
#pragma mark ostream Operator
std::ostream &operator<<(std::ostream &out, Complex c)
{
    out << c.real() << " + " << c.imag() << "i";
    return out;
}