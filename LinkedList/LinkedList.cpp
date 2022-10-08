#include "LinkedList.h"

//NODE FUNCTIONS

template <typename T>
LinkedList<T>::Node<T>::Node(){
    this->next = null;
}

template <typename T>
LinkedList<T>::Node<T>::Node(T val){
    this->value = val;
    this->next = null;
}

LinkedList<T>::Node<T>::~Node(){
    //nothing to delete, deletion of nodes is responsibility of LinkedList class
}

template <typename T>
Node * getNext(){
    return this->next;
}

template <typename T>
void LinkedList<T>::Node<T>::setNext(Node * next){
    this->next = next;
}

template <typename T>
void LinkedList<T>::Node<T>::setValue(T val){
    this->value = val;
}

template <typename T>
T LinkedList<T>::Node<T>::getValue(){
    return value;
}

//LINKEDLIST FUNCTIONS
template <typename T>
LinkedList<T>::LinkedList(){
    head = null;
    tail = null;
}

/**
 * @brief Construct a new Linked List< T>:: Linked List object
 * TODO: Is there a way to use the iterator for a LinkedList here without cirular referencing?
 * @tparam T 
 */
template <typename T>
LinkedList<T>::LinkedList(const & LinkedList ll){
    Node<T> * currentNode = ll.head;
    this->head = null;
    this->tail = null;
    this->size = 0;

    while(currentNode != null){
        Node<T> * newNode = new Node<T>(currentNode->getValue());
        if(tail != null)
            tail->setNext(newNode);
        
        tail = currentNode;
        currentNode = currentNode->getNext();
        size++;
    }
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T> * currentNode = head;
    while(currentNode != null){
        Node<T> * nextNode = currentNode->getNext();
        delete currentNode;
        currentNode = nextNode;
    }
}

template <typename T>
virtual int LinkedList<T>::size(){
    return this->size;
}

template <typename T>
virtual void LinkedList<T>::isEmpty(){
    return size == 0;
}

template <typename T>
virtual bool LinkedList<T>::contains(const T & val){
    Node<T> * currentNode = head;
    while(currentNode != null){
        if(currentNode->getValue() == val)
            return true;

        currentNode = currentNode->getNext();
    }
    return false;
}

template <typename T>
virtual bool LinkedList<T>::operator == (const LinkedList & ll) const{
    Node<T> * thisCurrentNode = head;
    Node<T> * otherCurrentNode = ll.head;

    while(thisCurrentNode != null && otherCurrentNode != null){
        if(thisCurrentNode->getValue() != otherCurrentNode->getValue())
            return false;
        thisCurrentNode = thisCurrentNode->getNext();
        otherCurrentNode = otherCurrentNode->getNext();
    }

    if(thisCurrentNode == null && otherCurrentNode == null)
        return true;

    return false;    
}

/**
 * @brief 
 * 
 * TODO: do we need this if we have a copy constructor? I can think of one use case but it doesn't seem like it really is too needed
 * @tparam T 
 * @return true 
 * @return false 
 */
template <typename T>
virtual bool LinkedList<T>::operator = (const LinkedList & ll){

    this->removeAll();
    Node<T> * currentNode = ll.head;
    this->head = null;
    this->tail = null;
    this->size = 0;

    while(currentNode != null){
        Node<T> * newNode = new Node<T>(currentNode->getValue());
        if(tail != null)
            tail->setNext(newNode);
        
        tail = currentNode;
        currentNode = currentNode->getNext();
        size++;
    }

    return true;
}
/*
template <typename T>
virtual Iterator LinkedList<T>::createIterator(){

}
*/

/**
 * @brief 
 * For now, this will act as an append function
 * 
 * @tparam T 
 */
template <typename T>
virtual void LinkedList<T>::add(T val){
    Node<T> * newNode = new Node<T>(val);
    if(this->head == null){ // empty list
        head = newNode;
        tail = newNode;
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }

    
    size ++;
}

template <typename T>
virtual void LinkedList<T>::remove(T val){
    //Could use contains function here but that would be inefficient, we have to reiterate through the list if deleting anyway
    Node<T> * currentNode = head;
    Node<T> * prevNode = null;
    while(currentNode != null){
        if(currentNode->getValue() == val){
            if(currentNode == head)
                deleteHead();
            else if(currentNode == tail)
                deleteTail();
            else deleteNode(currentNode, prevNode);
            size --;
            return;   
        }
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }

}

template <typename T>
void LinkedList<T>::removedeleteHead(){
    //check if head == tail
}

template <typename T>
void LinkedList<T>::removedeleteTail(){

}

template <typename T>
void LinkedList<T>::removedeleteNode(Node<T> *, Node<T> *){

}

template <typename T>
virtual void LinkedList<T>::insertAt(T, int){

}

template <typename T>
virtual void LinkedList<T>::deleteAt(int){

}

template <typename T>
virtual void LinkedList<T>::swap(int, int){

}

template <typename T>
virtual T LinkedList<T>::head(){

}

template <typename T>
virtual T LinkedList<T>::operator[](int index){

}
