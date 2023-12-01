#include "Queue.h"

template <typename T>
Queue<T>::Queue() {
    front = -1;
    rear = -1;
}

template <typename T>
bool Queue<T>::isFull() {
    return (rear == MAX - 1);
}

template <typename T>
bool Queue<T>::isEmpty() {
    return (front == -1 || front > rear);
}

template <typename T>
void Queue<T>::EnQueue(T x) {
    if (isFull()) {
        std::cout << "Queue is full. Cannot enqueue element " << x << std::endl;
        return;
    }

    if (front == -1) {
        front = 0;
    }
    rear++;
    arr[rear] = x;
}

template <typename T>
T Queue<T>::DeQueue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return T();
    }

    T x = arr[front];
    front++;
    return x;
}

template <typename T>
void Queue<T>::PrintQueue() {
    if (isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    std::cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Queue<T>::Search(T x) {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot search." << std::endl;
        return;
    }

    bool found = false;
    for (int i = front; i <= rear; i++) {
        if (arr[i] == x) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "Element " << x << " found in the queue." << std::endl;
    } else {
        std::cout << "Element " << x << " not found in the queue." << std::endl;
    }
}
