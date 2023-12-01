#include "linkedlist.h"
#include "Node.h"
#include <iostream>

Linkedlist::Linkedlist() {
    head = NULL;
}

void Linkedlist::addNode(int x) {
    Node* newNode = new Node(x);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Linkedlist::printList() {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Linkedlist::deleteNode_Index(int i) {
    if (isRange(i)) {
        Node* temp = head;
        if (i == 0) {
            head = temp->next;
            delete temp;
        } else {
            Node* prev = NULL;
            for (int j = 0; j < i; j++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}

bool Linkedlist::isListEmpty() {
    return head == NULL;
}

int Linkedlist::lengthList() {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

bool Linkedlist::isRange(int i) {
    return i >= 0 && i < lengthList();
}

void Linkedlist::deleteNode_Data(int x) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        std::cout << "Element not found in the list!" << std::endl;
    } else {
        if (prev == NULL) {
            head = temp->next;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
    }
}

void Linkedlist::searchNode(int x) {
    Node* current = head;
    int index = 0;
    while (current != NULL && current->data != x) {
        current = current->next;
        index++;
    }
    if (current == NULL) {
        std::cout << "Element not found in the list!" << std::endl;
    } else {
        std::cout << "Element " << x << " found at index " << index << " in the list." << std::endl;
    }
}
