//
//  ArrayStack.cpp
//  Chapter2.5
//

#include <iostream>

#include "ArrayStack.h"

#pragma mark -
#pragma mark Constructors/Destructors
ArrayStack::ArrayStack(int s)
{
    // Check for a bad number
    if ( s < 0 || s > MAX_SIZE ) throw Bad_size();
    
    // configure the object
    top = 0;
    max_size = s;
    p = new char[s];
}

ArrayStack::~ArrayStack()
{
    delete[] p;
}

#pragma mark -
#pragma mark Push/Pop Methods
void ArrayStack::push(char c) 
{
    // check for overflow
    if ( top == max_size ) throw Overflow();
    
    // store the element
    p[top++] = c;
}

char ArrayStack::pop()
{
    // check for underflow
    if ( top == 0 ) throw Underflow();
    
    // return the element
    return p[--top];
}