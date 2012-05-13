//
//  main.cpp
//  Chapter2.5
//

#include <iostream>

#include "Stack.h"
#include "ArrayStack.h"
#include "ListStack.h"

using namespace std;

void testArrayStack()
{
    // test bad_size exception
    try {
        ArrayStack a(1000000);
    } catch ( Stack::Bad_size ) {
        cout << "Stack too large!" << endl;
    }
    
    // run through some examples
    Stack *s = new ArrayStack(100);
    s->push('a');
    s->push('b');
    s->push('c');
    cout << s->pop() << endl;   // ==> c
    cout << s->pop() << endl;   // ==> b
    cout << s->pop() << endl;   // ==> a
}

void testListStack()
{
    // run through some examples
    Stack *s = new ListStack(100);
    s->push('a');
    s->push('b');
    s->push('c');
    cout << s->pop() << endl;   // ==> c
    cout << s->pop() << endl;   // ==> b
    cout << s->pop() << endl;   // ==> a
}

int main(int argc, const char * argv[])
{
    testArrayStack();
    
    cout << " " << endl;
    
    testListStack();
    
    return 0;
}

