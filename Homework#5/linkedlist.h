#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class Linkedlist {
public:
    Linkedlist();
    void addNode(int x);
    void printList();
    void deleteNode_Index(int i);
    bool isListEmpty();
    int lengthList();
    bool isRange(int i);
    void deleteNode_Data(int x);
    void searchNode(int x);

private:
    Node* head;
};

#endif
