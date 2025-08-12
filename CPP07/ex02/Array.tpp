#include "Array.hpp"

template <class T>
Array<T>::Array(): _array(NULL), _size(0){}

template <class T>
Array<T>::Array(unsigned int n): _array(new T[n]()), _size(n){}

template <class T>
Array<T>::~Array(){ delete[] _array;}

template <class T>
Array<T>::Array(const Array<T>& other): _array(NULL), _size(other._size){ //cannot copy just by initializing, need to do deep copy
    if(_size > 0){
        this->_array = new T[_size];
        for(unsigned i = 0; i < _size; i++)
            this->_array[i] = other._array[i];
    }
}

template <class T>
Array<T>& Array<T>:: operator=(const Array<T>& other){
    if(this != &other){
        delete [] _array;
        this->array = new T[other._size];
       if(other._size > 0){
        for(unsigned i = 0; i < other._size; i++)
            this->_array[i] = other.array[i];
        }
        else
            this->_array = NULL;      
    }
    return *this;
}

template <class T>
T& Array<T>::operator[](unsigned int index){ //subscript operator to access elements
    if(index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}