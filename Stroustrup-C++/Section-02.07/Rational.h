//
//  Rational.h
//  Chapter2.7
//

#ifndef Rational_h
#define Rational_h

#include <iostream>

class Rational {
private:
    // Private members
    int _n, _d;
    int gcd(int a,int b);
    void configure(int n, int d);
    
public:
    // Constructors and Destructors
    Rational(int n=1, int d = 1) { configure(n,d); }
    virtual ~Rational() { }
    
    // Selectors
    int numerator();
    int denominator();
    float numeric();
    
    // Binary Operators
    const Rational operator+(const Rational other) const;
    const Rational operator-(const Rational other) const;
    const Rational operator*(const Rational other) const;
    const Rational operator/(const Rational other) const;
    
    // Comparison Operators
    bool operator==(const Rational &other) const;
    bool operator!=(const Rational &other) const;
    
    // Self-Assignment Operator
    Rational &operator=(const Rational &rhs);
    
    // Compound Assignment Operators
    Rational &operator+=(const Rational &rhs);
    Rational &operator-=(const Rational &rhs);
    Rational &operator*=(const Rational &rhs);
    Rational &operator/=(const Rational &rhs);
    
    // ostream Operator
    friend std::ostream &operator<<(std::ostream &out, Rational r);
};

#endif // Rational_h
