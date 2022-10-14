#include "LinkedList.h"

//NODE FUNCTIONS

template <class T>
LinkedList<T>::Node::Node(){
    this->next = NULL;
}

template <class T>
LinkedList<T>::Node::Node(T val){
    this->value = val;
    this->next = NULL;
}

template <class T>
LinkedList<T>::Node::~Node(){
    //nothing to delete, deletion of nodes is responsibility of LinkedList class
}

template <class T>
typename LinkedList<T>::Node * LinkedList<T>::Node::getNext(){
    return this->next;
}

template <class T>
void LinkedList<T>::Node::setNext(Node * next){
    this->next = next;
}

template <class T>
void LinkedList<T>::Node::setValue(T val){
    this->value = val;
}

template <class T>
T LinkedList<T>::Node::getValue(){
    return value;
}

template <class T>
T & LinkedList<T>::Node::getValueByReference(){
    return value;
}

//LINKEDLIST FUNCTIONS --------------------------------------------------------------------------------------------
template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

/**
 * @brief Construct a new Linked List< T>:: Linked List object
 * TODO: Is there a way to use the iterator for a LinkedList here without cirular referencing?
 * @tparam T 
 */
template <class T>
LinkedList<T>::LinkedList(const LinkedList & ll){
    Node * currentNode = ll.head;
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;

    while(currentNode != NULL){
        Node * newNode = new Node(currentNode->getValue());
        if(tail != NULL)
            tail->setNext(newNode);
        
        tail = currentNode;
        currentNode = currentNode->getNext();
        size++;
    }
}

template <class T>
LinkedList<T>::~LinkedList(){
    Node * currentNode = head;
    while(currentNode != NULL){
        Node * nextNode = currentNode->getNext();
        delete currentNode;
        currentNode = nextNode;
    }
}

