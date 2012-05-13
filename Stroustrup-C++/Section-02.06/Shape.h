//
//  Shape.h
//  Chapter2.6
//
//  Created by Paul Sholtz on 5/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Shape_h
#define Shape_h

class Shape {
private:
    Point center;
    Color color;
public:
    Point where() { return center; }
    void move(Point to) {
        center = to;
        draw();
    }
    
    virtual void draw() = 0;
    virtual void rotate(int angle) = 0;
};


#endif // Shape_h
