#include "Stack.h"
#include <cstdlib>  // For rand() and srand()
#include <ctime>  // For time()

Stack::Stack() {
    head = -1;  // Initialize the head to -1
    // Seed the random number generator with the current time
    srand(time(0));
}

bool Stack::push(int x) {
    if (isFull()) {
        return false;  // Stack is full, cannot push
    }
    head++;
    data[head] = x;  // Push the element to the stack
    return true;  // Push successful
}

int Stack::pop() {
    if (isEmpty()) {
        return -1;  // Stack is empty, cannot pop
    }
    int value = data[head];  // Pop the element from the stack
    head--;
    return value;  // Return the popped element
}

int Stack::peek() {
    if (isEmpty()) {
        return -1;  // Stack is empty, cannot peek
    }
    return data[head];  // Return the top element of the stack
}

bool Stack::isEmpty() {
    return head == -1;  // Stack is empty if head is -1
}

bool Stack::isFull() {
    return head == MAX_SIZE - 1;  // Stack is full if head is at the maximum index
}

bool Stack::isPrime(int x) {
    if (x <= 1) {
        return false;  // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;  // Numbers divisible by i are not prime
        }
    }
    return true;  // If no divisors found, number is prime
}

int Stack::Gen_Random_Number() {
    return rand() % 1000 + 1;  // Generate a random number between 1 and 1000
}

Stack Stack::Sort_Prim_Numbers(Stack& input) {
    Stack s2;  // Create a new stack to store sorted numbers
    while (!input.isEmpty()) {
        int num = input.pop();
        // Insert num into s2 at the correct position
        while (!s2.isEmpty() && s2.peek() < num) {
            input.push(s2.pop());
        }
        s2.push(num);
    }
    return s2;  // Return the sorted stack
}