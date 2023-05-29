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
    void pushBack(T* item);

    /* Pop to the front item of the Queue.
     * @return void. */
    void popFront();

    /* Here we are explicitly telling the compiler to use the default methods */
    Queue& operator=(const Queue& other) = default;

private:
    Node<T>* m_front;
    Node<T>* m_back;
    int m_size;

};

/*----------------------------------------------------------------------------*/
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
void Queue<T>::pushBack(T* item){
    if (this->m_front == NULL){
        this->m_front = new Node(item);
    }
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
    this->m_front = this->m_front->getBack();
    if (temp){
        delete(temp);
    }
}

#endif //EX3_QUEUE_H
