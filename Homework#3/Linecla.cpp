#include <iostream>
#include <sstream>

template <class T>
class Line {
public:
    Line() {
        p1 = T();
        p2 = T();
    }

    Line(T np1, T np2) {
        p1 = np1;
        p2 = np2;
    }

    float length() {
        return p1.distanceFrom(p2);
    }

    std::string toString() {
        std::stringstream ss;
        ss << "(" << p1.toString() << ")-(" << p2.toString() << ")";
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const Line<T>& line) {
        os << line.toString();
        return os;
    }

private:
    T p1;
    T p2;
};
