#include "../DataStructure.h"
#include <stdexcept>
using namespace std; 

/**
 * Generic Singly Linked List
 * 
 * Including a tail pointer since we have the add function which will function as an appending function.
 * Having a tail makes appending faster since we wont have to traverse entire list
 * 
 * TODO: does every function here need to be virtual?
 * TODO: implement private functions for use by iterator eg getNextNode.
 * @tparam T 
 */
template <typename T>
class LinkedList : public DataStructure{

        protected:
        /**
         * Nested class to prevent outside access to this class. 
         * Allows us to prevent others from creating dependencies on this class
         * which would potentially prevent updates to this class from occurring in the future. 
         * 
         * This class has no copy constructor since we do NOT want multiple nodes to point to
         * the same node in their next fields, this violates a singly linked ideaology.
         * 
         * TODO: Is this tight coupling optimal? Should there be code reuse between this linked list and other linked lists??
         * TODO: duplicated iteration code in multiple functions. Is there a way to reduce this?
         * @tparam T 
         */
        template <typename T>
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
        };

        Node<T> * head;
        Node<T> * tail;
        int size; //faster to update this when we make changes as opposed to traversing list each time we need the list size

        //helper functions for node deletion
        void deleteHead();
        void deleteTail();
        void deleteNode(Node<T> *, Node<T> *);

        public:
            //Constructor and Destructors
            LinkedList();
            LinkedList(const & LinkedList);
            ~LinkedList();

            virtual int size();
            virtual void isEmpty();
            virtual bool contains(const T &);
            virtual bool operator == (const LinkedList &) const;
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
            virtual T head();
            virtual T operator[](int index);
};

