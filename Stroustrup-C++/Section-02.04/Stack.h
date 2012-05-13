//
//  Stack.h
//  Chapter2.4
//
//

#ifndef Stack_h
#define Stack_h

namespace Stack {
    void push(char);
    char pop();
    
    class Overflow { };     // type representing overflow exceptions
    class Underflow { };    // type representing underflow exceptions
}

#endif // Stack_h
