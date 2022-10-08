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

template <typename T>
T & LinkedList<T>::Node<T>::getValueByReference(){
    return & value;
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
    this->size = ll.size();

    while(currentNode != null){
        Node<T> * newNode = new Node<T>(currentNode->getValue());
        if(tail != null)
            tail->setNext(newNode);
        
        tail = currentNode;
        currentNode = currentNode->getNext();
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
            //case of head == tail included here for the sake of clarity: I.M.O its easier to see this cae is handled if we check it 
            //in this function
            if(currentNode == head) {
                if(head == tail)
                    deleteOnlyNode();
                else deleteHead();
                
            }
            else if(currentNode == tail)
                deleteTail(prevNode);
            else deleteNode(currentNode, prevNode);
            size --;
            return;   
        }
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }

}

template <typename T>
void LinkedList<T>::deleteOnlyNode(){
    delete head;
    head = null;
    tail = null;
    size = 0;
}

template <typename T>
void LinkedList<T>::deleteHead(){
   Node<T> * temp = head;
   delete head;
   head = temp;
   size --;
}

template <typename T>
void LinkedList<T>::deleteTail(Node<T> * prevNode){
    prevNode->setNext(null);
    delete tail;
    size --;
}

template <typename T>
void LinkedList<T>::deleteNode(Node<T> * currentNode, Node<T> * prevNode){
    prevNode ->setNext(currentNode->getNext());
    delete currentNode;
    size --;
}

template <typename T>
bool LinkedList<T>::isOutOfBounds(int index){
    if(index < 0 || index >= size)
        return true;
    return false;
}

template <typename T>
virtual void LinkedList<T>::insertAt(T val, int index){

    if(isOutOfBounds(index))
        throw std:out_of_range("ERROR: index " + index + " is out of range for LinkedList with size " + size);

    if(index == 0){
        //check if tail == head, heandles case for size -1 where size = 1
        if(head == tail)
            add(val); //this function already handles this case
        else addAtHead(val);   
    }
    else if(index == size -1)
        add(val);
    else addNode(val, index);
}

template <typename T>
void LinkedList<T>::addAtHead(T){
    Node<T> * newNode = new Node<T>(val);
    newNode->setNext(head);
    head = newNode;
    size ++;
}

template <typename T>
void LinkedList<T>::addNode(T val, int index){

    Node<T> * currentNode = head;
    Node<T> * prevNode = null;

    for(int i=0; i<index; ++i){
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }
    Node<T> * newNode = new Node<T>(val);
    newNode->setNext(currentNode);
    prevNode->setNext(newNode);
    size ++;
}

template <typename T>
virtual void LinkedList<T>::deleteAt(int index){

    if(isOutOfBounds(index))
        throw std:out_of_range("ERROR: index " + index + " is out of range for LinkedList with size " + size);

    if(index == 0){
        //check if tail == head, heandles case for size -1 where size = 1
        if(head == tail)
            add(T); //this function already handles this case
        else{
            Node<T> * newNode = new Node<T>(T);
            newNode->setNext(head);
            head = newNode;
            size ++;
        }
    }
    else if(index == size -1){
        add(T);
    }
    else{
        Node<T> * currentNode = head;
        Node<T> * prevNode = null;

        for(int i=0; i<index; ++i){
            prevNode = currentNode;
            currentNode = currentNode->getNext();
        }
        Node<T> * newNode = new Node<T>(T);
        newNode->setNext(currentNode);
        prevNode->setNext(newNode);
        size ++;
    }
}

template <typename T>
virtual void LinkedList<T>::swap(int index1, int index2){

    if(isOutOfBounds(index1))
        throw std:out_of_range("ERROR: index " + index1 + " is out of range for LinkedList with size " + size);

    if(isOutOfBounds(index2))
        throw std:out_of_range("ERROR: index " + index2 + " is out of range for LinkedList with size " + size);
    
    T temp = (*this)[index1];
    (*this)[index1] = (*this)[index2];
    (*this)[index2] = temp;
}

template <typename T>
virtual T LinkedList<T>::head(){
    return head->getValue();
}

/**
 * @brief 
 * 
 * 
 * 
 * @tparam T 
 * @param index 
 * @return T& 
 */
template <typename T>
virtual T & LinkedList<T>::operator[](int index){

    if(isOutOfBounds(index))
        throw std:out_of_range("ERROR: index " + index + " is out of range for LinkedList with size " + size);
    
    Node<T> * currentNode = head;

    for(int i=0; i<index; ++i){
        currentNode = currentNode->getNext();
    }
    return currentNode->getValueByReference();
}
