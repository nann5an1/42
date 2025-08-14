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
    std::set<unsigned int>spannedNum;
    spannedNum.insert(num);
}

template <typename T>
void Span::addMultipleNumbers(T &container){
    typename T::iterator it;
    for(it = container.begin(); it!= container.end(); ++it){
        this->addNumber(*it);
    }
}

unsigned int Span:: shortestSpan(){ //if no numbers or only one num, throw exception

}

unsigned int Span:: longestSpan(){

}