//
//  main.cpp
//  Chapter3
//

#include <iostream>
#include <valarray>

#define PI 3.14159 

using namespace std;

#pragma mark -
#pragma mark Declarations
void f(valarray<double> &a1, valarray<double> &a2);
void display(valarray<double> &a, const string &name) ;

#pragma mark -
#pragma mark Definitions
void f(valarray<double> &a1, valarray<double> &a2)
{
    // first computation
    valarray<double> a = a1 * PI + a2/a1;
    display(a, "a");
    
    // second computation
    a2 += a1 * PI;
    display(a2, "a2");
    
    // third computation
    a = abs(a);
    display(a, "a");
    
    // fourth computation
    double d = a2[3];
    cout << d << endl;
}

void display(valarray<double> &a, const string &name) 
{
    cout << "[" << name << "]: ";
    for ( int i=0; i < a.size(); ++i ) 
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}

#pragma mark -
#pragma mark Main Driver
int main (int argc, const char * argv[])
{
    valarray<double> a1(5);
    a1[0] = 5.0f;
    a1[1] = 3.0f;
    a1[2] = 1.0f;
    a1[3] = -1.0f;
    a1[4] = -3.0f;
    display(a1,"a1");
    
    valarray<double> a2(5);
    a2[0] = 1.0f;
    a2[1] = 2.0f;
    a2[2] = 3.0f;
    a2[3] = 4.0f;
    a2[4] = 5.0f;
    display(a2,"a2");
    
    f(a1,a2);
    
    return 0;
}

