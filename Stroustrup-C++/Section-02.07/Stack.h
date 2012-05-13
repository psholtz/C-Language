//
//  Stack.h
//  Chapter2.7
//
//  Created by Paul Sholtz on 5/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#define MAX_SIZE 10000

#pragma mark -
#pragma mark Class Declaration
template<class T> class Stack {
private:
    T* v;
    int max_size;
    int top;
    
public:
    // Constructors
    Stack(int s);
    ~Stack();
    
    // Push/Pop Methods
    void push(T);
    T pop();
    
    // Exceptions
    class Bad_size { };
    class Overflow { };
    class Underflow { };
};

#pragma mark -
#pragma mark Constructors
// ++++++++++++++++++++++++++++++++++++++++++++ 
// TEMPLATE METHODS IMPLEMENTED IN HEADER FILE
// ++++++++++++++++++++++++++++++++++++++++++++
template <class T> Stack<T>::Stack(int s)
{
    // Check for a bad number
    if ( s< 0 || s > MAX_SIZE ) new Bad_size();
    
    // Configure the object
    top = 0;
    max_size = s;
    v = new T[s];
}

template <class T> Stack<T>::~Stack()
{
    
}

#pragma mark -
#pragma mark Push/Pop methods
template <class T> void Stack<T>::push(T t) 
{
    // check for overflow
    if ( top == max_size ) throw Overflow();
    
    // store the element
    v[top++] = t;
}

template <class T> T Stack<T>::pop()
{
    // check for underflow
    if ( top == 0 ) throw Underflow();
    
    // return the element
    return v[--top];
}

#endif  // Stack_h
