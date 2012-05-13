//
//  Complex.h
//  Chapter2.7
//

#ifndef Complex_h
#define Complex_h

#include <iostream>

class Complex {
private:
    float _real, _imag;
    static float _makeMagnitude(float x, float y);     // conversion from rect to polar
    static float _makeRadians(float x, float y);       // conversion from rect to polar
    static float _makeReal(float r, float a);          // conversion from polar to rect
    static float _makeImag(float r, float a);           // conversion from polar to rect
    
public:
    // Constructors
    Complex(float real = 0.0f, float imag = 0.0f) : _real(real), _imag(imag) { }
    ~Complex() { }
    
    // Selectors (Rectangle)
    float real();
    float imag();
    
    // Selectors (Polar)
    float magnitude();
    float degrees();
    float radians();
    
    // Binary Operators
    const Complex operator+(const Complex other) const;
    const Complex operator-(const Complex other) const;
    const Complex operator*(const Complex other) const;
    const Complex operator/(const Complex other) const;
    
    // Comparison Operators
    bool operator==(const Complex &other) const;
    bool operator!=(const Complex &other) const;
    
    // Self-Assignment Operator
    Complex &operator=(const Complex &rhs);
    
    // Compound Assignment Operators
    Complex &operator+=(const Complex &rhs);
    Complex &operator-=(const Complex &rhs);
    Complex &operator*=(const Complex &rhs);
    Complex &operator/=(const Complex &rhs);
    
    // ostream Operator
    friend std::ostream &operator<<(std::ostream &out, Complex c);
    
};

#endif // Complex_h
