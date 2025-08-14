#include "Span.hpp"

Span::Span(): _maxSize(0) {}
Span::~Span() {}
Span::Span(unsigned int n): _maxSize(n){
    std::cout << "n size : " << n << std::endl;
    this->vec.reserve(n);
    std::cout << "this vector capacity : " << this->vec.capacity() << std::endl;
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
// void Span::addMultipleNumbers(T &container){
//     typename T::iterator it;
//     unsigned int size = container.size();
//     if(size <= this->_maxSize){
//         for(it = container.begin(); it!= container.end(); ++it){
//             this->addNumber(*it);
//             std::cout << "Added number: " << *it << std::endl;
//         }
//     }

// }

void Span:: shortestSpan(){ //if no numbers or only one num, throw exception
    std::set<unsigned int> setSpan(this->vec.begin(), this->vec.end()); //the set will now contain the sorted numbers
    // std::set<unsigned int>::iterator  it = setSpan.begin();
    //  for(unsigned int i = 0; i < vec.size(); i++){
    //     std::cout << i << " : " << vec[i] << std::endl;
    // }

    std::next(setSpan.begin());
    //print the set which is sorted
    for(std::set<unsigned int>::iterator  it = setSpan.begin(); it != setSpan.end() ;it++){
        std::cout << *it << std::endl;
    }
}

// unsigned int Span:: longestSpan(){

// }