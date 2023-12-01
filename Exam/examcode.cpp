#include <iostream>

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a, b;
    std::cout << "Enter the Two Numbers to Swap in C++: ";
    std::cin >> a >> b;

    swap(a, b);

    std::cout << "\nAfter Swapping of Two Numbers: " << a << "   " << b << std::endl;

    return 0;
}
