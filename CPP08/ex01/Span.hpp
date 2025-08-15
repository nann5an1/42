#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <set>
#include <iterator> //next
#include <ctime>
#include <cstdlib>
#include <iterator>
#define MAX_NUM 10000

//Span class that can strore a max of N integers

class Span{
    private:
        unsigned int _maxSize; //will be the only param passed to the 
        std::vector<unsigned int> vec;
        unsigned int _longestSpanVal;
    public:
        void addNumber(unsigned int num); //to add a single number to the Span class
        unsigned int shortestSpan();  //if no numbers or only one num, throw exception
        unsigned int longestSpan();
        template <typename Iter>
        void addMultipleNumbers(Iter begin, Iter end){ //container's size is aldy reserved from the constructor
            if(begin != end && std::distance(begin, end)  > _maxSize && vec.size() == _maxSize){
                throw std::overflow_error("Span is full");
            }
            for(Iter it = begin; it!= end; ++it)
                this->addNumber(*it);
        }
        
        Span();
        Span(unsigned int n);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
};

#endif