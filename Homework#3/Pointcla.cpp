#include <iostream>
#include <list>
#include <cmath>
#include <sstream>

template <unsigned short n>
class Point {
public:
    Point() {
        for (int i = 0; i < n; i++) {
            coords.push_back(0);
        }
    }

    Point(std::list<float> crds) {
        if (crds.size() != n) {
            throw std::string("Number of coordinates specified in the template differs from the size of the predefined coordinate vector.");
        }
        coords = crds;
    }

    float distanceFrom(Point<n> v) {
        float sum = 0;
        auto it1 = coords.begin();
        auto it2 = v.coords.begin();
        for (int i = 0; i < n; i++) {
            float diff = *it1 - *it2;
            sum += diff * diff;
            it1++;
            it2++;
        }
        return std::sqrt(sum);
    }

    std::string toString() {
        std::stringstream ss;
        ss << "(";
        auto it = coords.begin();
        for (int i = 0; i < n; i++) {
            ss << *it;
            if (i != n-1) {
                ss << ", ";
            }
            it++;
        }
        ss << ")";
        return ss.str();
    }

    template <unsigned short m>
    friend std::ostream& operator<<(std::ostream& os, Point<m>& p);

private:
    std::list<float> coords;
};

template <unsigned short n>
std::ostream& operator<<(std::ostream& os, Point<n>& p) {
    os << p.toString();
    return os;
}
