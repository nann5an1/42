#ifndef ITER_HPP
#define ITER_HPP
#include <typeinfo>
#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; ++i)
        std::cout << func(array[i]) << " ";
    std::cout << std::endl;
}

template <typename T>
T increment(const T& x) { //modify this function template to test on the const and non-const for the third parameter
    return x + 1;
}


#endif
