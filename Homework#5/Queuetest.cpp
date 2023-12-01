#include <iostream>
#include <ctime>
#include "Queue.h"
#include "Queue.cpp"

int main() {
    std::cout << "============================== Queue Test ===========================" << std::endl;

    Queue<int> q1;
    std::cout << "|=====> Check Queue is empty <=====|" << std::endl;
    q1.DeQueue();
    std::cout << "Done!! " << std::endl;

    std::cout << "|=====> Push elements to Queue <=====| " << std::endl;
    srand(time(0));
    q1.EnQueue(rand() % 10);
    q1.EnQueue(rand() % 10);
    q1.EnQueue(rand() % 10);
    q1.EnQueue(rand() % 10);
    q1.EnQueue(rand() % 10);
    std::cout << std::endl << "Done!! " << std::endl;

    std::cout << "|=====> Check Queue is full <=====|" << std::endl;
    q1.EnQueue(60);
    std::cout << "Done!! " << std::endl;

    std::cout << "|=====> Display Queue elements <=====|" << std::endl;
    q1.PrintQueue();
    std::cout << "Done!! " << std::endl;

    std::cout << "|=====> Delete element <=====|" << std::endl;
    q1.DeQueue();
    std::cout << "Done!! " << std::endl;

    std::cout << "|=====> Display Queue elements <=====|" << std::endl;
    q1.PrintQueue();
    std::cout << "Done!! " << std::endl;

    std::cout << "|=====> Search in Queue <=====|" << std::endl;
    Queue<int> q2;
    for (int i = 0; i < q2.max; i++) {
        q2.EnQueue(rand() % 10);
    }

    q2.PrintQueue();
    std::cout << "Enter a number to search: ";
    int num;
    std::cin >> num;
    q2.Search(num);

    std::cout << std::endl << "================================= End ===============================" << std::endl;
    return 0;
}
