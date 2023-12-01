#include <iostream>
#include "Point.cpp" 

class Line2 {
public:
    // Default constructor - creates points using Point2 default constructor
    Line2() : p1(), p2() {}

    // Parameterized constructor - values for class elements are provided
    Line2(Point2 np1, Point2 np2) : p1(np1), p2(np2) {}

    // Returns the length of the line
    float length() {
        return p1.distanceFrom(p2);
    }

    // Outputs straight line data in the form (p1 - p2)
    friend std::ostream& operator<<(std::ostream& os, const Line2& line) {
        os << "coords " << line.p1 << " and " << line.p2;
        return os;
    }

public:
    Point2 p1;
    Point2 p2;
};
