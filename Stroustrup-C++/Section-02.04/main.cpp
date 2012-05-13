//
//  main.cpp
//  Chapter2.4
//

#include <iostream>

#include "Stack.h"

using namespace std;

void f() 
{
    Stack::push('c');
    if ( Stack::pop() != 'c' ) { cout << "Impossible!" << endl; }
}

void g()
{
    Stack::push('a');
    cout << Stack::pop() << endl;
    // ==> a
    
    Stack::push('b');
    cout << Stack::pop() << endl;
    // ==> b
    
    Stack::push('c');
    cout << Stack::pop() << endl;
    // ==> c
    
    Stack::push('a');
    Stack::push('b');
    Stack::push('c');
    cout << Stack::pop() << endl;
    cout << Stack::pop() << endl;
    cout << Stack::pop() << endl;
    // ==> c
    // ==> b
    // ==> a
}

void h()
{
    try {
        int i = 0;
        while (true) {
            Stack::push('c');
            cout << "Pushed " << (++i) << " times(s).." << endl;
        }
    } 
    catch (Stack::Overflow) {
        cout << "Overflow!" << endl;
    }
}

int main(int argc, const char * argv[])
{
    f();
    g();
    h();
    return 0;
}

