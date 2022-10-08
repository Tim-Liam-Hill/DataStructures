#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <string>
//#include "Iterator.h"

using namespace std;

/**
 * This is the base class that defines all of the basic operations that each
 * datastructure must support. It also serves as the 'Abstract List' class
 * for the iterator design pattern.
 * To avoid dangling pointers, items added to a data structure will be passed 
 * in by value as opposed to by reference.
 * 
 * NBNB: removing equality and assignment operators for now but it could be cool to add them later? But 
 * That could lead to misunderstanding: how should we define if a stack and linked list are equal? What about trees? 
 * For now I am going to implement those functions at class level.
 */
template <class T> 
class DataStructure {

    public:
        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;

        //Const reference to increase processing time and avoid functional side effects
        virtual bool contains(const T &) = 0;

        //Will compare element by element to determine equality.
        //Assumes objects of type T have corresponding == overloaded
        //virtual bool operator == (const DataStructure &) = 0;

        //Will create deep copies of DataStructures
        //virtual bool operator = (const DataStructure &) = 0;

        //virtual Iterator<T> createIterator() = 0;

        virtual void add(T) = 0;
        virtual void remove(T) = 0;
        virtual void removeAll() = 0;
};

#endif