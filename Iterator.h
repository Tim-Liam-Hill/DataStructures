#ifndef ITERATOR_H
#define ITERATOR_H

/**
 * The interface class for Iterators of each datastructure
 * Other base iterators may declare further functionality but
 * they all at a minimum need to include the following functions.
 * @tparam T 
 */
template <class T>
class Iterator {

    public:
        virtual void reset() =0;
        virtual bool isDone() = 0;

        /**
         * This function will only return an objects value as opposed to 
         * a reference, since an Iterator should not expose the underling data to being changed.
         * TODO: consider returning a const object
         * @return T 
         */
        virtual T current() const =0;
        virtual void goNext() = 0;
};

#endif 