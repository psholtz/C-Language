//
//  ListStack.cpp
//  Chapter2.5
//

#include "ListStack.h"

#pragma mark -
#pragma mark Constructors
ListStack::ListStack(int s)
{
    // Check for a bad number
    if ( s < 0 || s > MAX_SIZE ) throw Bad_size();
    
    // Configure the object
    lc = new std::list<char>(s);
}

ListStack::~ListStack()
{
    delete lc;
}

#pragma mark -
#pragma mark Push/Pop Interface
void ListStack::push(char c)
{
    lc->push_front(c);
}

char ListStack::pop()
{
    char c = lc->front();
    lc->pop_front();
    return c; 
}