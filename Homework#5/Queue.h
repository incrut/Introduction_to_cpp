#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue {
public:
    Queue();
    bool isFull();
    bool isEmpty();
    void EnQueue(T x);
    T DeQueue();
    void PrintQueue();
    void Search(T x);
    int max = 5;

private:
    static const int MAX = 5;
    T arr[MAX]; 
    int front;
    int rear;
};

#endif
