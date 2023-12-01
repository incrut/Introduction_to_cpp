#include <vector>
#include <string>
#include <sstream>
#include "point.h"
#include "line.h"
#include "sphere.h"

template <class T, unsigned short n>
class Polygon {
public:
    // Constructors
    Polygon() {
        points = std::vector<T>(n);
    }
    
    Polygon(std::vector<T> pts) {
        if (pts.size() != n) {
            throw std::invalid_argument("Incorrect number of points");
        }
        points = pts;
    }
    
    // Perimeter method
    float perimeter() {
        float sum = 0;
        for (int i = 0; i < n; i++) {
            sum += points[i].distanceFrom(points[(i+1)%n]);
        }
        return sum;
    }
    
    // String representation method
    std::string toString() {
        std::stringstream ss;
        ss << "(" << points[0];
        for (int i = 1; i < n; i++) {
            ss << "),(" << points[i];
        }
        ss << ")";
        return ss.str();
    }
    
    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Polygon& poly) {
        os << poly.toString();
        return os;
    }
    
private:
    std::vector<T> points;
};
