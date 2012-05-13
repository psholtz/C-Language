//
//  ArrayStack.h
//  Chapter2.5
//

#ifndef ArrayStack_h
#define ArrayStack_h

#include "Stack.h"

class ArrayStack : public Stack 
{
private:
    int top;
    int max_size;
    char *p;
    
public:
    // Constructors
    ArrayStack(int s);
    ~ArrayStack();
    
    // Push/Pop Interface
    void push(char c);
    char pop();
};

#endif // ArrayStack_h
