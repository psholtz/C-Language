//
//  Stack.cpp
//  Chapter2.4
//

#include "Stack.h"

namespace Stack {
    const int max_size = 200;
    char v[max_size];
    int top = 0;
}

void Stack::push(char c)
{
    // check for overflow
    if ( top == max_size ) throw Overflow();
    
    // store the element
    v[top++] = c;
}

char Stack::pop()
{
    // check for underflow
    if ( top == 0 ) throw Underflow();
    
    // return the element
    return v[--top];
}