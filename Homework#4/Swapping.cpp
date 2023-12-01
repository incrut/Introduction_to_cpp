#include <iostream>

template<class T>
void swap_ref(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template<class T>
void swap_ptr(T *x, T *y) {
    T temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 5, y = 7;
    swap_ref<int>(x, y);
    std::cout << "x after swap_ref: " << x << std::endl;
    std::cout << "y after swap_ref: " << y << std::endl;
    
    int a = 5, b = 7;
    swap_ptr<int>(&a, &b);
    std::cout << "a after swap_ptr: " << a << std::endl;
    std::cout << "b after swap_ptr: " << b << std::endl;
    return 0;
}
