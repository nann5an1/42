#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdlib.h>
#include <time.h>


template <class T>
class Array{
    private:
        T* _array; //return the pointer to the array cannout use Array<T> because it is a template class(will be caught in a recursion)
        unsigned int _size;
    public:
        Array(); //construction with no param creates an empty array
        ~Array();
        Array(unsigned int n); //creates an array of n elements 
        Array(const Array<T>& other);
        Array& operator=(const Array<T>& other);
        T& operator[](unsigned int index);
        unsigned int size() const {return _size;}
};       

#include "Array.tpp"

#endif