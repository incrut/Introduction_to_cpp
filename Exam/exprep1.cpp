#include <iostream>
using namespace std;

class Quad {
protected:
    float side1, side2, side3, side4;

public:
    virtual float Area() {
        return 0.0;
    }

    void SetSides(float s1, float s2, float s3, float s4) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
        side4 = s4;
    }
};

class Rectangle : public Quad {
public:
    float Area() override {
        return side1 * side2;
    }
};

int main() {
    Rectangle* rectPtr = new Rectangle();  // Create a pointer to Rectangle on the heap

    // Set the side lengths of the rectangle
    float length = 5.0;
    float width = 3.0;
    rectPtr->SetSides(length, width, length, width);

    // Calculate and print the area of the rectangle
    float area = rectPtr->Area();
    cout << "Area of the rectangle: " << area << endl;

    delete rectPtr;  // Deallocate memory

    return 0;
}
