#include "node.h"

// Default constructor
Node::Node() {
    data = 0;
    next = nullptr;
}

// Constructor with data parameter
Node::Node(int data) {
    this->data = data;
    next = nullptr;
}
