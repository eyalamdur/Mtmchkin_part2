#include "Node.h"
#include "Queue.h"
#include <string>
#include <iostream>

void nodeTest(){
    int item1 = 1, item2 = 2, item3 = 3;
    Node<int> stam;
    Node<int> first(&item1);
    Node<int> second = &item2;
    Node<int> third = &item3;
    std::cout << "First Node: " << *(first.getItem()) << std::endl;
    std::cout << "second Node: " << *(second.getItem()) << std::endl;
    std::cout << "third Node: " << *(third.getItem()) << std::endl;
    first.setBack(second);
    second.setBack(third);
    second.setFront(first);
    third.setFront(second);
    std::cout << "First Node back: " << (*first.getBack()->getItem()) << std::endl;
    std::cout << "second Node front: " << (*second.getFront()->getItem()) << std::endl;
    std::cout << "second Node back: " << (*second.getBack()->getItem()) << std::endl;
    std::cout << "third Node front: " << (*third.getFront()->getItem()) << std::endl;
    first.setItem(&item3);
    std::cout << "End" << std::endl;
}


int main() {
    std::cout << "Node Test Start" << std::endl;
    nodeTest();
    return 0;
}