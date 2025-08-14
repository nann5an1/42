#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

//Span class that can strore a max of N integers
class Span{
    private:
        unsigned int _maxSize; //will be the only param passed to the constructor
    public:
        void addNumber(unsigned int num); //to add a single number to the Span class
        unsigned int shortestSpan();  //if no numbers or only one num, throw exception
        unsigned int longestSpan();

        Span();
        Span(unsigned int n);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
};

#endif