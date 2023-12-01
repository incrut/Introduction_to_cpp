#include <cmath>
#include <string>
#include <sstream>
#include "point.h"
#include "line.h"

template <class T>
class Sphere {
public:
    T o;
    float r;

    Sphere() {
        o = T();
        r = 0;
    }

    Sphere(T no, float nr) {
        o = no;
        r = nr >= 0 ? nr : 0;
    }

    bool contains(T v) {
        return o.distanceFrom(v) <= r;
    }

    bool contains(Line<T> l) {
        return o.distanceFrom(l) <= r;
    }

    void scale(float factor) {
        r *= factor;
    }

    std::string toString() {
        std::ostringstream ss;
        ss << "(" << o.toString() << "), " << r;
        return ss.str();
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, Sphere<T>& s) {
    os << s.toString();
    return os;
}
