#include "../DataStructure.h"
using namespace std; 

/**
 * Generic Singly Linked List
 * 
 * Will only consist of a head pointer. If a tail pointer was included, this
 * would increase the complexity of implementation for little benefit since
 * it seems like it would only help in the single case when the tail is retrieved O(1).
 * If you need fast lookup from end of list makes more since to have a doubly linked list.
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
         * TODO: Is this tight coupling optimal? Should there be code reuse between this linked list and 
         * other linked lists??
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

        Node * head;

        public:
            //Constructor and Destructors
            LinkedList();
            LinkedList(const & LinkedList);
            ~LinkedList();

            virtual int size();
            virtual void isEmpty();
            virtual bool contains(const T &);
            virtual bool operator == (const DataStructure &);
            virtual bool operator = (const DataStructure &);
            virtual Iterator createIterator();

            //Functions that alter the underlying list
            virtual void add(T);
            virtual void remove(T);
            virtual void insertAt(T, int);
            virtual void deleteAt(int);
            //Will be used later for sorting algorithm
            virtual void swap(int, int);

            //Access Functions
            virtual T head();
            virtual T operator[](int index);
};

