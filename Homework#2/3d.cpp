#include <iostream>
#include <cmath>

class Point3 {
private:
    float x, y, z;
public:
    Point3() : x(0), y(0), z(0) {}
    Point3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}
    float distanceFrom(Point3 p) {
        float dx = x - p.x;
        float dy = y - p.y;
        float dz = z - p.z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }
    friend std::ostream& operator<<(std::ostream& os, Point3 p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }
};

class Line3 {
public:
    Point3 p1, p2;
    Line3() : p1(Point3()), p2(Point3()) {}
    Line3(Point3 np1, Point3 np2) : p1(np1), p2(np2) {}
    float length() {
        return p1.distanceFrom(p2);
    }
    friend std::ostream& operator<<(std::ostream& os, Line3 l) {
        os << "(" << l.p1 << " - " << l.p2 << ")";
        return os;
    }
};

class Sphere3 {
private:
    Point3 p1;
    float r;
public:
    Sphere3() : p1(Point3()), r(0) {}
    Sphere3(Point3 np1, float nr) : p1(np1), r(nr < 0 ? 0 : nr) {}
    float circumference() {
        return 2 * M_PI * r;
    }
    float area() {
        return 4 * M_PI * r * r;
    }
    float volume() {
        return (4.0/3.0) * M_PI * r * r * r;
    }
    bool contains(Point3 p) {
        return p1.distanceFrom(p) <= r;
    }
    bool contains(Line3 l) {
        return (p1.distanceFrom(l.p1) <= r) && (p1.distanceFrom(l.p2) <= r);
    }
    void scale(float factor) {
        if (factor >= 0) {
            r *= factor;
        }
    }
    friend std::ostream& operator<<(std::ostream& os, Sphere3 s) {
        os << "(" << s.p1 << ", " << s.r << ")";
        return os;
    }
};

int main() {
    Point3 p1(1, 2, 3);
    Point3 p2(4, 5, 6);
    Point3 p3(7, 8, 9);

    std::cout << "Point 1 is " << p1 << std::endl;
    std::cout << "Point 2 is " << p2 << std::endl;
    std::cout << "Point 3 is " << p3 << std::endl;

    Line3 line(p1, p2);
    std::cout << "Line is " << line << std::endl;
    std::cout << "Line length is " << line.length() << std::endl;

    Sphere3 sphere(p2, 5);
    std::cout << "Sphere is " << sphere << std::endl;
    std::cout << "Sphere circumference is " << sphere.circumference() << std::endl;
    std::cout << "Sphere area is " << sphere.area() << std::endl;
    std::cout << "Sphere volume is " << sphere.volume() << std::endl;

    std::cout << "Point 1 is inside the sphere is " << sphere.contains(p1) << std::endl;
    std::cout << "Point 2 is inside the sphere is " << sphere.contains(p2) << std::endl;
    std::cout << "Point 3 is inside the sphere is " << sphere.contains(p3) << std::endl;

    Line3 line2(p1, p3);
    std::cout << "Line is inside the sphere is " << sphere.contains(line2) << std::endl;

    sphere.scale(2);
    std::cout << "Scaled sphere is " << sphere << std::endl;

    sphere.scale(-1);
    std::cout << "Scaled sphere is " << sphere << std::endl;

    return 0;
}