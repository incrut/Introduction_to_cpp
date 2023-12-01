#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Equivalence class separation
string classify_input(int input) {
    if (input < 1 || input > 99) {
        return "Invalid input";
    }
    else if (input == 1 || input == 99) {
        return "Boundary value";
    }
    else {
        return "Valid input";
    }
}

// Boundary value testing
void test_input(int input) {
    string classif = classify_input(input);
    if (classif == "Invalid input") {
        cout << "Invalid input: " << input << endl;
    }
    else if (classif == "Boundary value") {
        cout << "Boundary value: " << input << endl;
    }
    else {
        cout << "Valid input: " << input << endl;
    }
}

int main() {
    // Test invalid inputs
    test_input(-1);
    test_input(0);
    test_input(100);
    test_input(101);
    test_input(2.5);

    // Test boundary values
    test_input(1);
    test_input(99);

    // Test valid inputs
    test_input(50);
    test_input(25);
    test_input(75);

    return 0;
}