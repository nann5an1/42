#include "Span.hpp"

Span::Span(): _maxSize(0) {}
Span::~Span() {}
Span::Span(unsigned int n): _maxSize(n), _longestSpanVal(0) {
    // std::cout << "n size : " << n << std::endl;
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
    vec.push_back(num);
    // std::cout << "Span size: " << this->vec.size() << std::endl;
}

// template <typename T>
// void Span::addMultipleNumbers(T &container){ //container's size is aldy reserved from the constructor
//     typename T::iterator it;
//     unsigned int capacity = container.capacity();
//         for(it = container.begin(); it!= container.end(); ++it){

//             vec.push_back(rand() % 5000);
//             // this->addNumber(*it);
//             std::cout << "Added number: " << *it << std::endl;
//         }
// }

unsigned int Span:: shortestSpan(){ //if no numbers or only one num, throw exception
    std::set<unsigned int>newSet;
    std::set<unsigned int> setSpan(this->vec.begin(), this->vec.end()); //the set will now contain the sorted numbers
    this->_longestSpanVal = *(setSpan.rbegin()) - *(setSpan.begin());

    //print the set which is sorted
    for(std::set<unsigned int>::iterator  it = setSpan.begin(); it != setSpan.end() ;it++){
       std::set<unsigned int>::iterator nextIt = it; // copy current position
       std::cout << *it << " ";
        ++nextIt; // move to next element

    if (nextIt != setSpan.end()) // make sure there's a next element
        newSet.insert(*nextIt - *it);
    }
    std::cout << std::endl;
    // std::cout << *(newSet.begin()) << std::endl;
    return (*newSet.begin());
}

unsigned int Span:: longestSpan(){
    return this->_longestSpanVal;
}

std::vector<unsigned int> Span::getVec(){
    return this->vec;

}