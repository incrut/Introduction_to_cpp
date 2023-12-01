#include <iostream>

class Vector2 {
public:
    double x, y;
    Vector2(double x_ = 0.0, double y_ = 0.0) : x(x_), y(y_) {}
};

template <class T>
class DynamicLine {
public:
    T *p1;
    T *p2;
    
    DynamicLine(T *v1, T *v2) : p1(v1), p2(v2) {}
    DynamicLine(const DynamicLine& l) : p1(l.p1), p2(l.p2) {}
    DynamicLine& operator= (const DynamicLine& l) {
        if (this != &l) {
            p1 = l.p1;
            p2 = l.p2;
        }
        return *this;
    }
    ~DynamicLine() {}
};

int main() {
    Vector2 p1(1.0, 2.0);
    Vector2 p2(0, 0);
    Vector2 p3(5.0, 2.0);
    DynamicLine<Vector2> l1(&p1, &p2);  // line between p1 and p2
    DynamicLine<Vector2> l2 = l1;       // copy line l1 (same endpoints)
    l2.p2 = &p3;                        // define l2 other endpoint
    p1.x = 2.0;                         // both l1 and l2 endpoints have moved
    
    std::cout << "l1 endpoints: (" << l1.p1->x << ", " << l1.p1->y << "), (" 
              << l1.p2->x << ", " << l1.p2->y << ")" << std::endl;
    std::cout << "l2 endpoints: (" << l2.p1->x << ", " << l2.p1->y << "), (" 
              << l2.p2->x << ", " << l2.p2->y << ")" << std::endl;

    return 0;
}
