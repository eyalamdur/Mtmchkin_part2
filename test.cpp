#include "Node.h"
#include "Queue.h"
#include <string>
#include <iostream>

static bool isEven(int n){
    return (n % 2) == 0;
}

static void square(int& n){
    n = n*n;
}


void nodeTest(){
    int item3 = 3;
    Node<int> stam;
    Node<int> first(1);
    Node<int> second = 2;
    Node<int> third = item3;
    std::cout << "First Node: " << (first.getItem()) << std::endl;
    std::cout << "second Node: " << (second.getItem()) << std::endl;
    std::cout << "third Node: " << (third.getItem()) << std::endl;
    first.setBack(second);
    second.setBack(third);
    second.setFront(first);
    third.setFront(second);
    std::cout << "First Node back: " << (first.getBack().getItem()) << std::endl;
    std::cout << "second Node front: " << (second.getFront().getItem()) << std::endl;
    std::cout << "second Node back: " << (second.getBack().getItem()) << std::endl;
    std::cout << "third Node front: " << (third.getFront().getItem()) << std::endl;
    first.setItem(4);
    std::cout << "End" << std::endl;
}

void queueTest(){
    Queue<int> queue1;
	queue1.pushBack(1);
	queue1.pushBack(2);
	int front1 = queue1.front();
	queue1.front() = 3;
	front1 = queue1.front();
	queue1.popFront();
	front1 = queue1.front();
	int size1 = queue1.size();

    Queue<int> queue3;
	for (int i = 1; i <= 10; i++) {
		queue3.pushBack(i);
	}
    for (Queue<int>::Iterator i = queue3.begin(); i != queue3.end(); ++i) {
		std::cout << "%" << std::endl;
	}
    for (int i : queue3){
        std::cout << "&" << std::endl;
    }

	Queue<int> queue4 = filter(queue3, isEven);
    transform(queue3, square);
    return;
}
int main() {
    std::cout << "Node Test Start" << std::endl;
    nodeTest();
    queueTest();
    return 0;
}