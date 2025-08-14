#include "Span.hpp"

int main(){
    srand(time(0));
    // std::vector<unsigned int>vec(5);
    Span sp = Span(5); //create a span of size 5
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    sp.addMultipleNumbers(sp.getVec());
    return 0;
}