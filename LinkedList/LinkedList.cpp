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


template <typename T>
LinkedList<T>::Node<T>::Node(T val, Node * next){
    this->value = val;
    this->next = next;
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
    while(currentNode != null){

    }

}

template <typename T>
LinkedList<T>::~LinkedList(){

}

template <typename T>
virtual int LinkedList<T>::size(){

}

template <typename T>
virtual void LinkedList<T>::isEmpty(){

}

template <typename T>
virtual bool LinkedList<T>::contains(const T &){

}

template <typename T>
virtual bool LinkedList<T>::operator == (const DataStructure &){

}

template <typename T>
virtual bool LinkedList<T>::operator = (const DataStructure &){

}

template <typename T>
virtual Iterator LinkedList<T>::createIterator(){

}

template <typename T>
virtual void LinkedList<T>::add(T){

}

template <typename T>
virtual void LinkedList<T>::remove(T){

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
