#include<iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot perform pop operation." << std::endl;
            return -1;
        }
        int popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot perform peek operation." << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
