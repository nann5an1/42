#include "Span.hpp"

Span::Span(): _maxSize(0) {}
Span::~Span() {}
Span::Span(unsigned int n): _maxSize(n){}
Span::Span(const Span &other): _maxSize(other._maxSize) {
    // Copy constructor logic if needed
}

Span &Span::operator=(const Span &other){

}

void Span::addNumber(unsigned int num){
    std::vector<unsigned int>spannedNum;

    spannedNum.push_back(num);

}