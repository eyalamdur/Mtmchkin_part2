#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include <string>
#include "Node.h"

template <class T>
class Queue {
public:
    /* C'tor of Queue class.
     * @return a new instance of Queue. */
    Queue();

    /* D'tor of Queue class. */
    ~Queue();

    /* Copy of Queue class.
     * @param Queue& - reference to another Queue object.
     * @return a new instance of Queue with copied values as the given Queue. */
    Queue(const Queue&) = default;

    /* Prints the Queue info*/
    void printQueue() const;

    /* Push to the back of Queue new item.
     * @param item& - reference to another item.
     * @return void. */
    void pushBack(T item);

    /* Returns the front item of the Queue.
     * @return first item in queue. */
    T& front();

    /* Pop to the front item of the Queue.
     * @return void. */
    void popFront();

    /* Returns the size of Queue.
     * @return int size. */
    int size();

    /* Here we are explicitly telling the compiler to use the default methods */
    Queue& operator=(const Queue& other) = default;

    class EmptyQueue;
    class Iterator;
    Iterator begin() const;
    Iterator end() const; 

private:
    Node<T>* m_front;
    Node<T>* m_back;
    int m_size;

};

template <class T>
class Queue<T>::Iterator {
    const Node<T>* pointer;
    Iterator(const Node<T>* pointer);
    friend class Queue<T>;

    public:
    T& operator*();
    Iterator& operator++();
    Iterator operator++(int);

    bool operator==(const Iterator& iterator) const;
    bool operator!=(const Iterator& iterator) const;

    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    
    class InvalidOperation;

};

/*---------------------------Class member functions---------------------------*/
/* C'tor of Queue class.
* @return a new instance of Queue. */
template <class T>
Queue<T>::Queue(){
    this->m_front = NULL;
    this->m_back = NULL;
    this->m_size = 0;
}

/* D'tor of Queue class. */
template <class T>
Queue<T>::~Queue(){
    while (this->m_front){
        popFront();
    }
    return;
}

/* Push to the back of Queue new item.
 * @param item& - reference to another item.
 * @return void. */
template <class T>
void Queue<T>::pushBack(T item){
    Node<T> *newItem = new Node<T>;
    newItem->setItem(item);
    if (this->m_front == NULL){
        this->m_front = newItem;
    }
    if (this->m_back){
        this->m_back->setBack(*newItem);
        newItem->setFront(*this->m_back);
    }
    this->m_back = newItem;
    this->m_size++;
}

/* Returns the front item of the Queue.
 * @return first item in queue. */
template <class T>
T& Queue<T>::front(){
    return this->m_front->getItem();
}

/* Pop to the front item of the Queue.
 * @return void. */
template <class T>
void Queue<T>::popFront(){
    // Empty queue
    if(!this->m_front){
        return;
    }

    // Remove front and delete it
    Node<T>* temp = this->m_front;
    this->m_front = &this->m_front->getBack();
    if (temp){
        delete(temp);
    }

    // If the queue only item was poped than its an empty queue.
    if(this->m_front == NULL){
        this->m_back = NULL;
    }
    this->m_size--;
    return;
}

/* Returns the size of Queue.
 * @return int size. */
template <class T>
int Queue<T>::size(){
    return this->m_size;
}

/* C'tor of Queue::Iterator class.
* @return a new instance of Queue. */
template<class T>
Queue<T>::Iterator::Iterator(const Node<T>* pointer) : pointer(pointer){}

/* Returns the front node of Queue.
 * @return the Queue front node. */
template<class T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(this->m_front);
}

/* Returns the back node of Queue.
 * @return the Queue back node. */
template<class T>
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(NULL);
}

/* Operators ++ (both sides), !=, == and *. */
template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    this->pointer = &this->pointer->getBack();
    return *this;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {
    Iterator result = *this;
    this->pointer = &this->pointer->getBack();
    return result;
}

template<class T>
bool Queue<T>::Iterator::operator==(const Iterator& i) const {
    return this->pointer == i.pointer;
} 

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const {
    return !(this->pointer == i.pointer);
} 

template<class T>
T& Queue<T>::Iterator::operator*() {
    return pointer->getItem();
} 

/*----------------------------------------------------------------------------*/

template <class T>
Queue<T> filter(const Queue<T>& queue, bool (*filterFunction)(T)){
    Queue<T> newQueue;
    for (Node<T> item : queue){
        if (filterFunction(item.getItem())){
            newQueue.pushBack(item.getItem());
            std::cout << "item: "<< item.getItem() << std::endl;
        }
    }
    return newQueue;
}

template <class T>
void transform(const Queue<T>& queue, void (*transeformFunction)(T&)){
    for (typename Queue<T>::Iterator item = queue.begin(); item != queue.end(); ++item){
        transeformFunction(*item);
        std::cout << "new item: "<< *item << std::endl;
    }
    return;
}
#endif //EX3_QUEUE_H
