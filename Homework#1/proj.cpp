#include <iostream>

int maximum(int a, int b){
    if (a > b){
        std::cout << "a is bigger than b\n";
        return a;
    }

    else if (a < b){
        std::cout << " b is bigger than a\n";
        return b;
    }

    else {
        std::cout << "those numbers are equal\n";
        return NULL;
    }
}

int product (int a, int b){
    int prod = a*b;
    std::cout << prod;
    return prod;
}

int power (int a, int b){
    int pow = a;
    for (int i = 1; i < b; i++){
        pow = a*pow;
    }
    std::cout << pow;
    return pow;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main (){
    gcd(10,5);
}