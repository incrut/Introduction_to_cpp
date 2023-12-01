#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack();  // Constructor
    bool push(int x);  // Push a data to the stack
    int pop();  // Pop an element from the stack and return it
    int peek();  // Read an element from the stack and return it
    bool isEmpty();  // To check if the stack is empty
    bool isFull();  // To check if the stack is full
    bool isPrime(int x);  // To check if a number is prime
    int Gen_Random_Number();  // To generate a random number
    Stack Sort_Prim_Numbers(Stack& input);  // To sort the elements of the stack using another stack

private:
    static const int MAX_SIZE = 5;
    int head;  // Index of the top of the stack
    int data[MAX_SIZE];  // Store elements of the stack
};

#endif  // STACK_H
