#include "Span.hpp"

int main(){
    // std::vector<unsigned int>vec(5);
    Span sp = Span(5); //create a span of size 5
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.shortestSpan();
    // std::cout << sp.longestSpan() << std::endl;
   
    return 0;
}