template <class T>
int LinkedList<T>::getSize(){
    return this->size;
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

template <class T>
bool LinkedList<T>::contains(const T & val){
    Node * currentNode = head;
    while(currentNode != NULL){
        if(currentNode->getValue() == val)
            return true;

        currentNode = currentNode->getNext();
    }
    return false;
}

template <class T>
bool LinkedList<T>::operator == (const LinkedList & ll) const{
    Node * thisCurrentNode = head;
    Node * otherCurrentNode = ll.head;

    while(thisCurrentNode != NULL && otherCurrentNode != NULL){
        if(thisCurrentNode->getValue() != otherCurrentNode->getValue())
            return false;
        thisCurrentNode = thisCurrentNode->getNext();
        otherCurrentNode = otherCurrentNode->getNext();
    }

    if(thisCurrentNode == NULL && otherCurrentNode == NULL)
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
template <class T>
bool LinkedList<T>::operator = (const LinkedList & ll){

    this->removeAll();
    Node * currentNode = ll.head;
    this->head = NULL;
    this->tail = NULL;
    this->size = ll.size;

    while(currentNode != NULL){
        Node * newNode = new Node(currentNode->getValue());
        if(tail != NULL)
            tail->setNext(newNode);
        
        tail = currentNode;
        currentNode = currentNode->getNext();
    }

    return true;
}
/*
template <class T>
Iterator LinkedList<T>::createIterator(){

}
*/

/**
 * @brief 
 * For now, this will act as an append function
 * 
 * @tparam T 
 */
template <class T>
void LinkedList<T>::add(T val){
    Node * newNode = new Node(val);
    if(this->head == NULL){ // empty list
        head = newNode;
        tail = newNode;
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }

    size ++;
}

template <class T>
void LinkedList<T>::remove(T val){
    //Could use contains function here but that would be inefficient, we have to reiterate through the list if deleting anyway
    Node * currentNode = head;
    Node * prevNode = NULL;
    while(currentNode != NULL){
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

template <class T>
void LinkedList<T>::removeAll(){
    Node * currentNode = head; 
    Node * temp;
    tail = NULL; 
    size = 0;
    while(currentNode != NULL){
        temp = currentNode;
        currentNode = currentNode->getNext();
        delete temp;
    }

}

template <class T>
void LinkedList<T>::deleteOnlyNode(){
    delete head;
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
void LinkedList<T>::deleteHead(){
   Node * temp = head;
   delete head;
   head = temp;
   size --;
}

template <class T>
void LinkedList<T>::deleteTail(Node * prevNode){
    prevNode->setNext(NULL);
    delete tail;
    size --;
}

template <class T>
void LinkedList<T>::deleteNode(Node * currentNode, Node * prevNode){
    prevNode ->setNext(currentNode->getNext());
    delete currentNode;
    size --;
}

template <class T>
bool LinkedList<T>::isOutOfBounds(int index){
    if(index < 0 || index >= size)
        return true;
    return false;
}

template <class T>
void LinkedList<T>::insertAt(T val, int index){

    if(isOutOfBounds(index))
        throw std::out_of_range("ERROR: index " + to_string(index) + " is out of range for LinkedList with size " + to_string(size));

    if(index == 0){
        addAtHead(val);   //works for case head==tail != NULL
    }
    else if(index == size -1)
        add(val);
    else addNode(val, index);
}

template <class T>
void LinkedList<T>::addAtHead(T val){
    Node * newNode = new Node(val);
    newNode->setNext(head);
    head = newNode;
    size ++;
}

template <class T>
void LinkedList<T>::addNode(T val, int index){

    Node * currentNode = head;
    Node * prevNode = NULL;

    for(int i=0; i<index; ++i){
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }
    Node * newNode = new Node(val);
    newNode->setNext(currentNode);
    prevNode->setNext(newNode);
    size ++;
}

template <class T>
void LinkedList<T>::deleteAt(int index){

    if(isOutOfBounds(index))
        throw std::out_of_range("ERROR: index " + to_string(index) + " is out of range for LinkedList with size " + to_string(size));

    if(index == 0){
        //check if tail == head, heandles case for size -1 where size = 1
        if(head == tail)
            deleteOnlyNode();
        else{
            deleteHead();
        }
    }
    else{
        Node * currentNode = head;
        Node * prevNode = NULL;

        for(int i=0; i<index; ++i){
            prevNode = currentNode;
            currentNode = currentNode->getNext();
        }
        deleteNode(currentNode, prevNode);
    }
}

template <class T>
void LinkedList<T>::swap(int index1, int index2){

    if(isOutOfBounds(index1))
        throw std::out_of_range("ERROR: index " + to_string(index1) + " is out of range for LinkedList with size " + to_string(size));

    if(isOutOfBounds(index2))
        throw std::out_of_range("ERROR: index " + to_string(index2) + " is out of range for LinkedList with size " + to_string(size));
    
    T temp = (*this)[index1];
    (*this)[index1] = (*this)[index2];
    (*this)[index2] = temp;
}

template <class T>
T LinkedList<T>::getHead(){
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
template <class T>
T & LinkedList<T>::operator[](int index){

    if(isOutOfBounds(index))
        throw std::out_of_range("ERROR: index " + to_string(index) + " is out of range for LinkedList with size " + to_string(size));
    
    Node * currentNode = head;

    for(int i=0; i<index; ++i){
        currentNode = currentNode->getNext();
    }
    return currentNode->getValueByReference();
}


/**
 * This function assumes that the '<<' operator of class 'T' is overloaded 
 * 
 * @tparam T 
 * @return string 
 */
template <class T>
string LinkedList<T>::toString(){

    Node * thisCurrentNode = head;
    string listRepresentation = "";

    while(thisCurrentNode != NULL){

        stringstream ss;
        ss<<thisCurrentNode->getValue()<<" ";
        listRepresentation += ss.str();
        thisCurrentNode = thisCurrentNode->getNext();
    }
    
    return listRepresentation.substr(0, listRepresentation.length()-1);
}

