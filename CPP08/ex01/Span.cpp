#include "Span.hpp"

Span::Span(): _maxSize(0) {}
Span::~Span() {}
Span::Span(unsigned int n): _maxSize(n), _longestSpanVal(0) {
    this->vec.reserve(n);
    // std::cout << "this vector capacity : " << this->vec.capacity() << std::endl;
}

Span::Span(const Span &other): _maxSize(other._maxSize) {
     (void)other;
}

Span &Span::operator=(const Span &other){
    (void)other;
    return *this;
}

void Span::addNumber(unsigned int num){
    if(vec.size() > _maxSize)
        throw std::overflow_error("Span is already full");
    vec.push_back(num);
    // std::cout << "Span size: " << this->vec.size() << std::endl;
}

unsigned int Span:: shortestSpan(){ //if no numbers or only one num, throw exception
    std::set<unsigned int>newSet;
    if(vec.size() < 2)
        throw std::overflow_error("Span has less than 2 numbers");
    std::set<unsigned int> setSpan(this->vec.begin(), this->vec.end()); //the set will now contain the sorted numbers
    // vec.clear();
    this->_longestSpanVal = *(setSpan.rbegin()) - *(setSpan.begin());

    //print the set which is sorted
    for(std::set<unsigned int>::iterator  it = setSpan.begin(); it != setSpan.end() ;it++){
       std::set<unsigned int>::iterator nextIt = it; // copy current position
    //    std::cout << *it << " ";
        ++nextIt; // move to next element
    if (nextIt != setSpan.end()) // make sure there's a next element
        newSet.insert(*nextIt - *it);
    }
    // std::cout << std::endl;
    return (*newSet.begin());
}

unsigned int Span:: longestSpan(){
    if(vec.size() < 2)
        throw std::overflow_error("Span has less than 2 numbers");
    return this->_longestSpanVal;
}
