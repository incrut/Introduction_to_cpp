#include <iostream>
#include <cmath>

class Point2 {
public:
    // Default constructor
    Point2() : x(0.0), y(0.0) {}

    // Parameterized constructor
    Point2(float nx, float ny) : x(nx), y(ny) {}

    // Calculate the distance from another point
    float distanceFrom(Point2 p) {
        float dx = x - p.x;
        float dy = y - p.y;
        return std::sqrt(dx*dx + dy*dy);
    }

    // Output the coordinates of the point
    friend std::ostream& operator<<(std::ostream& os, const Point2& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

private:
    float x;
    float y;
};


