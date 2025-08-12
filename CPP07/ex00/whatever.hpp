#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>


template <typename T>
T min(T a, T b){
    return ((a < b) ? a : b);
}

template <typename T>
T max(T a, T b){
    return ((a > b ? a : b));
}

template <typename T>
void swap(T a, T b){
    T c = a;
    a = b;
    b = c;
    std::cout << "a b4 update " << a << " b b4 update " << b << std::endl;
}

#endif