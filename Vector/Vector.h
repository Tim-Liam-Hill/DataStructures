#ifndef VECTOR_H
#define VECTOR_H

#include "../DataStructure.h"

using namespace std; 
/**
 * Ahh, a good old vector. Was the first data structure I really 
 * began to love before I knew what data structures really were.
 * 
 * Gonna try have a small optimization to spice things up.
 * 
 * @tparam T 
 */
template<typename T> 
class Vector : public DataStructure<T>
{
    protected:
        
        int size;       //total size of inner array 'arr'
        int sizeUsed;   //amount of 'arr' actually being used 
        T * arr;
        /**
         * The thought behind this variable is as follows:
         * The main drawback behind vectors is that anytime you want 
         * to extend the range of the vector, you need to declare a new array of greater size
         * and copy over all the elements of the old array. This takes time.
         * 
         * This variable will allow the user to set by how much we increase the size of the
         * vector each time its current limit is reached. Thus, if we have a pattern where
         * we know batches will all be added to the vector at once instead of single insertions,
         * this in theory should allow the insertion to go faster (at the cost of an extra 
         * 4 bytes of storage for this integer and some extra lines of code).)
         * 
         * TODO: decide if this should be const. 
         */
        const int VOLUME_FULL_INCREMENT;

        void expandInnerArray();

    public: 

        Vector(int increment = 1);
        //Different to what follows, this sets initial size for inner array without having to specify an array
        Vector(int size, int increment = 1);
        Vector(T *, int size, int increment = 1);
        Vector(const Vector<T> &);
        virtual ~Vector();

        virtual int getSizeUsed();      //Trying to us every explicit function names here to avoid ambiguity when this function would be used
        virtual int getSizeAvailable();
        virtual bool isEmpty();
        virtual bool contains(const T &);
        virtual void add(T);
        virtual void remove(T);
        virtual void removeAll();

        virtual void shrinkToFit();

        virtual void insertAt(T, int);
        virtual void deleteAt(int);

        virtual T & operator [](int);
        virtual bool operator ==(const Vector &);
        virtual bool operator =(const Vector &);

        virtual string toString();
};

#endif 