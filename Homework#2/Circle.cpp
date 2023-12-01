#include <iostream>
#include "Line.cpp"

class Circle2 {
public:
    // Default constructor - creates a Point2 using the default constructor and sets the radius to zero
    Circle2() : p1(), r(0) {}

    // Parameterized constructor - values for class elements are provided
    Circle2(Point2 np1, float nr) : p1(np1) {
        r = (nr < 0) ? 0 : nr;
    }

    // Returns the circumference of the circle
    float circumference() {
        return 2 * 3.14159265 * r;
    }

    // Returns the area of the circle
    float area() {
        return 3.14159265 * r * r;
    }

    // Returns true if the given point is on or inside the circle, otherwise false
    bool contains(Point2 p) {
        return p1.distanceFrom(p) <= r;
    }

    // Returns true if the line is inside a circle, otherwise false
    bool contains(Line2 l) {
        return p1.distanceFrom(l.p1) <= r && p1.distanceFrom(l.p2) <= r;
    }

    // Multiplies the radius of the circle by the given value
    void scale(float factor) {
        if (factor >= 0) {
            r *= factor;
        }
    }

    // Outputs the circle in the form (p1, r)
    friend std::ostream& operator<<(std::ostream& os, const Circle2& circle) {
        os << "(" << circle.p1 << ", " << circle.r << ")";
        return os;
    }

private:
    Point2 p1;
    float r;
};


int main() {
    Point2 p1;
    Point2 p2(3.0, 4.0);
    std::cout << "Point 1 is " << p1 << std::endl;
    std::cout << "Point 2 is " << p2 << std::endl;
    std::cout << "Distance between p1 and p2 is " << p1.distanceFrom(p2) << std::endl;


    Line2 line(p1, p2);
    std::cout << "Line " << line << std::endl;
    std::cout << "Length is " << line.length() << std::endl;


    Circle2 c1(Point2(0,0), 5);
    std::cout << "Circumference = " << c1.circumference() << std::endl;
    std::cout << "Area = " << c1.area() << std::endl;
    
    if (c1.contains(Point2(4,6))) {
        std::cout << "Point p1 is inside circle c1" << std::endl;
    } else {
        std::cout << "Point p1 is outside circle c1" << std::endl;
    }

    c1.scale(2);
    std::cout << "Circumference after scaling = " << c1.circumference() << std::endl;
    std::cout << "Area after scaling = " << c1.area() << std::endl;

    Line2 l1(Point2(-2,0), Point2(2,0));
    if (c1.contains(l1)) {
        std::cout << "Line l1 is inside circle c1" << std::endl;
    } else {
        std::cout << "Line l1 is outside circle c1" << std::endl;
    }

    return 0;
}
