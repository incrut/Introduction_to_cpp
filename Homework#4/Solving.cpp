#include <iostream>
#include <cmath>

bool solve(double a, double b, double c, double &x1, double &x2) {
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return false;
    }
    else if (discriminant == 0) {
        x1 = x2 = -b / (2*a);
        return true;
    }
    else {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        return true;
    }
}

int main() {
    double a = 1.0, b = -2.0, c = 1.0;
    double solution1, solution2; 
    if (solve(a, b, c, solution1, solution2)) {
        std::cout << "Solution: " << solution1 << ", " << solution2 << std::endl;
    }
    else {
        std::cout << "No solutions in real numbers" << std::endl;
    }
    return 0;
}
