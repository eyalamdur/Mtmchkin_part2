#ifndef EX3_NODE_H
#define EX3_NODE_H

#include <iostream>

template <class T>
class Node {
public:
    /* C'tor of Node class - 0 param.
    * @return a new instance of Node. */
    Node();

    /* C'tor of Node class - 1 param.
    * @param item - item which the node will contain.
    * @return a new instance of Node. */
    Node(T* item);

    /* D'tor of Node class. */
    ~Node();

    /* Copy of Node class.
    * @param Node& - reference to another Node object.
    * @return a new instance of Node with copied values as the given Node. */
    Node(const Node&) = default;

    /* Sets the Node item to given one. 
    * @param item - item which the node will contain.
    * @return void. */
    void setItem(T* item);

    /* Sets the Node back pointer to given one. 
     * @param back - Node pointer which this node will now contain in its back pointer.
     * @return void. */
    void setBack(Node& back);

    /* Sets the Node front pointer to given one. 
     * @param front - Node pointer which this node will now contain in its front pointer.
     * @return void. */
    void setFront(Node& front);

    /* returns the Node item. */
    T* getItem();

    /* returns the Node back pointer. */
    Node<T>* getBack();

    /* returns the Node front pointer. */
    Node<T>* getFront();

    /* Here we are explicitly telling the compiler to use the default methods*/
    Node& operator=(const Node& other) = default;

private:
    T* m_item;
    Node* m_front;
    Node* m_back;
};

/*----------------------------------------------------------------------------*/
/* C'tor of Node class - 0 param.
 * @return a new instance of Node. */
template <class T>
Node<T>::Node(){
    this->m_item = NULL;
    this->m_front = NULL;
    this->m_back = NULL;
}

/* C'tor of Node class - 1 param.
 * @param item - item which the node will contain.
 * @return a new instance of Node. */
template <class T>
Node<T>::Node(T* item){
    T* newItem = new T;
    *newItem = *item;
    this->m_item = newItem;
    this->m_front = NULL;
    this->m_back = NULL;
}

/* D'tor of Node class. */
template <class T>
Node<T>::~Node(){
    if (this->m_item){
        delete(this->m_item);
    }
    return;
}

/* Sets the Node back pointer to given one. 
 * @param back - item which the node will contain.
 * @return void. */
template <class T>
void Node<T>::setItem(T* item){
    this->m_item = item;
    return;
}

/* Sets the Node back pointer to given one. 
 * @param back - Node pointer which this node will now contain in its back pointer.
 * @return void. */
template <class T>
void Node<T>::setBack(Node& back){
    this->m_back = &back;
    return;
}

/* Sets the Node back pointer to given one. 
 * @param front - Node pointer which this node will now contain in its front pointer.
 * @return void. */
template <class T>
void Node<T>::setFront(Node& front){
    this->m_front = &front;
    return;
}

/* returns the Node item. */
template <class T>
T* Node<T>::getItem(){
    if (!this){
        return NULL;
    }
    return this->m_item;
}

/* returns the Node back pointer. */
template <class T>
Node<T>* Node<T>::getBack(){
    return this->m_back;
}

/* returns the Node front pointer. */
template <class T>
Node<T>* Node<T>::getFront(){
    return this->m_front;
}


#endif //EX3_NODE_H
