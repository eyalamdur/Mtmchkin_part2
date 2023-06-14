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
    Queue(const Queue&);

    /* Push to the back of Queue new item.
     * @param item& - reference to another item.
     * @return void. */
    void pushBack(T item);
    void pushBack(T item) const;

    /* Returns the front item of the Queue.
     * @return first item in queue. */
    T& front() const;

    /* Pop to the front item of the Queue.
     * @return void. */
    void popFront();
    void popFront() const;

    /* Returns the size of Queue.
     * @return int size. */
    int size() const;

    /* = of Queue class.
     * @param Queue& - reference to another Queue object.
     * @return a new instance of Queue with copied values as the given Queue. */
    Queue& operator=(const Queue& other);

    class EmptyQueue{};
    class Iterator;
    class ConstIterator;
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
    friend class Queue<T>;
    friend class Queue<T>::ConstIterator;

    public:
        Iterator(const Node<T>* pointer);
        T& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& iterator) const;
        bool operator!=(const Iterator& iterator) const;

        Iterator(const Iterator&) = default;
        Iterator& operator=(const Iterator&) = default;
        
        class InvalidOperation{};
};

template <class T>
class Queue<T>::ConstIterator {
    const Node<T>* pointer;
    friend class Queue<T>;

    public:
        ConstIterator(const Node<T>* pointer);
        ConstIterator(const Queue<T>::Iterator pointer);
        T& operator*();
        ConstIterator& operator++();
        ConstIterator operator++(int);
        bool operator==(const ConstIterator& iterator) const;
        bool operator!=(const ConstIterator& iterator) const;

        ConstIterator(const ConstIterator&) = default;
        ConstIterator& operator=(const ConstIterator&) = default;
    
    class InvalidOperation{};
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
    while (this->m_size != 0){
        popFront();
    }
    return;
}

/* Copy of Queue class.
 * @param Queue& - reference to another Queue object.
 * @return a new instance of Queue with copied values as the given Queue. */
template <class T>
Queue<T>::Queue(const Queue& queue){
    this->m_front = NULL;
    this->m_back = NULL;
    this->m_size = 0;

    for (Node<T> item : queue){
        this->pushBack(item.getItem());
    }
}

/* Assignment of Queue class.
 * @param Queue& - reference to another Queue object.
 * @return a new instance of Queue with copied values as the given Queue. */
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){
    // Check if the assignment is leagl
    Queue<T> temp;
    try{
        for (T item : other){
            temp.pushBack(item);
        }

        // If so empty old queue (if exist) and assign new one
        if (this->m_size != 0){
            while (this->m_front){
                popFront();
            }
        }
        this->m_back = NULL;
        this->m_front = NULL;
        this->m_size = 0;
        for (T item : other){
            this->pushBack(item);
        }
        return *this;
    }
    catch(...){
        temp.~Queue();
        throw;
    }
}

/* Push to the back of Queue new item.
 * @param item& - reference to another item.
 * @return void. */
template <class T>
void Queue<T>::pushBack(T item){
    Node<T> *newItem = new Node<T>;
    try{
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
        return;
    }
    catch(...){
        delete(newItem);
        throw;
    }
}

template <class T>
void Queue<T>::pushBack(T item) const{
    // Const queue
    return;
}

/* Returns the front item of the Queue.
 * @return first item in queue. */
template <class T>
T& Queue<T>::front() const{
    // Empty queue
    if (this->m_size == 0){
        throw(Queue::EmptyQueue());
    }
    return this->m_front->getItem();
}

/* Pop to the front item of the Queue.
 * @return void. */
template <class T>
void Queue<T>::popFront(){
    // Empty queue
    if (this->m_size == 0){
        throw(Queue::EmptyQueue());
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

template <class T>
void Queue<T>::popFront() const{
    // Const queue
    return;
}

/* Returns the size of Queue.
 * @return int size. */
template <class T>
int Queue<T>::size() const{
    try{
        return this->m_size;
    }
    catch(...){
        throw (Queue::EmptyQueue());
    }
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
    // Last item cannot have ++ operator
    try{
        this->pointer->getBack();
    }
    catch (...){
        throw(Queue::Iterator::InvalidOperation());
    }

    this->pointer = &this->pointer->getBack();
    return *this;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {
    // Last item cannot have ++ operator
    if (this->pointer->getBack == NULL){
        throw(Queue::Iterator::InvalidOperation());
    }

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

/* C'tor of Queue::ConstIterator class.
* @return a new instance of ConstIterator. */
template<class T>
Queue<T>::ConstIterator::ConstIterator(const Node<T>* pointer) : pointer(pointer){}

/* C'tor of Queue::ConstIterator class.
* @return a new instance of ConstIterator. */
template<class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>::Iterator pointer) : pointer(pointer.pointer){}

/* Operators ++ (both sides), !=, == and *. */
template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() {
    // Last item cannot have ++ operator
    try{
        this->pointer->getBack();
    }
    catch (...){
        throw(Queue::ConstIterator::InvalidOperation());
    }

    this->pointer = &this->pointer->getBack();
    return *this;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int) {
    // Last item cannot have ++ operator
    if (this->pointer->getBack == NULL){
        throw(Queue::ConstIterator::InvalidOperation());
    }

    ConstIterator result = *this;
    this->pointer = &this->pointer->getBack();
    return result;
}

template<class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator& i) const {
    return this->pointer == i.pointer;
} 

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& i) const {
    return !(this->pointer == i.pointer);
} 

template<class T>
T& Queue<T>::ConstIterator::operator*(){
    return pointer->getItem();
} 

/*----------------------------------------------------------------------------*/

template <class T, typename Functor>
Queue<T> filter(const Queue<T>& queue, Functor filterFunction){
    Queue<T> newQueue;
    for (T item : queue){
        if (filterFunction(item)){
            newQueue.pushBack(item);
        }
    }
    return newQueue;
}

template <class T, typename Functor>
void transform(const Queue<T>& queue, Functor transeformFunction){
    for (typename Queue<T>::Iterator item = queue.begin(); item != queue.end(); ++item){
        transeformFunction(*item);
    }
    return;
}

#endif //EX3_QUEUE_H
