#ifndef MY_FUNCTORS_H
#define MY_FUNCTORS_H

#include <iostream>
#include <numeric>

template<typename T>
class SumElements {
public:
    SumElements() : sum_() {} // initialize sum to 0
    void operator()(const T& t) { sum_ += t; } // accumulate the sum
    T result() const { return sum_; } // return the sum
private:
    T sum_; // accumulate the sum
};

#endif
