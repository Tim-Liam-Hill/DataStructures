#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <string>
#include "Iterator.h"

using namespace std;

/**
 * This is the base class that defines all of the basic operations that each
 * datastructure must support. It also serves as the 'Abstract List' class
 * for the iterator design pattern
 */
template <typename T> 
class DataStructure {

    public:
        virtual int size() = 0;
        virtual void isEmpty() = 0;

        //Const reference to increase processing time and avoid functional side effects
        virtual bool contains(const T &) = 0;

        //Will compare element by element to determine equality.
        //Assumes objects of type T have corresponding == overloaded
        virtual bool operator == (const DataStructure &) = 0;

        //Will create deep copies of DataStructures
        virtual bool operator = (const DataStructure &) = 0;

        virtual Iterator createIterator() = 0;
};

#endif