//
//  Stack.h
//  Chapter2.5
//

#ifndef Stack_h
#define Stack_h

#define MAX_SIZE 10000

//
// Define push/pop interface for a Stack.
// Specific implementations will define these methods in specific ways.
//
class Stack {    
public:
    // Stack Interface
    virtual void push(char c) = 0;  // virtual function, define in subclass
    virtual char pop() = 0;         // virtual function, define in subclass
    
    // Exception classes
    class Underflow { };
    class Overflow { };
    class Bad_size { };
};

#endif // Stack_h
