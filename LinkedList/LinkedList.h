#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../DataStructure.h"
#include <stdexcept>
#include <iostream>

class TestLinkedList; //Forward declaration so that we can make it a friend class

using namespace std; 

/**
 * Generic Singly Linked List
 * 
 * Including a tail pointer since we have the add function which will function as an appending function.
 * Having a tail makes appending faster since we wont have to traverse entire list
 * 
 * TODO: does every function here need to be virtual?
 * TODO: implement private functions for use by iterator eg getNextNode.
 * TODO: add and remove functions and how size is affected. Should this happen at lowest level functions? I think use since these are the functions that actually do the thing that decreases the size.
 * @tparam T 
 */
template <class T>
class LinkedList : public DataStructure<T> {

        friend class TestLinkedList;

        protected:
        /**
         * Nested class to prevent outside access to this class. 
         * Allows us to prevent others from creating dependencies on this class
         * which would potentially prevent updates to this class from occurring in the future. 
         * 
         * This class has no copy constructor since we do NOT want multiple nodes to point to
         * the same node in their next fields, this violates a singly linked ideaology.
         * 
         * TODO: Is this tight coupling optimal? Should there be code reuse between this linked list and other linked lists?? Not all other linkedlists will inherit from this 
         * TODO: duplicated iteration code in multiple functions. Is there a way to reduce this?
         * @tparam T 
         */
        
        class Node{
            private:    
                T value;
                Node * next;
                Node(); //private since we never want this used: T should never get a default value
            public:
                Node(T);
                Node(T, Node *);
                Node * getNext();
                ~Node();
                void setNext(Node *);
                void setValue(T);
                T getValue();
                T & getValueByReference(); //Honestly, included for sake of uniformity. Best practice to not directly access other classes variable in this case(?)
        };

        Node * head;
        Node * tail;
        int size; //faster to update this when we make changes as opposed to traversing list each time we need the list size

        //helper functions for node deletion
        void deleteOnlyNode();
        void deleteHead();
        void deleteTail(Node * );
        void deleteNode(Node *, Node *);

        //helper function for adding nodes
        void addAtHead(T);
        void addNode(T,int);

        bool isOutOfBoundsForInsert(int);
        bool isOutOfBoundsForAccess(int);

        public:
            //Constructor and Destructors
            LinkedList();
            LinkedList(const LinkedList<T> &);
            virtual ~LinkedList();

            virtual int getSize();
            virtual bool isEmpty();
            virtual bool contains(const T &);
            virtual bool operator == (const LinkedList &) const;
            //Creates Deep Copy
            virtual bool operator = (const LinkedList &);
            //virtual Iterator createIterator();

            //Functions that alter the underlying list
            virtual void add(T);
            //Will remove first occurrance of T
            virtual void remove(T);
            virtual void insertAt(T, int);
            virtual void deleteAt(int);
            virtual void removeAll();
            //Will be used later for sorting algorithm
            virtual void swap(int, int);

            //Access Functions
            virtual T getHead();
            virtual T & operator[](int index); // Needs to return reference otherwise can't assign to using []

            virtual string toString();
};


#endif
