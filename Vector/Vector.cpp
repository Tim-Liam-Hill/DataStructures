#include "Vector.h"

template<typename T> 
Vector<T>::Vector(int increment){
    VOLUME_FULL_INCREMENT = increment;
    size = 0; 
    sizeUsed = 0;
    arr = NULL;
}

template<typename T> 
Vector<T>::Vector(int size, int increment){

    if(size <= 0)
        throw std::out_of_range("Cannot initialze vector with size " + to_string(size));

    this->size = size;
    this->sizeUsed = size;
    this->VOLUME_FULL_INCREMENT = increment;
    arr = new T[size];
}

template<typename T> 
Vector<T>::Vector(T * a, int size, int increment){
    if(size <= 0)
        throw std::out_of_range("Cannot initialze vector with size " + to_string(size));

    this->size = size; 
    this->sizeUsed = size;
    this->VOLUME_FULL_INCREMENT = increment;
    arr = new T[size];
    for(int i=0;i<size; ++i){
        arr[i] = a[i]; //TODO: check if this makes a deep copy if a[i] is a pointer. 
    }
}

template<typename T> 
Vector<T>::Vector(const Vector<T> & vec){
    this->size = vec.size;
    this->sizeUsed = vec.size;
    this->VOLUME_FULL_INCREMENT = vec.VOLUME_FULL_INCREMENT;
    arr = new T[size];

    for(int i=0;i<size; ++i){
        arr[i] = vec[i]; //TODO: check if this makes a deep copy if vec[i] is a pointer. 
    }
}

template<typename T> 
Vector<T>::~Vector(){
    delete arr; //Will this memory leak if T holds pointers?? 
}

/**
 * Doesn't update the 'sizeUsed' field
 * 
 * @tparam T 
 */
template<typename T> 
void Vector<T>::expandInnerArray(){

    int newSize = size + VOLUME_FULL_INCREMENT;
    T * newArr = new T[newSize];
    for(int i=0; i<size; ++i){
        newArr[i] = arr[i];
    }
    size= newSize;
    arr = newArr;
    delete arr; 
}

template<typename T> 
int Vector<T>::getSizeUsed(){
    return sizeUsed;
}

template<typename T> 
int Vector<T>::getSizeAvailable(){
    return size; 
}

template<typename T> 
bool Vector<T>::isEmpty(){
    return sizeUsed == 0;
}

template<typename T> 
bool Vector<T>::contains(const T & val){

    for(int i=0;i<sizeUsed; ++i){
        if(arr[i] == val)
            return true;
    }

    return false;
}

/**
 * Functions as an append function, similarly to in linkedlists
 * 
 * @tparam T 
 */
template<typename T> 
void Vector<T>::add(T val){

    if(sizeUsed == size){
        this->expandInnerArray();
    }
    arr[sizeUsed] = val;
    sizeUsed ++;
}

/**
 * Removes first occurance of val, if any 
 * 
 * @tparam T 
 */
template<typename T> 
void Vector<T>::remove(T val){ 

    for(int i=0; i<sizeUsed; ++i){
        if(arr[i] == val){
            deleteAt(i);   
            return; 
        }
    }
}

/**
 * For all practical porpoises, doesn't really overwrite the values inside the array. Serves more as marking 
 * existing values in the array as deleted/
 * 
 * @tparam T 
 */
template<typename T> 
void  Vector<T>::removeAll(){
    sizeUsed = 0;
}

template<typename T> 
void Vector<T>::shrinkToFit(){
    if(sizeUsed > 0 && sizeUsed < size){

    }
    T * newArr = new T[sizeUsed];
    size = sizeUsed;
    for(int i=0;i<size; ++i)
        newArr[i] = arr[i];
    delete arr;
    arr = newArr;

}

/**
 * Cases to cover:
 * 1. Index is in range of current sizeUsed
 * 2. Index is in range of current size 
 * 3. Index is out of range of size 
 * 
 * 
 * @tparam T 
 * @param val 
 * @param index 
 */
template<typename T> 
void Vector<T>::insertAt(T val, int index){

}

template<typename T> 
void Vector<T>::deleteAt(int){

}

template<typename T> 
T & Vector<T>::operator [](int){
    return NULL;
}

template<typename T> 
bool Vector<T>::operator ==(const Vector &){
    return true;
}

template<typename T> 
bool Vector<T>::operator =(const Vector &){
    return true; 
}

template<typename T> 
string Vector<T>::toString(){

    return "";
}