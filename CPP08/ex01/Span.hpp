#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <set>
#include <iterator> //next

//Span class that can strore a max of N integers


class Span{
    private:
        unsigned int _maxSize; //will be the only param passed to the 
        std::vector<unsigned int> vec;
    public:
        void addNumber(unsigned int num); //to add a single number to the Span class
        void shortestSpan();  //if no numbers or only one num, throw exception
        // unsigned int longestSpan();
        // template <typename T>
        // void addMultipleNumbers(T &container); //add multiple numbers to the span in a single call
        
        Span();
        Span(unsigned int n);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
        std::vector<unsigned int> getVec();
};

#endif