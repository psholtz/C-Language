//
//  Shape.h
//  Chapter2.6
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
