//
//  main.cpp
//  Chapter2.7
//

#include <iostream>

#include "Stack.h"
#include "Complex.h"
#include "Rational.h"

#include "tester.h"

using namespace std;

void test1()
{
    Stack<char> s(100);
    s.push('a');
    s.push('b');
    s.push('c');
    
    cout << " " << endl;
    cout << s.pop() << endl; // ==> c
    cout << s.pop() << endl; // ==> b
    cout << s.pop() << endl; // ==> a
    cout << " " << endl;
}

void test2()
{
    Stack<int> s(100);
    s.push(100);
    s.push(500);
    s.push(750);
    
    cout << " " << endl;
    cout << s.pop() << endl;    // ==> 750
    cout << s.pop() << endl;    // ==> 500
    cout << s.pop() << endl;    // ==> 100
    cout << " " << endl;
}

void test3()
{
    Stack<Complex> s(100);
    s.push(Complex(1,0));
    s.push(Complex(1,1));
    s.push(Complex(0,1));
    
    cout << " " << endl;
    cout << s.pop() << endl;   // ==> 0 + 1i
    cout << s.pop() << endl;   // ==> 1 + 1i
    cout << s.pop() << endl;   // ==> 1 + 0i
    cout << " " << endl;
}

void test4()
{
    Stack<Rational> s(100);
    s.push(Rational(1,2));
    s.push(Rational(2,3));
    s.push(Rational(5,6));
    
    cout << " " << endl;
    cout << s.pop() << endl;    // ==> 5/6
    cout << s.pop() << endl;    // ==> 2/3
    cout << s.pop() << endl;    // ==> 1/2
    cout << " " << endl;
}

int main(int argc, const char * argv[])
{
    //testRational();
    //testComplex();
 
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}

