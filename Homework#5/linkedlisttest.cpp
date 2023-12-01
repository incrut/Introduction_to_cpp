#include <iostream>
#include "node.h"
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "Node.cpp"

void testLinkedList() {
    std::cout << "========================== Linked list Test =====================" << std::endl;
    Linkedlist l;
    l.addNode(10);
    l.addNode(20);
    l.addNode(30);
    l.addNode(40);
    l.addNode(50);
    l.addNode(60);
    l.addNode(70);
    l.addNode(80);
    l.addNode(90);
    std::cout << "Elements of the list are: ";
    l.printList();
    std::cout << "Length list is : " << l.lengthList() << std::endl;
    l.deleteNode_Index(2);
    std::cout << "Elements of the list are: ";
    l.printList();
    std::cout << "Length list is : " << l.lengthList() << std::endl;
    l.deleteNode_Index(2);
    std::cout << "Elements of the list are: ";
    l.printList();
    std::cout << "Length list is : " << l.lengthList() << std::endl;
    l.deleteNode_Data(40);
    std::cout << "Elements of the list are: ";
    l.printList();
    std::cout << "-----------------------------------------" << std::endl;
    l.isRange(200);
    l.searchNode(200);
    l.searchNode(10);
    std::cout << std::endl << "================================= End ===============================" << std::endl;
}

int main() {
    testLinkedList();
    return 0;
}