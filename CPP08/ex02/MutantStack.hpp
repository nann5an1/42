#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

//mutantStack class need to have of stack's member functions and "iterators" feature
template <class T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack():std::stack<T>(){};
        ~MutantStack():std::stack<T>(){};
        MutantStack(const MutantStack<T> &other);
        MutantStack&<T> operator=(const MutantStack<T> &other);
        typedef typename std::stack<T>::std::iterator iter; //iterator applied on the stack
        iter begin();
        iter end();
};


#include "MutantStack.tpp"

#endif