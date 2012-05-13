//
//  Rational.cpp
//  Chapter2.5
//

#include "Rational.h"

#include <cmath>

#pragma mark -
#pragma mark Private Methods
// Return greater common divisor between a and b.
int Rational::gcd(int a, int b)
{
    if ( b == 0 ) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

void Rational::configure(int n, int d) 
{
    int g = this->gcd(abs(n), abs(d));
    if ( d < 0 ) {
        _n = (-1 * n)/g;
        _d = (-1 * d)/g;
    } else {
        _n = n/g;
        _d = d/g;
    }
}

#pragma mark -
#pragma mark Selectors
int Rational::numerator()
{
    return _n;
}

int Rational::denominator()
{
    return _d;
}

float Rational::numeric()
{
    return (float)_n / (float)_d;
}

#pragma mark -
#pragma mark Binary Operators
const Rational Rational::operator+(const Rational other) const 
{
    Rational me = *this;
    int n = (me._n * other._d) + (other._n * me._d);
    int d = me._d * other._d;
    return Rational(n,d);
}

const Rational Rational::operator-(const Rational other) const 
{
    Rational me = *this;
    int n = (me._n * other._d) - (other._n * me._d);
    int d = me._d * other._d;
    return Rational(n,d);
}

const Rational Rational::operator*(const Rational other) const 
{
    Rational me = *this;
    int n = me._n * other._n;
    int d = me._d * other._d;
    return Rational(n,d);
}

const Rational Rational::operator/(const Rational other) const 
{
    Rational me = *this;
    int n = me._n * other._d;
    int d = me._d * other._n;
    return Rational(n,d);
}

bool Rational::operator==(const Rational &other) const 
{
    Rational me = *this;
    return me._n == other._n && me._d == other._d;
}

bool Rational::operator!=(const Rational &other) const 
{
    Rational me = *this;
    return me._n != other._n || me._d != other._d;
}

#pragma mark -
#pragma mark Composite Assignment Operators
Rational &Rational::operator+=(const Rational &rhs) 
{
    Rational me = *this;
    int n = (me._n * rhs._d) + (rhs._n * me._d);
    int d = me._d * rhs._d;
    configure(n, d);
    
    return *this;
}

Rational &Rational::operator-=(const Rational &rhs) 
{
    Rational me = *this;
    int n = (me._n * rhs._d) - (rhs._n * me._d);
    int d = me._d * rhs._d;
    configure(n, d);
    
    return *this;
}

Rational &Rational::operator*=(const Rational &rhs) 
{
    Rational me = *this;
    int n = me._n * rhs._n;
    int d = me._d * rhs._d;
    configure(n, d);
    
    return *this;
}

Rational &Rational::operator/=(const Rational &rhs) 
{
    Rational me = *this;
    int n = me._n * rhs._d;
    int d = me._d * rhs._n;
    configure(n, d);
    
    return *this;
}

#pragma mark -
#pragma mark Self-Assignment Operator
Rational &Rational::operator=(const Rational &rhs) 
{
    configure(rhs._n, rhs._d);
    return *this;
}

#pragma mark -
#pragma mark ostream Operator
std::ostream &operator<<(std::ostream &out, Rational r) 
{
    if ( r.denominator() == 1 ) {
        out << r.numerator();
    } else {
        out << r.numerator() << "/" << r.denominator();
    }
    return out;
}