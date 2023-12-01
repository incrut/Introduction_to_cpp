#include "Stack.h"
#include "Stack.cpp"
#include <iostream>

int main() {
    std::cout << "//============================== Stack Test =======================" << std::endl;
    Stack s1;  // Create a stack s1
    std::cout << "//|=====> Push elements to s1 <=====|" << std::endl;
    int numPrimes = 0;  // Number of prime numbers pushed to s1
    while (numPrimes < 5) {
        int num = s1.Gen_Random_Number();
        if (s1.isPrime(num)) {
            s1.push(num);
            std::cout << num << " pushed" << std::endl;
            numPrimes++;
        }
    }

    Stack s2 = s1.Sort_Prim_Numbers(s1);  // Sort s1 elements into s2

    std::cout << "//|=====> Sorting s1 elements into s2 <=====|" << std::endl;
    while (!s2.isEmpty()) {
        int num = s2.pop();
        s1.push(num);
        std::cout << num << " pushed" << std::endl;
    }

    std::cout << "//|=====> Pop sorted elements from s2 <=====|" << std::endl;
    while (!s1.isEmpty()) {
        int num = s1.pop();
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "//================================= End ===============================" << std::endl;

    return 0;
}
