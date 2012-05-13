//
//  ListStack.h
//  Chapter2.5
//

#ifndef ListStack_h
#define ListStack_h

#include <list>

#include "Stack.h"

class ListStack : public Stack 
{
private:
    std::list<char> *lc;
    
public:
    // Constructors
    ListStack(int s);
    ~ListStack();
    
    // Push/Pop Interafcce
    void push(char c);
    char pop();
};

#endif // ListStack_h
